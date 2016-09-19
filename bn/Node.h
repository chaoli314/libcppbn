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
    size_t getStateIndex(const std::string &stateLabel) { return stateLabel_to_stateIndex_[stateLabel]; }

    std::string getStateLabel(size_t stateIndex) const { return stateLabels_[stateIndex]; }

    std::string getName() const { return node_name_; }

    size_t getIndex() const { return node_index_; }
    //@}

    /**  @name Capacity */
    //@{
    size_t getNumberOfStates() const { return stateLabels_.size(); }
    //@}

    /**  @name Modifiers */
    //@{
    ///   Add parent as a new parent of this node.
    /**    That is, add a directed link from parent to this node.     */
    void addParent(Node *parent) { parents_.push_back(parent); }

    void addState(const std::string &label) {
        if (stateLabel_to_stateIndex_.cend() != stateLabel_to_stateIndex_.find(label)) {
            /* The same stateLabel has already existed */
            throw std::runtime_error("Same state name: " + label + ".");
        }
        stateLabel_to_stateIndex_[label] = stateLabels_.size();
        stateLabels_.push_back(label);
    }
    //@}

///@name constructor
//@{
    Node(BayesianNetwork *network,  ///< The BN possesses this Node
         const string &nodeName,
         const size_t &nodeIndex) :
            network_(network), node_name_(nodeName), node_index_(nodeIndex) {}
//@}
private:
    BayesianNetwork *network_; ///< Brief
    size_t node_index_; ///< The index of this node
    std::string node_name_;  //!< The name of this node

    std::vector<std::string> stateLabels_;
    std::map<std::string, size_t> stateLabel_to_stateIndex_;

    vector<Node *> parents_;    //!< Parent nodes of *this node

    //std::vector<std::vector<cppbn::real>> data_;
};


#endif //LIBCPPBN_NODE_H
