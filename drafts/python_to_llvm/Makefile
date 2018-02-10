all: generate_llvm generate_s generate_elf
.PHONY: generate_llvm
generate_llvm:
	clang test.c -S -emit-llvm -o test.bc
.PHONY: generate_s
generate_s:
	llc -O2 test.bc -o test.s
.PHONY: generate_elf
generate_elf:
	as test.s -o test.out
	ld -o test test.out
.PHONY: clean
clean:
	rm test.s test.out test.bc test		
