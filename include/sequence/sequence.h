#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__

#include <string>
#include <iostream>

namespace seqtools {

class Sequence {
public:
    Sequence(int per = 0) : period_(per), sequence_() {}
    Sequence(const std::string& str) : period_(str.length()), sequence_(str) {}

    int length() const { return sequence_.size(); }
    int period() const { return period_; }
    const std::string& sequence() const { return sequence_; }
    const char* sequence_char() const { return sequence.c_str(); }

    const char operator[](int n) const { return sequence_[n % period_]; }
    void change_sequence(int n, char c) { sequence_[n] = c; }

    friend std::ostream& operator<<(std::ostream& os, const Sequence& seq) { os << seq.sequence_; }
    friend std::istream& operator>>(std::istream& is, const Sequence& seq) { is >> seq.sequence_; }

protected:
    int period_;
    std::string sequence_;
};

}

#endif