//
// Created by chao li on 9/9/16.
//

#ifndef LIBCPPBN_ADTREE_H
#define LIBCPPBN_ADTREE_H

#include <memory>
#include <vector>
#include "contingency_table.h"
using namespace std;

class ADTree {

public:
    friend class contingency_table;

private:
    using Nums = std::vector<size_t> ;

    struct ADNode {
#ifdef REPORT_STATS
        static int count;
#endif
    };

/*    struct Node {
        vector<shared_ptr<Node>> children;
        Data data;
    };*/




#ifdef REPORT_STATS
    int ADNode::count = 0;
#endif


    struct VaryNode {
#ifdef REPORT_STATS
        static int count;
#endif

    };

#ifdef REPORT_STATS
    int VaryNode::count = 0;
#endif


public:


private:

    std::unique_ptr<ADNode> root_;

    size_t R_min_;
};


#endif //LIBCPPBN_ADTREE_H
