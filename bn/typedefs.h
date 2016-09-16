//
// Created by chao li on 9/7/16.
//

#ifndef LIBCPPBN_TYPEDEFS_H_H
#define LIBCPPBN_TYPEDEFS_H_H

#include <string>
#include <boost/multiprecision/cpp_int.hpp>

namespace cppbn{

    using real = double;
    using Bigint = boost::multiprecision::checked_cpp_int;

    //using varset =


} // end of namespace cppbn

#define RESET       "\033[0m"
#define RED         "\033[31m"      /* Red */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
// std::cout << BOLDRED << "bold red text" << RESET << std::endl;

#endif //LIBCPPBN_TYPEDEFS_H_H
