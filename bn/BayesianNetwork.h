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
    Node *getNodeByName(const std::string &nodeName) { return &nodes_[name_to_index_[nodeName]]; }

    /// Find a node by index in this BayesianNetwork.
    Node *getNodeByIndex(size_t nodeIndex) { return &nodes_[nodeIndex]; }

    size_t getNodeIndex(const std::string &nodeName) { return name_to_index_[nodeName]; }

    std::string getNodeName(size_t nodeIndex) const { return nodes_[nodeIndex].getName(); }
    //@}


    /**  @name Capacity */
    //@{
    size_t size() const { return nodes_.size(); }
    //@}

    Node *addNode(const std::string &nodeName);

    std::string getFileName() const { return file_name_; }

private:

    std::string file_name_;

    vector<Node> nodes_;
    std::map<std::string, size_t> name_to_index_;
};

Node *BayesianNetwork::addNode(const std::string &nodeName) {
    if (name_to_index_.cend() != name_to_index_.find(nodeName)) {
        /* The same nodeName has already existed */
        throw std::runtime_error("Same node name: " + nodeName + ".");
    }

    const size_t nodeIndex = name_to_index_.size();

    name_to_index_[nodeName] = nodeIndex;
    Node node{this, nodeName, nodeIndex /**bn, name, int_ID */};
    nodes_.push_back(node);

    return &nodes_[nodeIndex];
}

#endif //LIBCPPBN_BAYESIANNETWORK_H