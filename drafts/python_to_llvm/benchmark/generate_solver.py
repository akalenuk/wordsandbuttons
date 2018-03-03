# this is the head and tail for one specific function
head = """; ModuleID = 'solve_5.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu" 

; Function Attrs: nounwind uwtable
define void @solve_5(double* %a, double* %b, double* %x) #0 { 
"""

tail = """}

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"} 
"""

# this is basically the whole LLVM layer (well, excluding the head and tail that are very specific)
g_stack_counter = 0

def array_to_stack(a_name, i):
    global g_stack_counter
    load = "%" + str(g_stack_counter+1) + " = alloca double*, align 8\n"
    load += "store double* %" + a_name + ", double** %" + str(g_stack_counter+1) +", align 8\n"
    load += "%" + str(g_stack_counter+2) + " = load double*, double** %" + str(g_stack_counter+1) + ", align 8\n"
    load += "%" + str(g_stack_counter+3) + " = getelementptr inbounds double, double* %"+ str(g_stack_counter+2) +", i64 " + str(i) + "\n"
    load += "%" + str(g_stack_counter+4) + " = load double, double* %" + str(g_stack_counter+4) + ", align 8\n;
    g_stack_counter += 4    
    return load;

def stack_to_array(a_name, i):
    store = "%" + str(g_stack_counter+1) + " = alloca double*, align 8\n"
    store += "store double* %" + a_name + ", double** %" + str(g_stack_counter+1) +", align 8\n"
    store += "%" + str(g_stack_counter+2) + " = load double*, double** %" + str(g_stack_counter+1) + ", align 8\n"
    store += "%" + str(g_stack_counter+3) + " = getelementptr inbounds double, double* %"+ str(g_stack_counter+2) +", i64 " + str(i) + "\n"
    store += "store double %" + str(g_stack_counter) + ", double* %" + str(g_stack_counter+3) + ", align 8\n"
    g_stack_counter += 3
    return store;

def compute(a, operator, b):
    operation = a + b;
    operation += "%" + str(g_stack_counter+1) + " = f" + operator + " double %" + str(g_stack_counter-1) + ", %" + str(g_stack_counter) + "\n";
    g_stack_counter += 1
    return operation;

# this generates n-solver in pseudo-code
def generate_solver(a_name, b_name, x_name, n_value):
    generated = ""       
   
    def a(i, j, n):
        if n==n_value: 
            return array_to_stack(a_name, i * n + j)
        return compute( compute(a(i,j,n+1), 'mul', a(n,n,n+1)), 'sub', compute(a(i,n,n+1), 'mul', a(n,j,n+1)) )

    def b(i, n):
        if n==n_value: 
            return array_to_stack(b_name, i)
        return compute( compute(a(n,n,n+1), 'mul', b(i,n+1)), 'sub', compute(a(i,n,n+1), 'mul', b(n,n+1)) )

    def x(i):
        d = b(i,i+1)
        for j in xrange(i): 
            d = compute(d, 'sub', compute(a(i,j,i+1), 'mul', array_to_stack(x_name, j) ) )
        return compute(d, 'div', a(i,i,i+1))

    for k in xrange(n_value):
        generated += x(k) + stack_to_array(x_name, k)

    return generated
    
if __name__ == '__main__':
    print head + generate_solver('a', 'b', 'x', 5) + tail


