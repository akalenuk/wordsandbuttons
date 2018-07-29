all:
	g++ -O2 -std=c++11 empty_run.cpp -o empty_run
	./empty_run
	valgrind --tool=cachegrind ./empty_run 
	g++ -O2 -std=c++11 empty_run.cpp -S
	cat empty_run.s
	g++ -O2 -std=c++11 numbers.cpp -o numbers	
	./numbers
	valgrind --tool=cachegrind ./numbers
	g++ -O2 -std=c++11 numbers.cpp -S
	cat numbers.s	
	g++ -O2 -std=c++11 numbers_const.cpp -o numbers_const	
	./numbers_const
	valgrind --tool=cachegrind ./numbers_const
	g++ -O2 -std=c++11 numbers_const.cpp -S
	cat numbers_const.s	
	g++ -O2 -std=c++11 numbers_permutation_shifts.cpp -o numbers_permutation_shifts		
	./numbers_permutation_shifts
	valgrind --tool=cachegrind ./numbers_permutation_shifts
	g++ -O2 -std=c++11 numbers_permutation_shifts.cpp -S
	cat numbers_permutation_shifts.s    
	g++ -O2 -std=c++11 64bits.cpp -o 64bits		
	./64bits
	valgrind --tool=cachegrind ./64bits
	g++ -O2 -std=c++11 64bits.cpp -S
	cat 64bits.s	
	g++ -O2 -std=c++11 64bits_local.cpp -o 64bits_local	
	./64bits_local
	valgrind --tool=cachegrind ./64bits_local
	g++ -O2 -std=c++11 64bits_local.cpp -S
	cat 64bits_local.s	
	g++ -O2 -std=c++11 64bits_smart_index.cpp -o 64bits_smart_index	
	./64bits_smart_index
	valgrind --tool=cachegrind ./64bits_smart_index
	g++ -O2 -std=c++11 64bits_smart_index.cpp -S
	cat 64bits_smart_index.s	
	g++ -O2 -std=c++11 64bits_binary_search.cpp -o 64bits_binary_search	
	./64bits_binary_search
	valgrind --tool=cachegrind ./64bits_binary_search
	g++ -O2 -std=c++11 64bits_binary_search.cpp -S
	cat 64bits_binary_search.s	
	g++ -O2 -std=c++11 words_smart_memcmp.cpp -o words_smart_memcmp
	./words_smart_memcmp
	valgrind --tool=cachegrind ./words_smart_memcmp
	g++ -O2 -std=c++11 words_smart_memcmp.cpp -S
	cat words_smart_memcmp.s
	g++ -O2 -std=c++11 words_smart_index_and_memcmp.cpp -o words_smart_index_and_memcmp
	./words_smart_index_and_memcmp
	valgrind --tool=cachegrind ./words_smart_index_and_memcmp
	g++ -O2 -std=c++11 words_smart_index_and_memcmp.cpp -S
	cat words_smart_index_and_memcmp.s
	rm ./empty_run	
	rm ./numbers
	rm ./numbers_const
	rm ./numbers_permutation_shifts
	rm ./64bits
	rm ./64bits_local
	rm ./64bits_smart_index
	rm ./64bits_binary_search
	rm ./words_smart_memcmp
	rm ./words_smart_index_and_memcmp
	rm ./*.s
