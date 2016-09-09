#include <iostream>

#include <boost/timer/timer.hpp>
#include <cmath>


#include <boost/rational.hpp>
#include "bn/BayesianNetwork.h"
#include "bn/sorted_set.h"
#include "bn007.h"
#include "bn/typedefs.h"

using namespace std;

int main() {

    BayesianNetwork network;

    std::cout << BOLDRED << "bold red text" << RESET << std::endl;

#if !defined(NDEBUG)
    cout << "DEBUG code is here!" << endl;
#endif

    boost::timer::auto_cpu_timer t;

    bn007* bn = new bn007();

    string s{"hel"};

    bn->talk();

    bn->tell(s);

    delete bn;

    sorted_set<int> a;


    real value = 0.3;

    std::cout << "real value: " << value << std::endl;



    std::cout << "Hello, World!" << std::endl;


    for (long i = 0; i < 100000000; ++i)
        std::sqrt(123.456L); // burn some time

    return 0;
}

