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

/// Brief description.
/** Detailed description.
 *
 * \author chao li
 * */
class Node {


public:

/**  @name Lookup */
    //@{
    size_t getStateIndex(const std::string &stateLabel) const { return label_to_index_[stateLabel]; }

    std::string getStateLabel(size_t stateIndex) const { return index_to_label_[stateIndex]; }

    std::string getName() const { return node_name_; }

    size_t getIndex() const { return node_index_; }
    //@}

    /**  @name Capacity */
    //@{
    size_t getNumberOfStates() const { return index_to_label_.size(); }
    //@}




    /**  @name Modifiers */
    //@{
    ///   Add parent as a new parent of this node.
    /**    That is, add a directed link from parent to this node.     */
    void addParent(Node *parent) { parents_.push_back(parent); }

    void addState(const std::string &label) {
        if (label_to_index_.cend() != label_to_index_.find(label) /* Only add new state */) {
            label_to_index_[label] = index_to_label_.size();
            index_to_label_.push_back(label);
        }
    }
    //@}


    Node(BayesianNetwork *network,  ///< Container has this Node
         const string &nodeName,
         size_t nodeIndex) :
            network_(network), node_name_(nodeName), node_index_(nodeIndex) {}

private:
    BayesianNetwork *network_;  ///< Brief description after the member

    std::string node_name_;  //!< The name of this node
    size_t node_index_; ///< The index of this node

    std::map<std::string, size_t> label_to_index_;
    std::vector<std::string> index_to_label_;


    vector<Node *> parents_;

    //std::vector<std::vector<double> > parameters;
};


#endif //LIBCPPBN_NODE_H
