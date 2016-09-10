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
    size_t getStateIndex(const std::string &label) const { return label_to_index_[label]; }
    std::string getStateLabel(size_t stateLabel) const { return index_to_label_[stateLabel]; }
    std::string getName() const { return name_; }
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

    void addState(const std::string& label) {
            if( label_to_index_.cend()!=label_to_index_.find(label) /* contains Key */){
                label_to_index_[label] = index_to_label_.size();
                index_to_label_.push_back(label);
            }
        }
     //@}




private:

    std::string name_;  //!< The name of this node

    vector<Node *> parents_;

    std::map<std::string, size_t> label_to_index_;
    std::vector<std::string> index_to_label_;

    BayesianNetwork *network_;  ///< Brief description after the member



    //std::vector<std::vector<double> > parameters;
};


#endif //LIBCPPBN_NODE_H
