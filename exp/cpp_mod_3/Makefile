all:
	clang++ -O2 -std=c++14 -march=native simple_mod_3.cpp -o simple_mod_3
	./simple_mod_3
	rm ./simple_mod_3
	clang++ -Os -std=c++14 -march=native simple_mod_3.cpp -o simple_mod_3_s
	./simple_mod_3_s
	rm ./simple_mod_3_s
	clang++ -O2 -std=c++14 -march=native lookup.cpp -o lookup
	./lookup
	rm ./lookup
	clang++ -O2 -std=c++14 -march=native trick_1.cpp -o trick_1
	./trick_1
	rm ./trick_1
	clang++ -O2 -std=c++14 -march=native trick_2.cpp -o trick_2
	./trick_2
	rm ./trick_2
	clang++ -O2 -std=c++14 -march=native trick_3.cpp -o trick_3
	./trick_3
	rm ./trick_3
	clang++ -O2 -std=c++14 -march=native trick_4.cpp -o trick_4
	./trick_4
	rm ./trick_4
	clang++ -O2 -std=c++14 -march=native trick_5.cpp -o trick_5
	./trick_5
	rm ./trick_5
s:
	clang++ -O2 -std=c++14 -march=native -S simple_mod_3.cpp -o simple_mod_3.s
	clang++ -Os -std=c++14 -march=native -S simple_mod_3.cpp -o simple_mod_3_s.s
	clang++ -O2 -std=c++14 -march=native -S lookup.cpp -o lookup.s
	clang++ -O2 -std=c++14 -march=native -S trick_1.cpp -o trick_1.s
	clang++ -O2 -std=c++14 -march=native -S trick_2.cpp -o trick_2.s
	clang++ -O2 -std=c++14 -march=native -S trick_3.cpp -o trick_3.s
	clang++ -O2 -std=c++14 -march=native -S trick_4.cpp -o trick_4.s
	clang++ -O2 -std=c++14 -march=native -S trick_5.cpp -o trick_5.s
clean:
	rm ./simple_mod_3.s
	rm ./simple_mod_3_s.s
	rm ./lookup.s
	rm ./trick_1.s
	rm ./trick_2.s
	rm ./trick_3.s
	rm ./trick_4.s
	rm ./trick_5.s

