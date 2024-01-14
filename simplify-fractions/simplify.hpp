//#define TABLE

#ifdef TABLE
#include "prime_table.hpp"
#endif

struct frac_t
{
	uint32_t a = 0;
	uint32_t b = 0;
};

inline bool divides(uint32_t a, uint32_t n)
{
	return !(a % n);
}

frac_t simplify(frac_t p)
{
	uint32_t temp = 0;
	if(p.b and (p.a > p.b)) { temp = p.a / p.b; p.a = (p.a % p.b); }

#if defined(__GCC__) || defined(__clang__)
	int x = (__builtin_ctz(p.a) <= __builtin_ctz(p.b))? __builtin_ctz(p.a): __builtin_ctz(p.b);
	p.a >>= x;
	p.b >>= x;
#else
	while(divides(p.a, 2) and divides(p.b, 2))
	{
		p.a /= 2;
		p.b /= 2;
	}
#endif

#ifdef TABLE
	for(uint32_t i = 0; i < prime_table.size(); i++)
	{
		while(divides(p.a, prime_table[i]) and divides(p.b, prime_table[i]))
		{
			p.a /= prime_table[i];
			p.b /= prime_table[i];
		}
	}
	for(uint32_t i = prime_table[prime_table.size() - 1]; i <= p.a; i++)
	{
		while(divides(p.a, i) and divides(p.b, i))
		{
			p.a /= i;
			p.b /= i;
		}
	}
#else
	for(uint32_t i = 3; i <= p.a; i+=2)
	{
		while(divides(p.a, i) and divides(p.b, i))
		{
			p.a /= i;
			p.b /= i;
		}
	}
#endif

	p.a += temp * p.b;

	return p;
}