all:
	gcc -std=c11 -O2 exp_static_a_b.c -o exp_static_a_b
	gcc -std=c11 -O2 exp_static_a_b.c -S -o exp_static_a_b.s
	./exp_static_a_b
	gcc -std=c11 -O2 exp_static_a_volatile_b.c -o exp_static_a_volatile_b
	gcc -std=c11 -O2 exp_static_a_volatile_b.c -S -o exp_static_a_volatile_b.s
	./exp_static_a_volatile_b
	gcc -std=c11 -O2 exp_lapack.c -L/usr/lib -llapack -lblas -lf2c -o exp_lapack
	./exp_lapack
clean:
	rm exp_static_a_b
	rm exp_static_a_b.s
	rm exp_static_a_volatile_b
	rm exp_static_a_volatile_b.s
	rm exp_lapack
