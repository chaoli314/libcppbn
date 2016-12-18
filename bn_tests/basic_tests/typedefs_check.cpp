//
// Created by chao li on 9/10/16.
//

#include "gtest/gtest.h"
#include "typedefs.h"
#include <cstdint>

#include <iostream>

TEST(typedefs_check, test_BigInteger) {

    // Repeat at arbitrary precision:
    cppbn::BigInteger u = 1;
    for(auto i = 1; i <= 100; ++i)
        u *= i;
    EXPECT_LT(INT64_MAX, u); // INT64_MAX is lower than u
    EXPECT_ANY_THROW(static_cast<size_t >(u)); // Throws a std::overflow_error.
}