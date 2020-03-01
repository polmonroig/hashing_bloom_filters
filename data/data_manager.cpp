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


void DataManager::generateIntegerData(std::string const& fileName, int nFiles){
    std::ofstream file;
    file.open(fileName + "_dict", std::ios::out);

    // write dictionary
    auto data = RandGenerator::generatePermutations(randomSeed, sequenceSize);
    writeData(file, data);
    file.close();

    // write text files
    for(int i = 0; i < nFiles; ++i){
        file.open(fileName + "_text_" + std::to_string(i), std::ios::out);
        writeData(file, data);
        randomSeed = RandGenerator::generate(randomSeed);
        auto unknownData = RandGenerator::generatePermutations(randomSeed, sequenceSize * 2);
        writeData(file, unknownData);

        file.close();
    }

}


/** =================================
 *               PRIVATE
 *  =================================*/


void DataManager::writeData(std::ofstream & file, std::vector<BigInt > const& data)const{
    for(auto const& value : data){
        file << std::to_string(value) + "\n";
    }
}