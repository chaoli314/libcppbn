//
// Created by chao li on 9/9/16.
//

#ifndef LIBCPPBN_SORTED_SET_H
#define LIBCPPBN_SORTED_SET_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template<class E>
class sorted_set {
private:
    using Container = std::vector<E>;
public:
    typedef typename Container::size_type size_type;
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    // typedef typename Container::value_type value_type;
    //  typedef value_type&                                         reference;
    //  typedef const value_type&                                   const_reference;

    // typedef typename Container::reference reference;
    // typedef typename Container::const_reference const_reference;
    //  typedef Container container_type;


    sorted_set() : c() {}

    sorted_set(const E &e) : c() { c.push_back(e); }

    bool empty() const {
        return c.empty();
    }

    size_type size() const {
        return c.size();
    }

    //    reference       operator[](size_type n){}
    //  const_reference operator[](size_type n) const{}

/**
 * @name Group
 * */
    //@{
    /** Function without group. Details. */
    sorted_set operator-(const sorted_set &r) const {
        sorted_set result;
        std::set_difference(c.cbegin(), c.cend(), r.c.cbegin(), r.c.cend(), std::back_inserter(result));
        return result;
    }

    sorted_set operator&(const sorted_set &r) const {
        sorted_set result;
        std::set_intersection(c.cbegin(), c.cend(), r.c.cbegin(), r.c.cend(), std::back_inserter(result.c));
        return result;
    }

    sorted_set operator|(const sorted_set &r) const {
        sorted_set result;
        std::set_union(c.cbegin(), c.cend(), r.c.cbegin(), r.c.cend(), std::back_inserter(result.c));
        return result;
    }
    //@}

/**
 * @name Modifiers
 * */
    //@{
    void insert(const E &e) {
        // it pointing to the first element does not less than e
        auto it = std::lower_bound(c.cbegin(), c.cend(), e);
        if (c.end() == it) c.push_back(e); // if e is the max
        if (e < *it) c.insert(it, e);   // if e is should be located here
    }
    //@}

/**
 * @name Lookup
 * Details
 * */
///@{

/// Function 1 in group 2. Brief.
/** Function 1 in group 2. Details. */

    bool includes(const sorted_set &X) const {
        return std::includes(this->c.cbegin(), this->c.cend(), X.c.cbegin(), X.c.cend());
    }

    /** Function 2 in group 2. Details. */
    bool contains(const E &e) const {
        return std::binary_search(c.cbegin(), c.cend(), e);
    }

    bool disjoint(const sorted_set &X) const {
        return (*this & X).empty();
    }

    // bool disjoint(const sorted_set & r)    {   return true;  }

///@}





private:
    Container c;
};


#endif //LIBCPPBN_SORTED_SET_H
