all:
	g++ validity.cpp -std=c++14 -O3 -o validity
	g++ exp1.cpp -std=c++14 -O3 -o exp1
	g++ exp2.cpp -std=c++14 -O3 -o exp2
	g++ exp3.cpp -std=c++14 -O3 -o exp3
	g++ exp3_poisson.cpp -std=c++14 -O3 -o exp3_poisson
debug:
	g++ validity.cpp -std=c++14 -O0 -g -o validity
measurements:
	./validity
	./exp1
	./exp2
	./exp3
	./exp3_poisson
clean:
	rm validity
	rm exp1
	rm exp2
	rm exp3

