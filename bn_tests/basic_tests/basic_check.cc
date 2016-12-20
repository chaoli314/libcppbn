//
// Created by chao li on 12/14/16.
//
#include "gtest/gtest.h"

#include <boost/timer/timer.hpp>    //  from, http://www.boost.org/doc/libs/1_58_0/libs/timer/doc/cpu_timers.html
#include <cmath>
#include <iostream>

TEST(basic_check, test_eq) {
    size_t a = 2;
    size_t b = 2;
    EXPECT_EQ(1, a / b);
}

TEST(basic_check, test_neq) {
    EXPECT_NE(1, 0);

    //std::cout << std::endl << "DUMMY: 10000000 times computation start!" << std::endl;
    boost::timer::auto_cpu_timer t;
    for (auto i = 0; i < 10000000; ++i)
        std::sqrt(i); // burn some time
    t.stop();
    //t.report();
    //std::cout << "DUMMY: 10000000 times computation end!" << std::endl;
}
