all: generate_llvm generate_s generate_elf
.PHONY: generate_llvm
generate_llvm:
	clang test.c -S -emit-llvm -o test.bc
.PHONY: generate_s
generate_s:
	llc -O2 test.bc -o test.s
.PHONY: generate_elf
generate_elf:
	as test.s -o test.o
	clang -o test test.o
.PHONY: test
test:
	./test
	echo $?
.PHONY: clean
clean:
	rm test.s test.o test.bc test		
