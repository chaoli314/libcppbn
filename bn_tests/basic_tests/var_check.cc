//
// Created by chao li on 12/16/16.
//

#include "gtest/gtest.h"
#include "var.h"

class var_Fixture : public ::testing::Test {

public:
    ~var_Fixture() override { delete x; }

protected:
    var_Fixture() : Test() { x = new var(5, 3); }

    virtual void SetUp() {}

    virtual void TearDown() {}

    var *x;
};

TEST_F(var_Fixture, stream_check) {
    // expect string
    std::string s{"x5"};

    // operator<<
    std::ostringstream oss;
    oss << *x;
    EXPECT_EQ(s, oss.str());

    // toString
    EXPECT_EQ(s, x->toString());
}