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
    sorted_set<var> Scope_;
    std::vector<real> p_;
public:

    /// \name Constructors and destructors
    //@{

    /// Constructs factor depending on variables in \a vars with all values set to \a p
    Factor( const sorted_set<var>& vars, std::vector<real> p ) : Scope_(vars), p_(p) {}

    //@}

};


#endif //LIBCPPBN_FACTOR_H
