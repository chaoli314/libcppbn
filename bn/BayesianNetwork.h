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
    /** @return Pointer to the Node with the specified nodeName.     */
    Node* 	getNodeByName(const std::string &nodeName) const { return name_to_node_[nodeName]; }
    //@}

    std::string 	getFileName () const;

    /**  @name Capacity */
    //@{
    size_t size() const{ return Nodes_.size();}
    //@}

private:

    std::string file_name_;

    vector<Node> Nodes_;
    std::map<std::string, Node*> name_to_node_;
};

std::string BayesianNetwork::getFileName() const {
    return file_name_;
}



#endif //LIBCPPBN_BAYESIANNETWORK_H
