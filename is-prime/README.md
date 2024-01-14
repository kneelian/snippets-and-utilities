# is-prime

A simple prime-checker procedure in `is_prime.hpp` and sample usage in `main.cpp`. It checks numbers up to `sqrt(n) + 1`, since no two prime factors of `n` can both be larger than `sqrt(n)`. Replacing the check with `i*i < n` does not lead to performance speed-ups, presumably because `sqrt(n) + 1` is calculated only once and no repeat calculations are needed for future comparisons; runtimes of both variants are identical on my device using all optimisations from `-O0` to `-O3` on several compilers. Easily rewritten in case a target doesn't have access to `sqrt()`.
