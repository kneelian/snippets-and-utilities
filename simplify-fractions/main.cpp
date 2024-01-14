#include <random>
#include <iostream>

#include "simplify.hpp"

int main()
{
	std::random_device r;
	std::mt19937 gen(r());

	for(int i = 0; i < 500000; i++)
	{
		uint32_t a = r() & (1 << 16)-1;
		uint32_t b = r() & (1 << 16)-1;
		//std::cout << a << "/" << b << " --> ";
		frac_t p = simplify({a, b});
		//std::cout << p.a << "/" << p.b << std::endl;
	}
	return 0;
}