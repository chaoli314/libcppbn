//
// Created by chao li on 9/15/16.
//

#ifndef LIBCPPBN_HUGINNETFILE_H
#define LIBCPPBN_HUGINNETFILE_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "BayesianNetwork.h"

using namespace std;

void saveAsHuginNet(BayesianNetwork *outNetwork, const std::string &outFileName);

void readHuginNet(BayesianNetwork *inNetwork, const std::string &inFileName){

    std::string line;
    std::string allLines;



    ifstream myfile (inFileName);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            allLines += line;
        }
        myfile.close();
    } else {
        cout << "Unable to open file";
    }




}


#endif //LIBCPPBN_HUGINNETFILE_H
