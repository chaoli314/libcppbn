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



}
