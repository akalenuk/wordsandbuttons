all:
	gcc -std=c11 -O2 loop.c -o loop
	gcc -std=c11 -O2 loop.c -S -o loop.s
	./loop
lapack:
	gcc -std=c11 -O2 dgesv_ex.c -L/usr/lib -llapack -lblas -lf2c -o dgesv_ex
clean:
	rm loop
	rm loop.s
