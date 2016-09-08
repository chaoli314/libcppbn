#include <iostream>

#include <boost/timer/timer.hpp>
#include <cmath>

#include "bn/typedefs.h"


using namespace std;

int main() {
    boost::timer::auto_cpu_timer t;




#if !defined(NDEBUG)
    cout << "debug code is here!" << endl;
#endif

    real value = 0.3;

    std::cout << "real value: " << value << std::endl;



    std::cout << "Hello, World!" << std::endl;


    for (long i = 0; i < 100000000; ++i)
        std::sqrt(123.456L); // burn some time

    return 0;
}

