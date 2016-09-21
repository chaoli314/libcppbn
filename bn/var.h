//
// Created by chao li on 9/16/16.
//

#ifndef LIBCPPBN_VAR_H
#define LIBCPPBN_VAR_H

#include <iostream>
#include <sstream>

#include "typedefs.h"

class var {
private:
    size_t var_index_;
    size_t card_;
public:
    var(size_t varIndex, size_t card) : var_index_(varIndex), card_(card) {}

    //size_t getIndex() const { return var_index_; }
    /// Return the number of states of this node.
    size_t getCard() const { return card_; }

    /// @name Comparisons
    //@{
    bool operator==(const var &rhs) const {
        return var_index_ == rhs.var_index_;
    }

    bool operator!=(const var &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const var &rhs) const {
        return var_index_ < rhs.var_index_;
    }

    bool operator>(const var &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const var &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const var &rhs) const {
        return !(*this < rhs);
    }
    //@}

    /// @name std::cout & std::string
    //@{
    friend std::ostream &operator<<(std::ostream &os, const var &n) {
        return (os << "x" << n.var_index_);
    }

    operator std::string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
    //@}
};

/// get the number of joint assignments to vars
template <class range_of_vars>
cppbn::Bigint getNumberOfAssignment(const range_of_vars &vars) {
    cppbn::Bigint tableSize = 1;
    std::for_each(vars.cbegin(), vars.cend(), [&tableSize](const auto &v) { tableSize *= v.getCard(); } );
    return tableSize;
}
#endif //LIBCPPBN_VAR_H
