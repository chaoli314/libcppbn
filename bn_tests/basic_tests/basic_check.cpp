//
// Created by chao li on 9/7/16.
//


#include <boost/timer/timer.hpp>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

#include "gtest/gtest.h"
#include "typedefs.h"
TEST(basic_check, test_eq) {
EXPECT_EQ(1, 1);
}

TEST(basic_check, test_neq) {
EXPECT_NE(1, 0);

        boost::timer::auto_cpu_timer t;

        for (long i = 0; i < 100000000; ++i)
            std::sqrt(123.456L); // burn some time


    // Repeat at arbitrary precision:
    bigint j = 1;
    for(auto i = 1; i <= 20; ++i)
        j *= i;
    EXPECT_EQ(2432902008176640000, j);
    EXPECT_LT(-100,j);
    EXPECT_GT(j,100);
    //std::cout << j << std::endl; // prints 100!

}