#ifndef __SEQUENCE_MSEQUENCE_H__
#define __SEQUENCE_MSEQUENCE_H__

#include "sequence.h"
#include "tools/power.h"
#include <vector>

namespace seqtools {

class MSequence : public Sequence {
public:
    MSequence(const std::vector<int>& poly, int n);
private:
    std::vector<int> primitive_polynomial_;
};

MSequence::MSequence(const std::vector<int>& poly, int n) : primitive_polynomial_(poly)
{
    uint32_t reg = 1;
    int length = fast_power(2, n) - 1;
    period_ = length;
    for (int i = 0; i < length; ++i) {
        uint32_t feedback = 0;
        for (auto p : primitive_polynomial_)
        {
            feedback ^= reg >> (p % n);
        }
        feedback &= 1;
        reg = reg >> 1;
        reg = ((~(0xffffffff << (n - 1))) & reg) | (feedback << (n - 1));
        sequence_ += '0' + (reg & 1);
    }
}

}

#endif