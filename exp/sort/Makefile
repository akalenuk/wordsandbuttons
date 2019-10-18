all:
	g++ exp_0.cpp -std=c++14 -O2 -o exp_0
	g++ exp_1.cpp -std=c++14 -O2 -o exp_1
	g++ exp_2.cpp -std=c++14 -O2 -o exp_2
	g++ exp_3_triplet.cpp -std=c++14 -O2 -o exp_3
measurements:
	valgrind --tool=cachegrind ./exp_0
	valgrind --tool=cachegrind ./exp_1
	valgrind --tool=cachegrind ./exp_2
	valgrind --tool=cachegrind ./exp_3
clean:
	rm exp_0
	rm exp_1
	rm exp_2
	rm exp_3
triplets:
	g++ exp_3_triplet.cpp -std=c++14 -O2 -o exp_3
