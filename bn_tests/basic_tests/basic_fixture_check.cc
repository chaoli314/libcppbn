//
// Created by chao li on 9/7/16.
//

#include "gtest/gtest.h"
#include "BasicClass.h"

class BasicClassFixture : public ::testing::Test {
protected:

    virtual void SetUp() {
        bn->start();
    }

    virtual void TearDown() {
        bn->stop();
    }

public:
    BasicClassFixture() : Test() {
        bn = new BasicClass();
    }

    virtual ~BasicClassFixture() {
        delete bn;
    }

    BasicClass *bn;
};

TEST_F(BasicClassFixture, start_check) {
    EXPECT_EQ(1, 1);
}

TEST_F(BasicClassFixture, stop_check) {
    EXPECT_NE(1, 3);
}