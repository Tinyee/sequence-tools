#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__

#include <string>
#include <iostream>

namespace seqtools {

class Sequence {
public:
    Sequence() = default;
    const std::string& get_sequence_() const { return sequence_; }
    std::string get_sequence_() { return sequence_; }

    const int length() const { return sequence_.size(); }

    int get_period() const { return period_; }

    const char operator[](int n) const { return sequence_[n % period_]; }
    char operator[](int n) { return sequence_[n % period_]; }

    friend std::ostream& operator<<(std::ostream& os, const Sequence& seq) { os << seq.sequence_; }

protected:
    int period_;
    std::string sequence_;
};

}

#endif