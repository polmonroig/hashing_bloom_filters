#ifndef A_DATA_MANAGER_H
#define A_DATA_MANAGER_H

#include <fstream>
#include <string>

#include "../random/rand_generator.h"

class DataManager {

public:


    void setSeed(int seed);

    void setSize(unsigned int size);

    void generateIntegerData(std::string const& fileName, float appearance) ;

private:


    void writeData(std::ofstream & file, std::vector<BigInt > const& data)const;

    BigInt randomSeed;
    unsigned int sequenceSize;

};


#endif //A_DATA_MANAGER_H
