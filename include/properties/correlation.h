#ifndef __CORRELATION_H__
#define __CORRELATION_H__

#include <gmpxx.h>
#include <numeric>
#include "sequence/sequence.h"

namespace seqtools {

mpz_class arithmetic_cross_correlation(const seqtools::Sequence& seq1, const seqtools::Sequence& seq2, int tau)
{
	int N = std::lcm(seq1.length(), seq2.length());
	mpz_class s2 = 0, s_tau2 = 0, power = 1;
	for (int i = 0; i < N; ++i) {
		s2 += (seq1[i] - '0') * power;
		s_tau2 += (seq2[(i + tau)] - '0') * power;
		power *= 2;
	}
	mpz_class result = abs(s2 - s_tau2);
	mpz_class n1 = 0;
	for (int i = 0; i < N && result > 0; ++i) {
		n1 += (result & 1);
		result >>= 1;
	}
	mpz_class n0 = N - n1;
	return (s2 >= s_tau2) ? n0 - n1 : n1 - n0;
}

mpz_class arithmetic_auto_correlation(const seqtools::Sequence& seq, int tau)
{
	return arithmetic_cross_correlation(seq, seq, tau);
}

int cross_correlation(const seqtools::Sequence& seq1, const seqtools::Sequence& seq2, int tau)
{
	int sum = 0;
	int N = std::lcm(seq1.length(), seq2.length());
	for (int i = 0; i < N; ++i) {
		sum += ((seq1[i] - '0' + seq2[i + tau] - '0') & 1) ? -1 : 1;
	}
	return sum;
}

int auto_correlation(const seqtools::Sequence& seq, int tau)
{
	return cross_correlation(seq, seq, tau);
}

} // namespace

#endif
