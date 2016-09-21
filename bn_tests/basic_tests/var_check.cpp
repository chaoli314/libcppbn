//
// Created by chao li on 9/19/16.
//


#include "gtest/gtest.h"
#include "sorted_set.h"
#include "var.h"

class var_Fixture : public ::testing::Test {


protected:

    var_Fixture() : v1{1, 2}, v2{2, 3}, v3{3, 4} {}

    virtual ~var_Fixture() {}

    virtual void SetUp() {}

    virtual void TearDown() {}

    const var v1;
    const var v2;
    const var v3;
};


TEST_F(var_Fixture, tableSize_check) {

    sorted_set<var> set1 = {v1};
    sorted_set<var> set2 = {v2};
    sorted_set<var> set3 = {v3};
    sorted_set<var> varset123 = set1 | set2 | set3;

    EXPECT_EQ(2 * 3 * 4, getNumberOfAssignment(varset123));
}