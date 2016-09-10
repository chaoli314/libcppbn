//
// Created by chao li on 9/10/16.
//

#ifndef LIBCPPBN_VAR_H
#define LIBCPPBN_VAR_H

#include <string>
#include <iostream>

class var {

private:
    size_t node_index_;
    size_t card_;
public:
    var(size_t nodeIndex, size_t number_of_states) : node_index_(nodeIndex), card_(number_of_states) {}

    size_t getCard() const { return card_; }

    friend std::ostream &operator<<(std::ostream &os, const var &dt) { return (os << "var" << dt.node_index_); }

    /// @name relational operators
    //@{
    bool operator<(const var &rhs) const {
        return node_index_ < rhs.node_index_;
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

    /// @name equality operators
    //@{
    bool operator==(const var &rhs) const {
        return node_index_ == rhs.node_index_;
    }

    bool operator!=(const var &rhs) const {
        return !(rhs == *this);
    }
    //@}


};

#endif //LIBCPPBN_VAR_H