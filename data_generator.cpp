#include <iostream>


#include "data/data_manager.h"

int main(){

    int seed = 4156156;
    unsigned int size = 500;
    int nFiles = 3;
    DataManager data;
    data.setSeed(seed);
    data.setSize(size);
    std::string path = "/home/pol/Documents/fib/A/data/integer/";
    data.generateIntegerData(path + "integer_" + std::to_string(seed), nFiles);
    return 0;
}