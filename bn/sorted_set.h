//
// Created by chao li on 9/9/16.
//

#ifndef LIBCPPBN_SORTED_SET_H
#define LIBCPPBN_SORTED_SET_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template< class T >
class sorted_set {
private:
    using Container = std::vector<T>;
public:
    typedef typename Container::size_type size_type;


   // typedef typename Container::value_type value_type;
  //  typedef value_type&                                         reference;
  //  typedef const value_type&                                   const_reference;

   // typedef typename Container::reference reference;
   // typedef typename Container::const_reference const_reference;
  //  typedef Container container_type;

  //  typedef typename Container::iterator                          iterator;
  //  typedef typename Container::const_iterator                          const_iterator;

    bool empty() const {
        return c.empty();
    }
    size_type size() const {
        return c.size();
    }

//    reference       operator[](size_type n){}
  //  const_reference operator[](size_type n) const{}


    //@{
    /** Same documentation for members. Details */


    /** Function without group. Details. */
    sorted_set operator- (const sorted_set & r) const {
        sorted_set result;
        std::set_difference( c.cbegin(), c.cend(), r.c.cbegin(), r.c.cend(), std::back_inserter(result)  );
        return result;
    }

    sorted_set operator& (const sorted_set & r) const {
        sorted_set result;
        std::set_intersection( c.cbegin(), c.cend(), r.c.cbegin(), r.c.cend(), std::back_inserter( result.c ) );
        return result;
    }
    sorted_set operator| (const sorted_set & r) const {
        sorted_set result;
        std::set_union( c.cbegin(), c.cend(), r.c.cbegin(), r.c.cend(), std::back_inserter( result.c ) );
        return result;
    }
    //@}



/** @name Group2
 *  Description of group 2.
 */
///@{

/** Function 2 in group 2. Details. */

    bool includes(const sorted_set & r) const {
        return std::includes(this->c.cbegin(), this->c.cend(),r.c.cbegin(),r.c.cend());
    }

    bool contains(const T& x) const {
        return std::binary_search( c.cbegin(), c.cend(), x);
    }

    // bool disjoint(const sorted_set & r)    {   return true;  }

///@}




//    void push_back(const T& x){ c.push_back(x); }




private:
    Container c;
};


#endif //LIBCPPBN_SORTED_SET_H
