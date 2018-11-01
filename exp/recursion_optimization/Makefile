all:
	g++ -std=c++14 tco.cpp -O2 -S -o tco.s
	g++ -std=c++14 no_tco.cpp -O2 -S -o no_tco.s
	g++ -std=c++14 no_tco_instances_trick.cpp -O2 -S -o no_tco_instances_trick.s
	g++ -std=c++14 tco.cpp -O2 -o tco
	g++ -std=c++14 no_tco.cpp -O2 -o no_tco
	g++ -std=c++14 no_tco_instances_trick.cpp -O2 -o no_tco_instances_trick
measurements:
	valgrind --tool=cachegrind ./tco
	valgrind --tool=cachegrind ./no_tco
	valgrind --tool=cachegrind ./no_tco_instances_trick
	perf stat ./tco
	perf stat ./no_tco
	perf stat ./no_tco_instances_trick
clean:
	rm tco
	rm no_tco
	rm no_tco_instances_trick
	rm cachegrind.*
