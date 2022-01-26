#include "sequence/msequence.h"
#include "polynomial/primitive.h"
#include "properties/correlation.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main()
{
    for (size_t degree = 5; degree < 10; ++degree) {
        std::vector<std::vector<int>> polys = seqtools::Poly::getPrimitive(degree);
        std::set<mpz_class> occurs;
        std::cout << "n = " << degree << std::endl;
        for (auto poly : polys) {
            seqtools::MSequence seq(poly, degree);
            for (int t = 1; t < seq.length(); ++t) {
                mpz_class tmp = seqtools::arithmetic_auto_correlation(seq, t);
                occurs.emplace(tmp);
            }
        }
        for (auto& elem : occurs) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
