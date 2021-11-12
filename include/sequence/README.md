# how to use the `Sequence`

```c++
#include "sequence/sequence.h"
#include "sequence/legendre.h"
#include "sequence/fcsr.h"
#include <iostream>

int main()
{
    seqtools::Sequence seq0;
    std::cin >> seq0;
    seqtools::Sequence seq1("000111101011001");
    seqtools::Sequence seq2(seq1);
    seqtools::Legendre seq3(4);
    seqtools::FCSRSequence seq4(1, 17);
    std::cout << seq0 << endl;
    return 0;
}
```
