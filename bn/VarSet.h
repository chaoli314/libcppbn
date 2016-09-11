//
// Created by chao li on 9/11/16.
//

#ifndef LIBCPPBN_VARSET_H
#define LIBCPPBN_VARSET_H

#include "sorted_set.h"
#include "var.h"
#include "typedefs.h"
#include <map>
class VarSet : public sorted_set<var> {
public:

    VarSet() = default;

    VarSet(const var &v) : sorted_set<var>(v) {}


    //  BigInt nrStates() const {



};

size_t calcLinearState(const VarSet &vs, const std::map<var, size_t> &state);

std::map<var, size_t> calcState(const VarSet &vs, size_t linearState);

#endif //LIBCPPBN_VARSET_H
