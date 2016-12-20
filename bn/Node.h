//
// Created by chao li on 9/9/16.
//

#ifndef LIBCPPBN_NODE_H
#define LIBCPPBN_NODE_H

#include <string>
#include <map>
#include <vector>

#include "BayesianNetwork.h"
#include "typedefs.h"

using namespace std;

class BayesianNetwork;

/// Brief description.
/** Detailed description.
 * \author chao li
 * */
class Node {


public:

/**  @name Lookup */
    //@{

    std::string getStateLabel(size_t stateIndex) const { return stateLabels_[stateIndex]; }

    size_t getStateIndex(const std::string& stateLabel) const { return stateLabel_to_stateIndex_.at(stateLabel); }


    std::string getName() const { return node_name_; }

    size_t getIndex() const { return node_index_; }

    size_t getCard() const { return stateLabels_.size(); }
    //@}

    /**  @name Modifiers */
    //@{

    ///   Add parent as a new parent of this node.
    /**    That is, add a directed link from parent to this node.    */
    void addParent(Node* parent) { parents_.push_back(parent); }

    void addState(const std::string& stateLabel);
    //@}

///@name constructor
//@{
    Node(BayesianNetwork* network,  ///< The BN possesses this Node
         const string& nodeName,
         const size_t& nodeIndex) :
            network_(network), node_name_(nodeName), node_index_(nodeIndex) {}
//@}
private:
    BayesianNetwork* network_; ///< owner
    std::string node_name_;  //!< The name of this node
    size_t      node_index_; ///< The index of this node

    std::vector<std::string>      stateLabels_;
    std::map<std::string, size_t> stateLabel_to_stateIndex_;

    vector<Node*> parents_;    //!< Parent nodes of *this node

    // std::vector<std::vector<cppbn::real>> data_;
    // std::vector<std::vector<double> > parameters;
};

void Node::addState(const std::string& stateLabel) {
    if (stateLabel_to_stateIndex_.cend() != stateLabel_to_stateIndex_.find(stateLabel)) {
        throw std::runtime_error("Duplicate state name: " + stateLabel + ".");
    }
    stateLabel_to_stateIndex_[stateLabel] = stateLabels_.size();
    stateLabels_.push_back(stateLabel);
}

#endif //LIBCPPBN_NODE_H
