//
// Created by chao li on 9/16/16.
//

#ifndef LIBCPPBN_BN_VAR_H
#define LIBCPPBN_BN_VAR_H

//#include <iostream>
#include <sstream>
#include <string>

#include "typedefs.h"

class var {
private:
    size_t var_index_;
    size_t card_;

public:
    /// @name Constructor
    //@{
    var() = delete;

    var& operator=(const var&) = default;

    var(const var&) = default;

    ~var() = default;

    var(size_t index, size_t card) : var_index_(index), card_(card) {}
    //@}

    /// @name Getters and Setters
    //@{
    size_t getIndex() const { return var_index_; }

    size_t getCard() const { return card_; }
    //@}

    /// @name Comparison operators
    //@{
    bool operator==(const var& rhs) const { return var_index_ == rhs.var_index_; }

    bool operator!=(const var& rhs) const { return !(rhs == *this); }

    bool operator<(const var& rhs) const { return var_index_ < rhs.var_index_; }

    bool operator>(const var& rhs) const { return rhs < *this; }

    bool operator<=(const var& rhs) const { return !(rhs < *this); }

    bool operator>=(const var& rhs) const { return !(*this < rhs); }
    //@}

    /// @name std::cout & toString
    //@{
    friend std::ostream& operator<<(std::ostream& os, const var& n) {
        return os << "x" << n.var_index_;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
    //@}

};

#endif // LIBCPPBN_BN_VAR_H