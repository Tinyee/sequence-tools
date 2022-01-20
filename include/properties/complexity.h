#ifndef __PROPERTIES_COMPLEXITY_H__
#define __PROPERTIES_COMPLEXITY_H__
#include "sequence/sequence.h"

namespace seqtools {

// linear complexity from NIST
int BM(const Sequence& seq)
{
    const Sequence epsilon = seq + seq;
    int i, j, d, L, m, N_, M = epsilon.length();
    bool* T = NULL, * P = NULL, * B_ = NULL, * C = NULL;
    if (((B_ = (bool*)calloc(M, sizeof(bool))) == NULL) ||
        ((C = (bool*)calloc(M, sizeof(bool))) == NULL) ||
        ((P = (bool*)calloc(M, sizeof(bool))) == NULL) ||
        ((T = (bool*)calloc(M, sizeof(bool))) == NULL)) {
        printf("Insufficient Memory for Work Space:: Linear Complexity Test\n");
        if (B_ != NULL)
            free(B_);
        if (C != NULL)
            free(C);
        if (P != NULL)
            free(P);
        if (T != NULL)
            free(T);
        return -1;
    }
    for (i = 0; i < M; i++) {
        B_[i] = 0;
        C[i] = 0;
        T[i] = 0;
        P[i] = 0;
    }
    L = 0;
    m = -1;
    d = 0;
    C[0] = 1;
    B_[0] = 1;
    N_ = 0;
    while (N_ < M) {
        d = epsilon[N_] - '0';
        for (i = 1; i <= L; i++) {
            d ^= C[i] * (epsilon[N_ - i] - '0');
        }
        if (d == 1) {
            for (i = 0; i < M; i++) {
                T[i] = C[i];
                P[i] = 0;
            }
            for (j = 0; j < M; j++) {
                if (B_[j] == 1) {
                    P[j + N_ - m] = 1;
                }
            }
            for (i = 0; i < M; i++) {
                C[i] ^= P[i];
            }
            if (L <= N_ / 2) {
                L = N_ + 1 - L;
                m = N_;
                for (i = 0; i < M; i++)
                    B_[i] = T[i];
            }
        }
        N_++;
    }
    free(B_);
    free(P);
    free(C);
    free(T);
    return L;
}

} // namespace

#endif