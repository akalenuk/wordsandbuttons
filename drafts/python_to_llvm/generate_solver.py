# this generates n-solver in pseudo-code

def array_to_stack(a_name, i):
    return 'get_from ' + a_name + ' element ' + str(i) + '\n';

def stack_to_array(a_name, i):
    return 'put_to ' + a_name + ' element ' + str(i) + '\n';


def mul_in_stack():
    return 'mul_last_two put_as stack-1 decrement stack\n';

def add_in_stack():
    return 'add_last_two put_as stack-1 decrement stack\n';

def div_in_stack():
    return 'div_last_two put_as stack-1 decrement stack\n';

def sub_in_stack():
    return 'sub_last_two put_as stack-1 decrement stack\n';


def generate_solver(a_name, b_name, x_name, n_value):
    generated = ""       
   
    def a(i, j, n):
        if n==n_value: 
            return array_to_stack(a_name, i * n + j)
#        return a(i,j,n+1)*a(n,n,n+1)-a(i,n,n+1)*a(n,j,n+1)
        return a(i,j,n+1) + a(n,n,n+1) + mul_in_stack() + a(i,n,n+1) + a(n,j,n+1) + mul_in_stack() + sub_in_stack()

    def b(i, n):
        if n==n_value: 
            return array_to_stack(b_name, i)
#        return a(n,n,n+1)*b(i,n+1)-a(i,n,n+1)*b(n,n+1)
        return a(n,n,n+1) + b(i,n+1) + mul_in_stack() + a(i,n,n+1) + b(n,n+1) + mul_in_stack() + sub_in_stack()

    def x(i):
        d = b(i,i+1)
        for j in xrange(i): 
            d += a(i,j,i+1) + array_to_stack(x_name, j) + mul_in_stack() + sub_in_stack()
        return d + a(i,i,i+1) + div_in_stack()

    for k in xrange(n_value):
        generated += x(k) + stack_to_array(x_name, k)

    return generated
    
if __name__ == '__main__':
    print generate_solver('a', 'b', 'x', 5)


