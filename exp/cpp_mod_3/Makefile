all:
	clang++ -O2 -std=c++14 -march=native simple_mod_3.cpp -o simple_mod_3
	./simple_mod_3
	rm ./simple_mod_3
	clang++ -O2 -std=c++14 -march=native lookup.cpp -o lookup
	./lookup
	rm ./lookup
s:
	clang++ -O2 -std=c++14 -march=native -S simple_mod_3.cpp -o simple_mod_3.s
	clang++ -O2 -std=c++14 -march=native -S lookup.cpp -o lookup.s
clean:
	rm ./simple_mod_3.s
	rm ./lookup.s
