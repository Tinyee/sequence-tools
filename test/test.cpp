#include "sequence/msequence.h"
#include "polynomial/primitive.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    for (auto poly : seqtools::Poly::getPrimitive(5)) {
        seqtools::MSequence seq(poly, 5);
        std::cout << seq << endl;
    }
    return 0;
}