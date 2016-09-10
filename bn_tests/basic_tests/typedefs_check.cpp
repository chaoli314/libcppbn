//
// Created by chao li on 9/10/16.
//

#include "gtest/gtest.h"
#include "typedefs.h"
#include <istream>

TEST(typedefs_check, test_eq) {
    EXPECT_EQ(1, 1);
}

TEST(typedefs_check, test_bigint) {

    // Repeat at arbitrary precision:
    bigint large_number = 1;
    for(auto i = 1; i <= 100; ++i)
        large_number *= i;
    //std::cout << large_number << std::endl; // prints 100!
    EXPECT_LT(INT64_MAX, large_number); // large_number is really larger than INT64_MAX.
}