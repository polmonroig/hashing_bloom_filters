#include <iostream>
#include "data_manager.h"

/** =================================
 *               PUBLIC
 *  =================================*/



void DataManager::setSeed(int seed) {
    randomSeed = seed;
}

void DataManager::setSize(unsigned int size) {
    sequenceSize = size;
}


void DataManager::generateIntegerData(std::string const& fileName, float appearance){
    std::ofstream file;
    file.open(fileName + "_dict", std::ios::out);

    // write dictionary
    auto data = RandGenerator::generatePermutations(randomSeed, sequenceSize);
    writeData(file, data);
    file.close();

    // write text file
    file.open(fileName + "_text" , std::ios::out);
    data = RandGenerator::generatePermutations(randomSeed, int(float(sequenceSize) * appearance));
    writeData(file, data);
    randomSeed = RandGenerator::generate(randomSeed);
    data = RandGenerator::generatePermutations(randomSeed, sequenceSize * 2);
    writeData(file, data);

    file.close();



}


/** =================================
 *               PRIVATE
 *  =================================*/


void DataManager::writeData(std::ofstream & file, std::vector<BigInt > const& data)const{
    for(auto const& value : data){
        file << std::to_string(value) + "\n";
    }
}