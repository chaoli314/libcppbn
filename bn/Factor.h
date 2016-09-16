//
// Created by chao li on 9/11/16.
//

#ifndef LIBCPPBN_FACTOR_H
#define LIBCPPBN_FACTOR_H

#include <vector>
#include "typedefs.h"
#include "sorted_set.h"
#include "var.h"

using cppbn::real;


class Factor {

private:

    //sorted_set<var> Scope_;

    // cards;

    std::vector<real> _p;
public:

    // TFactor ( real p = 1 ) : _vs(), _p(1,p) {}

    ///    Return the size of this table.
    //size_t 	getSize () const {return 0;}

};


#endif //LIBCPPBN_FACTOR_H
