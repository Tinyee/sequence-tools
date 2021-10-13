#ifndef __LEGENDRE_H__
#define __LEGENDRE_H__

#include <iostream>
#include <string>
#include "sequence.h"
#include "tools/power.h"
#include "tools/prime.h"

namespace seqtools {

class Legendre : public Sequence {
public:
    Legendre(int prime);
    int prime() const { return prime_; }
    
private:
    int prime_;
};

Legendre::Legendre(int prime) : prime_(prime), Sequence(prime) {
    int power = (prime - 1) / 2;
    sequence_ += '0';
    for (int i = 1; i < prime_; ++i) {
        long long tmp = seqtools::fast_power(i, power, prime_);
        sequence_ += (tmp == 1) ? '1' : '0';
    }
}

} // namespace

#endif