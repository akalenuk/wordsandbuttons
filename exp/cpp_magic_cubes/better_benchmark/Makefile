all: gcc run1 clean
.PHONY: gcc
gcc:
	g++ -O2 -std=c++14 empty_run.cpp -o empty_run
.PHONY: s
s:
	g++ -O2 -S -std=c++14 empty_run.cpp -o empty_run.s
.PHONY: clang
clang:
	clang++ -O2 -std=c++14 empty_run.cpp -o empty_run
.PHONY: o3
o3:
	g++ -O3 -std=c++14 empty_run.cpp -o empty_run
.PHONY: run1
run1:
	./empty_run
.PHONY: run2
run2:
	./empty_run
.PHONY: run3
run3:
	./empty_run
.PHONY: clean
clean:	
	rm ./empty_run	

