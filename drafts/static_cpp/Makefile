all:
	g++ -O2 -std=c++14 -march=native exp_static_a_b.cpp -o exp_static_a_b
	g++ -O2 -std=c++14 -march=native exp_static_a_b.cpp -S -o exp_static_a_b.s
	g++ -O2 -std=c++14 -march=native exp_volatile_a_b.cpp -o exp_volatile_a_b
	g++ -O2 -std=c++14 -march=native exp_volatile_a_b.cpp -S -o exp_volatile_a_b.s
	ls -l *.s 
clean:
	rm exp_static_a_b
	rm exp_static_a_b.s
	rm exp_volatile_a_b
	rm exp_volatile_a_b.s
