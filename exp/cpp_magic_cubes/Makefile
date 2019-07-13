all: gcc run clang run o3 run clean
.PHONY: gcc
gcc:
	g++ -O2 -std=c++11 empty_run.cpp -o empty_run
	g++ -O2 -std=c++11 naive.cpp -o naive
	g++ -O2 -std=c++11 naive_reversed.cpp -o naive_reversed
	g++ -O2 -std=c++11 naive_less_code.cpp -o naive_less_code
	g++ -O2 -std=c++11 numbers.cpp -o numbers
	g++ -O2 -std=c++11 numbers_5_heuristic.cpp -o numbers_5_heuristic
	g++ -O2 -std=c++11 numbers_oddity_heuristic.cpp -o numbers_oddity_heuristic
	g++ -O2 -std=c++11 numbers_permutation_shifts.cpp -o numbers_permutation_shifts
	g++ -O2 -std=c++11 words.cpp -o words
	g++ -O2 -std=c++11 words_in_set.cpp -o words_in_set
	g++ -O2 -std=c++11 words_in_unordered_set.cpp -o words_in_unordered_set
	g++ -O2 -std=c++11 words_oddity_heuristic.cpp -o words_oddity_heuristic
	g++ -O2 -std=c++11 64bits.cpp -o 64bits
	g++ -O2 -std=c++11 64bits_in_set.cpp -o 64bits_in_set
	g++ -O2 -std=c++11 64bits_in_unordered_set.cpp -o 64bits_in_unordered_set
.PHONY: s
s:
	g++ -O2 -S -std=c++11 empty_run.cpp -o empty_run.s
	g++ -O2 -S -std=c++11 naive.cpp -o naive.s
	g++ -O2 -S -std=c++11 naive_reversed.cpp -o naive_reversed.s
	g++ -O2 -S -std=c++11 naive_less_code.cpp -o naive_less_code.s
	g++ -O2 -S -std=c++11 numbers.cpp -o numbers.s
	g++ -O2 -S -std=c++11 numbers_5_heuristic.cpp -o numbers_5_heuristic.s
	g++ -O2 -S -std=c++11 numbers_oddity_heuristic.cpp -o numbers_oddity_heuristic.s
	g++ -O2 -S -std=c++11 numbers_permutation_shifts.cpp -o numbers_permutation_shifts.s
	g++ -O2 -S -std=c++11 words.cpp -o words.s
	g++ -O2 -S -std=c++11 words_in_set.cpp -o words_in_set.s
	g++ -O2 -S -std=c++11 words_in_unordered_set.cpp -o words_in_unordered_set.s
	g++ -O2 -S -std=c++11 words_oddity_heuristic.cpp -o words_oddity_heuristic.s
	g++ -O2 -S -std=c++11 64bits.cpp -o 64bits.s
	g++ -O2 -S -std=c++11 64bits_in_set.cpp -o 64bits_in_set.s
	g++ -O2 -S -std=c++11 64bits_in_unordered_set.cpp -o 64bits_in_unordered_set.s
.PHONY: clang
clang:
	clang++ -O2 -std=c++11 empty_run.cpp -o empty_run
	clang++ -O2 -std=c++11 naive.cpp -o naive
	clang++ -O2 -std=c++11 naive_reversed.cpp -o naive_reversed
	clang++ -O2 -std=c++11 naive_less_code.cpp -o naive_less_code
	clang++ -O2 -std=c++11 numbers.cpp -o numbers
	clang++ -O2 -std=c++11 numbers_5_heuristic.cpp -o numbers_5_heuristic
	clang++ -O2 -std=c++11 numbers_oddity_heuristic.cpp -o numbers_oddity_heuristic
	clang++ -O2 -std=c++11 numbers_permutation_shifts.cpp -o numbers_permutation_shifts
	clang++ -O2 -std=c++11 words.cpp -o words
	clang++ -O2 -std=c++11 words_in_set.cpp -o words_in_set
	clang++ -O2 -std=c++11 words_in_unordered_set.cpp -o words_in_unordered_set
	clang++ -O2 -std=c++11 words_oddity_heuristic.cpp -o words_oddity_heuristic
	clang++ -O2 -std=c++11 64bits.cpp -o 64bits
	clang++ -O2 -std=c++11 64bits_in_set.cpp -o 64bits_in_set
	clang++ -O2 -std=c++11 64bits_in_unordered_set.cpp -o 64bits_in_unordered_set
.PHONY: o3
o3:
	g++ -O3 -std=c++11 empty_run.cpp -o empty_run
	g++ -O3 -std=c++11 naive.cpp -o naive
	g++ -O3 -std=c++11 naive_reversed.cpp -o naive_reversed
	g++ -O3 -std=c++11 naive_less_code.cpp -o naive_less_code
	g++ -O3 -std=c++11 numbers.cpp -o numbers
	g++ -O3 -std=c++11 numbers_5_heuristic.cpp -o numbers_5_heuristic
	g++ -O3 -std=c++11 numbers_oddity_heuristic.cpp -o numbers_oddity_heuristic
	g++ -O3 -std=c++11 numbers_permutation_shifts.cpp -o numbers_permutation_shifts
	g++ -O3 -std=c++11 words.cpp -o words
	g++ -O3 -std=c++11 words_in_set.cpp -o words_in_set
	g++ -O3 -std=c++11 words_in_unordered_set.cpp -o words_in_unordered_set
	g++ -O3 -std=c++11 words_oddity_heuristic.cpp -o words_oddity_heuristic
	g++ -O3 -std=c++11 64bits.cpp -o 64bits
	g++ -O3 -std=c++11 64bits_in_set.cpp -o 64bits_in_set
	g++ -O3 -std=c++11 64bits_in_unordered_set.cpp -o 64bits_in_unordered_set
.PHONY: run
run:	
	./empty_run
	./naive
	./naive_reversed
	./naive_less_code
	./numbers
	./numbers_5_heuristic
	./numbers_oddity_heuristic
	./numbers_permutation_shifts
	./words
	./words_in_set
	./words_in_unordered_set
	./words_oddity_heuristic
	./64bits
	./64bits_in_set
	./64bits_in_unordered_set
.PHONY: clean
clean:	
	rm ./empty_run	
	rm ./naive
	rm ./naive_reversed
	rm ./naive_less_code
	rm ./numbers
	rm ./numbers_5_heuristic
	rm ./numbers_oddity_heuristic
	rm ./numbers_permutation_shifts
	rm ./words
	rm ./words_in_set
	rm ./words_in_unordered_set
	rm ./words_oddity_heuristic
	rm ./64bits
	rm ./64bits_in_set
	rm ./64bits_in_unordered_set

