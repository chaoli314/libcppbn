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
    // copy from Standard Template Library (STL).
    typedef typename Container::value_type value_type;
    typedef typename Container::size_type  size_type;

    typedef typename Container::reference       reference;
    typedef typename Container::const_reference const_reference;

    typedef typename Container::iterator       iterator;
    typedef typename Container::const_iterator const_iterator;

    typedef typename Container::reverse_iterator       reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

private:
    Container elements_;

public:
    /// @name Constructor
    //@{
    sorted_set() = default; // empty

    sorted_set(const sorted_set& x) = default; // copy

    sorted_set& operator=(const sorted_set& x)= default; // copy

    sorted_set(sorted_set&&) = default; // move

    sorted_set& operator=(sorted_set&&) = default; // move

    ~sorted_set() = default; // destructor

    sorted_set(const value_type& e) : elements_() { elements_.push_back(e); }

    template<typename InputIterator>
    sorted_set(InputIterator first, InputIterator last) : elements_(first, last) {
        std::sort(elements_.begin(), elements_.end());
        auto new_end = std::unique(elements_.begin(), elements_.end());
        elements_.erase(new_end, elements_.end());
    }

    //@}

    /// @name Iterators
    //@{
    iterator begin() noexcept { return elements_.begin(); }

    const_iterator begin() const noexcept { return elements_.begin(); }

    iterator end() noexcept { return elements_.end(); }

    const_iterator end() const noexcept { return elements_.end(); }

    reverse_iterator rbegin() noexcept { return elements_.rbegin(); }

    const_reverse_iterator rbegin() const noexcept { return elements_.rbegin(); }

    reverse_iterator rend() noexcept { return elements_.rend(); }

    const_reverse_iterator rend() const noexcept { return elements_.rend(); }

    const_iterator cbegin() const noexcept { return elements_.cbegin(); }

    const_iterator cend() const noexcept { return elements_.cend(); }

    const_reverse_iterator crbegin() const noexcept { return elements_.crbegin(); }

    const_reverse_iterator crend() const noexcept { return elements_.crend(); }
    //@}

    /// @name Element access
    //@{
    reference operator[](size_type pos) { return elements_[pos]; }

    const_reference operator[](size_type pos) const { return elements_[pos]; }

    const_reference front() const { return elements_.front(); }

    const_reference back() const { return elements_.back(); }
    //@}

    /// @name Capacity
    //@{
    size_type size() const { return elements_.size(); }

    bool empty() const { return elements_.empty(); }
    //@}



    ///@name Comparison operators
    //@{

    bool operator==(const sorted_set& rhs) const {
        return elements_ == rhs.elements_;
    }

    bool operator!=(const sorted_set& rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const sorted_set& rhs) const {
        return elements_ < rhs.elements_;
    }

    bool operator>(const sorted_set& rhs) const {
        return rhs < *this;
    }

    bool operator<=(const sorted_set& rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const sorted_set& rhs) const {
        return !(*this < rhs);
    }
    //@}

    /// @name Element operations (on sorted ranges)
    //@{


    void insert(const value_type& e) {
        auto it = std::lower_bound(elements_.begin(), elements_.end(), e);
        if ((elements_.end() == it/* e最大*/) || (e != *it/* e has been in the set */))
            elements_.insert(it, e);
    }

    void erase(const value_type& e) {
        auto it = lower_bound(elements_.begin(), elements_.end(), e);
        if ((elements_.end() != it/* e <= max value */) && (e == *it/* find e*/))
            elements_.erase(it);
    }

    bool contains(const value_type& t) const { return std::binary_search(elements_.cbegin(), elements_.cend(), t); }
    //@}

    /// \name Set operations (on sorted ranges)
    //@{
    sorted_set operator-(const sorted_set& rhs) const {
        sorted_set res;
        std::set_difference(elements_.cbegin(), elements_.cend(),
                            rhs.elements_.cbegin(), rhs.elements_.cend(),
                            std::back_inserter(res.elements_));
        return res;
    }

    sorted_set operator&(const sorted_set& rhs) const {
        sorted_set res;
        std::set_intersection(elements_.cbegin(), elements_.cend(),
                              rhs.elements_.cbegin(), rhs.elements_.cend(),
                              std::back_inserter(res.elements_));
        return res;
    }

    sorted_set operator|(const sorted_set& rhs) const {
        sorted_set res;
        std::set_union(elements_.cbegin(), elements_.cend(),
                       rhs.elements_.cbegin(), rhs.elements_.cend(),
                       std::back_inserter(res.elements_));
        return res;
    }

    bool includes(const sorted_set& rhs) const {
        return std::includes(elements_.cbegin(), elements_.cend(), rhs.elements_.cbegin(), rhs.elements_.cend());
    }

    bool disjoint(const sorted_set& rhs) const { return (*this & rhs).empty(); }

    bool intersects(const sorted_set& rhs) const { return !disjoint(rhs); }
    //@}

    /// @name std::cout & std::string
    //@{
    friend std::ostream& operator<<(std::ostream& os, const sorted_set& variables) {
        os << "{";
        for (auto it = variables.cbegin(); it != variables.cend(); it++)
            os << (it != variables.cbegin() ? ", " : "") << *it;
        os << "}";
        return os;
    }

    std::string toString() const {
        std::ostringstream oss;
        oss << *this;
        return oss.str();
    }
    //@}
};

#endif //LIBCPPBN_SORTED_SET_H