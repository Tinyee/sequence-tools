#ifndef __TOOLS_PRIME_H__
#define __TOOLS_PRIME_H__

#include <vector>
#include <unordered_map>
#include "power.h"

namespace seqtools {

// add primes in 2~n to vector "primes"
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

// ord_n(q)
int multiplicative_order(int q, int n) {
    int i = 1;
    for (; i < q; ++i) {
        if (fast_power(n, i, q) == 1) {
            break;
        }
    }
    return i;
}

void prime_factorization(int n, std::unordered_map<int, int>& factors) {
    for (int i = 2; n >= i; ++i) {
        while (n % i == 0) {
            ++factors[i];
            n /= i;
        }
    }
}

// 辗转相除法判断是否互质
bool is_prime(int a, int b)
{
    int temp;
    bool flag = true;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    if (a == 1)
        flag = true;
    else
        flag = false;
    return flag;
}

// phi(n)
int euler(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (1 == is_prime(i, n))
            sum++;
    }
    return sum;
}

} // namespace

#endif