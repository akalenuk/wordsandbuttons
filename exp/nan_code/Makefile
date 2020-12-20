all:
	clang++ -O2 -std=c++17 -march=native nan_as_error_code.cpp -o nan_as_error_code
	./nan_as_error_code
	rm ./nan_as_error_code
	clang++ -O2 -std=c++17 -march=native nan_as_error_code_cast.cpp -o nan_as_error_code_cast
	./nan_as_error_code_cast
	rm ./nan_as_error_code_cast
	clang++ -O2 -std=c++17 -march=native measurements.cpp -o measurements
	./measurements
	rm ./measurements
