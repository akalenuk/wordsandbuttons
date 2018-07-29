all: static runtime lapack
.PHONY: static
static:
	gcc -std=c11 -O2 exp_static_a_b.c -o exp_static_a_b
	gcc -std=c11 -O2 exp_static_a_b.c -S -o exp_static_a_b.s
	./exp_static_a_b
	gcc -std=c11 -O2 exp_static_a_volatile_b.c -o exp_static_a_volatile_b
	gcc -std=c11 -O2 exp_static_a_volatile_b.c -S -o exp_static_a_volatile_b.s
	./exp_static_a_volatile_b
	gcc -std=c11 -O2 exp_volatile_a_static_b.c -o exp_volatile_a_static_b
	gcc -std=c11 -O2 exp_volatile_a_static_b.c -S -o exp_volatile_a_static_b.s
	./exp_volatile_a_static_b
	gcc -std=c11 -O2 exp_volatile_a_b.c -o exp_volatile_a_b
	gcc -std=c11 -O2 exp_volatile_a_b.c -S -o exp_volatile_a_b.s
	./exp_volatile_a_b	
	gcc -std=c11 -O2 exp_triangular_matrix.c -o exp_triangular_matrix
	gcc -std=c11 -O2 exp_triangular_matrix.c -S -o exp_triangular_matrix.s
	./exp_triangular_matrix
.PHONY: runtime
runtime:	
	gcc -std=c11 -O2 exp_runtime.c -o exp_runtime
	gcc -std=c11 -O2 exp_runtime.c -S -o exp_runtime.s
	./exp_runtime			
.PHONY: lapack
lapack:
	gcc -std=c11 -O2 exp_lapack.c -L/usr/lib -llapack -lblas -lf2c -o exp_lapack
	./exp_lapack
clean:
	rm exp_static_a_b
	rm exp_static_a_b.s
	rm exp_static_a_volatile_b
	rm exp_static_a_volatile_b.s
	rm exp_volatile_a_static_b
	rm exp_volatile_a_static_b.s	
	rm exp_volatile_a_b
	rm exp_volatile_a_b.s	
	rm exp_triangular_matrix
	rm exp_triangular_matrix.s
	rm exp_runtime
	rm exp_runtime.s
	rm exp_lapack
