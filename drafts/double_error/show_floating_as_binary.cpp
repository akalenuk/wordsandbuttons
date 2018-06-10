#include <cmath>
#include <iostream>

std::string float_to_bin(float x)
{
	uint32_t bits = *reinterpret_cast<uint32_t*>(&x);
	std::string ones_and_zeros;
	// sign
	ones_and_zeros += bits >> 31 ? '1' : '0';
	ones_and_zeros += ' ';
	// exponent
	for(auto i = 1u; i < 1 + 8; ++i)
		ones_and_zeros += (bits >> (31 - i)) & 0x0001 ? '1' : '0';
	ones_and_zeros += ' ';
	// significant bits
	
	for(auto i = 1u + 8; i < 1 + 8 + 23; ++i)
		ones_and_zeros += (bits >> (31 - i)) & 0x0001 ? '1' : '0';
	ones_and_zeros += ' ';
	
	return ones_and_zeros;
}

int main()
{
	auto present = [](float x)
	{ 
		std::cout << x << "\t - " << float_to_bin(x) << std::endl;
	};
	present(0.);
	present(-0.);
	present(1.);
	present(-1.);
	std::cout << std::endl;

	present(1.);
	present(2.);
	present(3.);
	present(4.);
	present(5.);
	present(6.);
	present(7.);
	present(8.);
	std::cout << std::endl;

	present(1.5);
	present(2.5);
	present(3.5);
	present(4.5);
	present(5.5);
	present(6.5);
	present(7.5);
	present(8.5);
	std::cout << std::endl;

	present(1.25);
	present(2.25);
	present(3.25);
	present(4.25);
	present(5.25);
	present(6.25);
	present(7.25);
	present(8.25);
	std::cout << std::endl;
	
	present(15.);
	present(255. / 16.);
	present(255. / 16. - 15.);

	present(1./0.);
	present(-1./0.);
	present(1./0. * 0.);
	present(0./0.);
	present(std::sqrt(-1.));
}
