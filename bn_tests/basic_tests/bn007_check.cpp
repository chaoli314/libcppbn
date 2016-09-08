//
// Created by chao li on 9/7/16.
//

#include "gtest/gtest.h"

#include "bn007.h"

class bn007Fixture : public ::testing::Test {
protected:

    virtual void SetUp() {
        bn->talk();
    }

    virtual void TearDown() {

    }


public:
    bn007Fixture() : Test() {
        bn = new bn007();
    }

    virtual ~bn007Fixture() {
        delete bn;
    }

    bn007 * bn;
};

TEST_F(bn007Fixture, absolute_date_check) {
    EXPECT_EQ(1, 1);
}

TEST_F(bn007Fixture, plus_one_date_check) {
    EXPECT_EQ(1, 1);
}