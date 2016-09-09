//
// Created by chao li on 9/9/16.
//

#ifndef LIBCPPBN_ADTREE_H
#define LIBCPPBN_ADTREE_H

#include <memory>
#include <vector>
#include "contingency_table.h"
using namespace std;
class ad_tree {

public:
    friend class contingency_table;

private:
    using Nums = std::vector<size_t> ;

    struct AD_node {
#if !defined(NDEBUG)
        static int count;
#endif
    };

#if !defined(NDEBUG)
    int AD_node::count = 0;
#endif


    struct Vary_node {
#if !defined(NDEBUG)
        static int count;
#endif

    };

#if !defined(NDEBUG)
    int Vary_node::count = 0;
#endif


public:


private:
    std::unique_ptr<AD_node> root_;
    size_t Rmin;
};


#endif //LIBCPPBN_ADTREE_H
