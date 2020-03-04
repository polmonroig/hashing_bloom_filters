#include <cmath>
#include <iostream>
#include <filesystem>
#include <cmath>

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


void DataManager::generateIntegerData(std::string const& path, float appearance)const{

    auto fileName = path + getFileExtension();

    if(!std::filesystem::exists(fileName + "_dict")){
        std::ofstream file;
        std::cout << "Creating file" << std::endl;
        // write dictionary
        file.open(fileName + "_dict", std::ios::out);
        auto data = RandGenerator::generatePermutations(randomSeed, sequenceSize);
        writeData(file, data, sequenceSize);
        file.close();

        // write text file
        file.open(fileName + "_text" , std::ios::out);
        writeData(file, data, std::ceil(sequenceSize * appearance));

        data = RandGenerator::generatePermutations(data[data.size() - 1], sequenceSize * 2);
        writeData(file, data, sequenceSize * 2);

        file.close();
    }
    else{
        std::cerr << "File already exists!" << std::endl;
    }


}

std::vector<int> DataManager::getIntegerText(const std::string &path) const{
    auto fileName = path + getFileExtension() + "_dict";
    return getData(path);
}

std::vector<int> DataManager::getIntegerKeys(const std::string &path)const {
    auto fileName = path + getFileExtension() + "_text";
    return getData(path);
}


/** =================================
 *               PRIVATE
 *  =================================*/


std::vector<int> DataManager::getData(std::string const& fileName) const{
    std::vector<int> data;
    std::ifstream file;
    file.open(fileName, std::ios::in);
    BigInt input;
    while(file >> input){
        data.push_back(input);
    }
    return data;
}

std::string DataManager::getFileExtension() const{
    return "integer_" + std::to_string(randomSeed) + "_" + std::to_string(sequenceSize);
}

void DataManager::writeData(std::ofstream & file, std::vector<BigInt > const& data, int size)const{
    for(int i = 0; i < size; ++i)
        file << std::to_string(data[i]) + "\n";

}


