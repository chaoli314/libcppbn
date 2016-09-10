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
/**  @name Lookup */
    //@{


    /// Find a node by name in this BayesianNetwork.
    Node* 	getNodeByName(const std::string &nodeName) const { return &index_to_nodes_[ name_to_index_[nodeName] ]; }
    /// Find a node by index in this BayesianNetwork.
    Node* 	getNodeByIndex(size_t nodeIndex) const { return &index_to_nodes_[nodeIndex]; }

    size_t          getNodeIndex(const std::string& nodeName) const {return name_to_index_[nodeName];}
    std::string 	getNodeName(size_t nodeIndex) const { return index_to_nodes_[nodeIndex].getName(); }
    //@}


    /**  @name Capacity */
    //@{
    size_t size() const{ return index_to_nodes_.size();}
    //@}


    std::string 	getFileName () const{    return file_name_; }



    void addNode(const std::string &nodeName);



private:

    std::string file_name_;

    vector<Node> index_to_nodes_;
    std::map<std::string, size_t> name_to_index_;
};


void BayesianNetwork::addNode(const std::string &nodeName) {


    if( name_to_index_.cend() != name_to_index_.find(nodeName) /* Only add new state */){

        size_t nodeIndex = name_to_index_.size();
        name_to_index_[nodeName] = nodeIndex;

        Node n{this, nodeName, nodeIndex};
        index_to_nodes_.push_back(n);
    }

}



#endif //LIBCPPBN_BAYESIANNETWORK_H