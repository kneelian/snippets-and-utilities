#include <random>
#include <iostream>

#include "is_prime.hpp"

int main()
{
	std::random_device r;
	std::mt19937 gen(r());

	for(int i = 0; i < 100000; i++)
	{
		uint32_t a = r();
		std::cout << a << " is" << (is_prime(a)?" ":" not ") << "a prime" << std::endl;
	}
	return 0;
}