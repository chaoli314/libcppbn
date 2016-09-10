//
// Created by chao li on 9/7/16.
//

#ifndef LIBCPPBN_TYPEDEFS_H_H
#define LIBCPPBN_TYPEDEFS_H_H

#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using real = double;
using bigint = boost::multiprecision::cpp_int;

#define RESET       "\033[0m"
#define RED         "\033[31m"      /* Red */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
// std::cout << BOLDRED << "bold red text" << RESET << std::endl;

#endif //LIBCPPBN_TYPEDEFS_H_H