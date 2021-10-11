#ifndef __PRIME_H__
#define __PRIME_H__

#include <vector>

namespace seqtools {

// add primes in 2-n to vector "primes"
void prime_select(int n, std::vector<int>& primes)
{
    std::vector<int> not_prime(n + 1);
    for (int num = 2; num <= n; ++num) {
        if (not_prime[num] == 0) {
            primes.emplace_back(num);
        }
        for (int idx = 0; primes[idx] * num <= n; ++idx) {
            not_prime[primes[idx] * num] = 1;
            if (num % primes[idx] == 0) {
                break;
            }
        }
    }
}

} // namespace

#endif