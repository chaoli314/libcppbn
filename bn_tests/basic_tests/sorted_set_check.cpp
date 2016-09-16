//
// Created by chao li on 9/11/16.
//


#include "gtest/gtest.h"
#include "sorted_set.h"

class sorted_set_Fixture : public ::testing::Test {


protected:

    sorted_set_Fixture() : x1(1), x2(2), x3(3), x4(4), x5(5) {}

    virtual ~sorted_set_Fixture() {}

    virtual void SetUp() {}

    virtual void TearDown() {}

    const sorted_set<int> x1;
    const sorted_set<int> x2;
    const sorted_set<int> x3;
    const sorted_set<int> x4;
    const sorted_set<int> x5;
};


TEST_F(sorted_set_Fixture, insert_check) {
    sorted_set<int> x;    // empty set
    sorted_set<int> x12 = x1 | x2;
    sorted_set<int> x23 = x2 | x3;
    sorted_set<int> x13 = x1 | x3;
    sorted_set<int> x123 = x12 | x3;
    sorted_set<int> y;

    y = x;
    y.insert(2);
    EXPECT_EQ(x2, y);

    y = x2;
    y.insert(1);
    EXPECT_EQ(x12, y);
    y = x2;
    y.insert(2);
    EXPECT_EQ(x2, y);
    y = x2;
    y.insert(3);
    EXPECT_EQ(x23, y);

    y = x13;
    y.insert(1);
    EXPECT_EQ(x13, y);
    y = x13;
    y.insert(2);
    EXPECT_EQ(x123, y);
    y = x13;
    y.insert(3);
    EXPECT_EQ(x13, y);

    y = x123;
    y.insert(1);
    EXPECT_EQ(x123, y);
    y = x123;
    y.insert(2);
    EXPECT_EQ(x123, y);
    y = x123;
    y.insert(3);
    EXPECT_EQ(x123, y);
}

TEST_F(sorted_set_Fixture, element_access_check) {
    sorted_set<int> x23 = x3 | x2;
    sorted_set<int> x123 = x1 | x23;

    EXPECT_EQ(1, x123[0]);
    EXPECT_EQ(2, x123[1]);
    EXPECT_EQ(3, x123[2]);

}