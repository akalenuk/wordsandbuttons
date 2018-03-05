all: generate_llvm generate_s generate_elf test
.PHONY: generate_llvm
generate_llvm:
#	clang solve_5.c -S -emit-llvm -o solve_5.bc
	python generate_solver.py > solve_5.bc
	clang benchmark.c -S -emit-llvm -o benchmark.bc
.PHONY: generate_s
generate_s:
	llc -O2 solve_5.bc -o solve_5.s
	llc -O2 benchmark.bc -o benchmark.s
.PHONY: generate_elf
generate_elf:
	as solve_5.s -o solve_5.o	
	as benchmark.s -o benchmark.o
	clang -o benchmark benchmark.o solve_5.o
.PHONY: test
test:
	./benchmark
	@echo "expected: -800714.025732, -695243.384448, 593914.994902, 1321725.609087, 565756.196571"
.PHONY: clean
clean:
	rm solve_5.s solve_5.o solve_5.bc
	rm benchmark.s benchmark.o benchmark.bc benchmark		
