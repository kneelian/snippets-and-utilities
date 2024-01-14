# simplify-fractions

This folder contains a header that contains a fraction simplification routine in `simplify.hpp`, and example usage in `main.cpp`. It's fairly simple. There's a precomputed table of the first one thousand primes in the header `prime_table.hpp`, and you can enable its use by uncommenting the `#define TABLE` macro at the start of `simplify.hpp`; you can also limit the range to only 8-bit primes by uncommenting the `#define THOUSAND` macro in the table header.

This can have a varying effect on your performance, but will probably result in a *slowdown*, probably because on a modern machine it's simply cheaper to calculate these values than to wait for heap access. It is included as an example of a different sort of approach. Not the neatest code, but I still have use for it.
