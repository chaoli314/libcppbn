//
// Created by chao li on 9/16/16.
//

#ifndef LIBCPPBN_VARSET_H
#define LIBCPPBN_VARSET_H

#include "sorted_set.h"

#include <ostream>
#include "var.h"
#include <sorted_set.h>
#include "typedefs.h"

using cppbn::Bigint

class VarSet : public sorted_set<var> {
public:

    VarSet() : sorted_set<var>() {}
    VarSet(const var &v) : sorted_set<var>(v) {}


    Bigint nrStates() const {
        Bigint states = 1;
        for (VarSet::const_iterator n = begin(); n != end(); n++)
            states *= (Bigint) n->states();
        return states;
    }


    friend std::ostream &operator<<(std::ostream &os, const VarSet &vars) {
        os << "{";
        for (auto iter = vars.cbegin(); iter != vars.cend(); ++iter)
            os << (iter != vars.cbegin() ? ", " : "") << *iter;
        os << "}";
        return (os);
    }

    operator std::string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
};


#endif //LIBCPPBN_VARSET_H
