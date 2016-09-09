//
// Created by chao li on 9/9/16.
//

#ifndef LIBCPPBN_BAYESIANNETWORK_H
#define LIBCPPBN_BAYESIANNETWORK_H

#include <vector>
#include <map>
#include <string>

#include "Node.h"

using namespace std;

class Node;

class BayesianNetwork {
public:
    Node * getNodeByName ( const std::string& nodeName) ;
    std::string 	getFileName () const;
    size_t size(){ return Nodes_.size();}
private:

    std::string file_name_;

    vector<Node> Nodes_;
    std::map<std::string, Node*> name_to_node_;

};

std::string BayesianNetwork::getFileName() const {
    return file_name_;
}
Node * BayesianNetwork::getNodeByName ( const std::string& nodeName){
    return name_to_node_[nodeName];
}


#endif //LIBCPPBN_BAYESIANNETWORK_H
