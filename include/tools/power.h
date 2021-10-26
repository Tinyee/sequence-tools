#ifndef __TOOLS_POWER_H__
#define __TOOLS_POWER_H__

namespace seqtools {

// fast power to compute x^y % mod
long long fast_power(long long x, long long y, long long mod) {
    long long result = 1;
    while (y > 0) {
        if (y & 1) {
            result = result * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return result;
}

// fast power to compute x^y
long long fast_power(long long x, long long y) {
    long long result = 1;
    while (y > 0) {
        if (y & 1) {
            result = result * x;
        }
        x = x * x;
        y >>= 1;
    }
    return result;
}

} // namespace

#endif