//
// Created by chao li on 9/7/16.
//


#include <boost/timer/timer.hpp>
#include <cmath>

#include "gtest/gtest.h"

TEST(basic_check, test_eq) {
    EXPECT_EQ(1, 1);
}

TEST(basic_check, test_neq) {
    EXPECT_NE(1, 0);

    boost::timer::auto_cpu_timer t; // test boost timer setup
    for (long i = 0; i < 100000000; ++i)
        std::sqrt(123.456L); // burn some time
    t.stop();
    //t.report();

}