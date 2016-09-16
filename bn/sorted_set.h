//
// Created by chao li on 9/9/16.
//

#ifndef LIBCPPBN_SORTED_SET_H
#define LIBCPPBN_SORTED_SET_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>


using namespace std;

template<typename E>
class sorted_set {
public:
    using Container = std::vector<E>;

    typedef typename Container::size_type size_type;

    typedef typename Container::reference reference;
    typedef typename Container::const_reference const_reference;

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;
private:
    Container elements_;
public:

    /// @name Constructor
    //@{
    sorted_set() : elements_() {}

    sorted_set(const E &e) : elements_() { elements_.push_back(e); }
    //@}

    /// @name Element access
    //@{
    reference operator[](size_t pos) {
        return elements_[pos];
    }

    const_reference operator[](size_t pos) const {
        return elements_[pos];
    }
    //@}

    /// @name Capacity
    //@{
    size_type size() const { return elements_.size(); }

    bool empty() const { elements_.empty(); }
    //@}

    /// @name Iterators
    //@{
    iterator begin() { return elements_.begin(); }
    const_iterator begin() const noexcept{ return elements_.begin(); }

    const_iterator cbegin() const { return elements_.cbegin(); }

    iterator end()  { return elements_.end(); }
    const_iterator end() const noexcept{ return elements_.end(); }

    const_iterator cend() const { return elements_.cend(); }

    reverse_iterator rbegin() { return elements_.rbegin(); }

    const_reverse_iterator crbegin() const { return elements_.crbegin(); }

    reverse_iterator rend() { return elements_.rend(); }

    const_reverse_iterator crend() const { return elements_.crend(); }
    //@}

    ///@name Comparisons
    //@{
    bool operator==(const sorted_set &rhs) const {
        return elements_ == rhs.elements_;
    }

    bool operator!=(const sorted_set &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const sorted_set &rhs) const {
        return elements_ < rhs.elements_;
    }

    bool operator>(const sorted_set &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const sorted_set &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const sorted_set &rhs) const {
        return !(*this < rhs);
    }
    //@}

    /// @name Element
    //@{
    bool contains(const E &e) const {
        return std::binary_search(elements_.cbegin(), elements_.cend(), e);
    }

    void insert(const E &e) {
        iterator it = std::lower_bound(elements_.begin(), elements_.end(), e);
        if ((elements_.end() == it/* e最大*/) || (e != *it/* e不重复*/))
            elements_.insert(it, e);
    }

    void erases(const E &e) {
        iterator it = lower_bound(elements_.begin(), elements_.end(), e);
        if ((elements_.end() != it/* e非最大*/) && (e == *it/* e找到*/))
            elements_.erase(it);
    }
    //@}

    /// \name Set operations (on sorted ranges)
    //@{
    sorted_set operator-(const sorted_set &rhs) const {
        sorted_set res;
        std::set_difference(elements_.cbegin(), elements_.cend(),
                            rhs.elements_.cbegin(), rhs.elements_.cend(),
                            std::back_inserter(res.elements_));
        return res;
    }

    sorted_set operator&(const sorted_set &rhs) const {
        sorted_set res;
        std::set_intersection(elements_.cbegin(), elements_.cend(),
                              rhs.elements_.cbegin(), rhs.elements_.cend(),
                              std::back_inserter(res.elements_));
        return res;
    }

    sorted_set operator|(const sorted_set &rhs) const {
        sorted_set res;
        std::set_union(elements_.cbegin(), elements_.cend(),
                       rhs.elements_.cbegin(), rhs.elements_.cend(),
                       std::back_inserter(res.elements_));
        return res;
    }

    bool includes(const sorted_set &rhs) const {
        return std::includes(elements_.cbegin(), elements_.cend(), rhs.elements_.cbegin(), rhs.elements_.cend());
    }

    bool disjoint(const sorted_set &rhs) const {
        return (*this & rhs).empty();
    }

    bool intersects(const sorted_set &rhs) const { return !disjoint(rhs); }
    //@}

    /// @name std::cout & std::string
    //@{
    friend std::ostream &operator<<(std::ostream &os, const sorted_set &variables) {
        os << "{";
        for (auto it = variables.cbegin(); variables.cend() != it; ++it)
            os << (it != variables.cbegin() ? ", " : "") << *it;
        os << "}";
        return os;
    }

    operator std::string() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
    //@}
};

#endif //LIBCPPBN_SORTED_SET_H
