all:
	g++ -std=c++14 tco.cpp -O2 -S -o tco.s
	g++ -std=c++14 no_tco.cpp -O2 -S -o no_tco.s
	g++ -std=c++14 no_tco_instances_trick_4.cpp -O2 -S -o no_tco_instances_trick_4.s
	g++ -std=c++14 tco.cpp -O2 -o tco
	g++ -std=c++14 no_tco.cpp -O2 -o no_tco
	g++ -std=c++14 no_tco_instances_trick_1.cpp -O2 -o no_tco_instances_trick_1
	g++ -std=c++14 no_tco_instances_trick_2.cpp -O2 -o no_tco_instances_trick_2
	g++ -std=c++14 no_tco_instances_trick_4.cpp -O2 -o no_tco_instances_trick_4
	g++ -std=c++14 no_tco_instances_trick_8.cpp -O2 -o no_tco_instances_trick_8
	g++ -std=c++14 no_tco_instances_trick_16.cpp -O2 -o no_tco_instances_trick_16
	g++ -std=c++14 no_tco_instances_trick_32.cpp -O2 -o no_tco_instances_trick_32
measurements:
	valgrind --tool=cachegrind ./tco
	valgrind --tool=cachegrind ./no_tco
	valgrind --tool=cachegrind ./no_tco_instances_trick_1
	valgrind --tool=cachegrind ./no_tco_instances_trick_2
	valgrind --tool=cachegrind ./no_tco_instances_trick_4
	valgrind --tool=cachegrind ./no_tco_instances_trick_8
	valgrind --tool=cachegrind ./no_tco_instances_trick_16
	valgrind --tool=cachegrind ./no_tco_instances_trick_32
clean:
	rm tco
	rm no_tco
	rm no_tco_instances_trick_1
	rm no_tco_instances_trick_2
	rm no_tco_instances_trick_4
	rm no_tco_instances_trick_8
	rm no_tco_instances_trick_16
	rm no_tco_instances_trick_32
	rm cachegrind.*
