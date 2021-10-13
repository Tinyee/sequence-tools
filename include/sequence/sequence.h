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
    const char* sequence_char() const { return sequence_.c_str(); }

    Sequence operator^(const Sequence& rhs);
    Sequence& operator^=(const Sequence& rhs);

    const char operator[](int n) const { return sequence_[n % period_]; }
    void change_sequence(int n, char c) { sequence_[n] = c; }

    friend std::ostream& operator<<(std::ostream& os, const Sequence& seq) { os << seq.sequence_; }
    friend std::istream& operator>>(std::istream& is, Sequence& seq) { is >> seq.sequence_; }

protected:
    int period_;
    std::string sequence_;
};

Sequence Sequence::operator^(const Sequence& rhs)
{
    Sequence tmp(*this);
    for (int i = 0; i < sequence_.size(); ++i) {
        tmp.sequence_[i] = '0' + ((tmp.sequence_[i] - '0') ^ (rhs.sequence_[i] - '0'));
    }
    return tmp;
}

Sequence& Sequence::operator^=(const Sequence& rhs)
{
    for (int i = 0; i < sequence_.size(); ++i) {
        sequence_[i] = '0' + ((sequence_[i] - '0') ^ (rhs.sequence_[i] - '0'));
    }
    return *this;
}

}

#endif