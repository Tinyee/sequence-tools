#ifndef __SEQUENCE_FCSR_H__
#define __SEQUENCE_FCSR_H__

#include <gmpxx.h>
#include "sequence.h"
#include "tools/prime.h"

namespace seqtools {

// the exponential representation of FCSR sequence
class FCSRSequence : public Sequence {
private:
    int A_;
    int connection_integer_;

public:
    FCSRSequence(int A, int connection_integer);

    int A() { return A_; }
    int connection_integer() { return connection_integer_; }
};

FCSRSequence::FCSRSequence(int A, int connection_integer) : A_(A), connection_integer_(connection_integer)
{
    int inverse = (connection_integer_ + 1) / 2;
    int per = seqtools::multiplicative_order(connection_integer_, 2);
    period_ = per;
    mpz_class base = 1;
    for (int i = 0; i < per; ++i) {
        sequence_ += (((A_ * base % connection_integer_ % 2) == 1) ? '1' : '0');
        base *= inverse;
    }
}

}

#endif
