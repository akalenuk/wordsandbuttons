all: static
.PHONY: static
static:
	gcc -std=c11 -march=native -O2 exp_volatile_a_b.c -o exp_volatile_a_b
	gcc -std=c11 -march=native -O2 exp_volatile_a_b.c -S -o exp_volatile_a_b.s
	./exp_volatile_a_b	
clean:	
	rm exp_volatile_a_b
	rm exp_volatile_a_b.s	

