//
// Created by chao li on 9/11/16.
//

#include "gtest/gtest.h"
#include "var.h"

TEST(var_check, test_constructor){
    var x{11,13};
    EXPECT_EQ(13, x.getCard());
}

/// only check < and ==.
TEST(var_check, test_relational_operators){
    var x{11, 13};
    var y{11, 17};
    var z{13, 13};

    EXPECT_FALSE(x < y);
    EXPECT_TRUE (x < z);
    EXPECT_FALSE(y < x);
    EXPECT_TRUE (y < z);
    EXPECT_FALSE(z < x);
    EXPECT_FALSE(z < y);

    EXPECT_TRUE (x == y );
    EXPECT_FALSE(x == z );
    EXPECT_FALSE(y == z );
}
