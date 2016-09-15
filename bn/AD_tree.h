//
// Created by chao li on 9/9/16.
//

#ifndef LIBCPPBN_ADTREE_H
#define LIBCPPBN_ADTREE_H

#include <memory>
#include <vector>
#include "contingency_table.h"
using namespace std;
class AD_tree {

public:
    friend class contingency_table;

private:
    using Nums = std::vector<size_t> ;

    struct AD_node {
#ifdef REPORT_STATS
        static int count;
#endif
    };

#ifdef REPORT_STATS
    int AD_node::count = 0;
#endif


    struct Vary_node {
#ifdef REPORT_STATS
        static int count;
#endif

    };

#ifdef REPORT_STATS
    int Vary_node::count = 0;
#endif


public:


private:
    std::unique_ptr<AD_node> root_;
    size_t R_min_;
};


#endif //LIBCPPBN_ADTREE_H
