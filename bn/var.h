//
// Created by chao li on 9/10/16.
//

#ifndef LIBCPPBN_VAR_H
#define LIBCPPBN_VAR_H

#include <string>
#include <iostream>
#include <sstream>

class var {

private:
    size_t node_index_;
    size_t card_;
public:
    var(size_t nodeIndex, size_t number_of_states) : node_index_(nodeIndex), card_(number_of_states) {}

    size_t getCard() const { return card_; }

    operator std::string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }

    friend std::ostream &operator<<(std::ostream &os, const var &x) { return (os << "var" << x.node_index_); }

    /// @name Relational operators
    //@{
    bool operator==(const var &rhs) const { return node_index_ == rhs.node_index_; }

    bool operator<(const var &rhs) const { return node_index_ < rhs.node_index_; }

    bool operator>(const var &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const var &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const var &rhs) const {
        return !(*this < rhs);
    }

    bool operator!=(const var &rhs) const {
        return !(rhs == *this);
    }
    //@}


};

#endif //LIBCPPBN_VAR_H