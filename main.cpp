#include <iostream>

#include <boost/timer/timer.hpp>
#include <cmath>


#include <boost/rational.hpp>
#include "bn/BayesianNetwork.h"
#include "sorted_set.h"
#include "bn/typedefs.h"
#include <fstream>
#include <exception>

#include <cstdlib>     /* getenv */
#include <HuginFormatFile.h>


using namespace std;

int main() {

    BayesianNetwork network;

    const string home_path {std::getenv("HOME")};
    string file =   home_path+ "/ClionProjects/libcppbn/bn_repos/bnlearn/asia.net";

    readHuginNet(&network, file);

//cout <<    network.getNodeName(2) << "index at " << 2 << endl;



    return 0;
}

