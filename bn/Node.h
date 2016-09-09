//
// Created by chao li on 9/9/16.
//

#ifndef LIBCPPBN_NODE_H
#define LIBCPPBN_NODE_H

#include <string>
#include <map>
#include <vector>

#include "BayesianNetwork.h"

using namespace std;

class BayesianNetwork;

class Node {


public:

    size_t getStateIndex (const std::string &label) const;
    std::string getStateLabel (size_t index) const;
    size_t 	getNumberOfStates () const{ return label_list_.size(); }
private:

    std::string name_;
    vector<Node*> parents_;

    std::map<std::string, size_t> label_to_index_;
    std::vector<std::string> label_list_;

    BayesianNetwork* network_;



    //std::vector<std::vector<double> > parameters;
};


#endif //LIBCPPBN_NODE_H
