#include <random>
#include <iostream>

#include "simplify.hpp"

int main()
{
    std::random_device r;
    std::mt19937 gen(r());
    std::uniform_int_distribution<> d(0, (1<<16) - 1);

    for(int i = 0; i < 500000; i++)
    {
        uint32_t a = d(gen);
        uint32_t b = d(gen);
        frac_t p = simplify({a, b});
    }
    return 0;
}
