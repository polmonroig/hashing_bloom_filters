#ifndef A_DATA_MANAGER_H
#define A_DATA_MANAGER_H

#include <fstream>
#include <string>

#include "../random/rand_generator.h"


/**
 * @class DataManager
 * @brief This class has three important roles, it generates the random data,
 *        it writes in an output directory and finally you can read the generated file.
 *        The data created during the generation process won't be created if a file
 *        with the specified characteristics already exists
 * */
class DataManager {

public:

    /**
     * @brief sets the random seed for the generated data
     * @param seed is the initial random seed
     * */
    void setSeed(int seed);

    /**
     * @brief sets the random numbers to be generated
     * @param size the total of keys to be generated
     * */
    void setSize(unsigned int size);

    /**
     * @brief Generates a random data in the specified, it generated two types of
     *        data, the keys and the texts, the keys will be of size n and the texts
     *        will be of size 2*n + n* appearance
     * @param path the name of the file to generate
     * @param appearance the percentage of keys that need to appear in the text file
     * */
    void generateIntegerData(std::string const& path, float appearance) const;

    /**
     * @brief reads the keys of the given path
     * @param path is the directory of the file
     * */
    [[nodiscard]] std::vector<int> getIntegerText(std::string const &path) const;

    /**
     * @brief reads the text data of a given path
     * @param path is the directory of the file
     * */
    [[nodiscard]] std::vector<int> getIntegerKeys(const std::string &path) const;

private:

    /**
     * @brief generates a corresponding extension for a fileName, given the seed and sequence size
     * @returns the extension to generate
     * */
    [[nodiscard]] std::string getFileExtension() const;

    /**
     * @brief reads the data from a file
     * @param fileName is the path of the data to read
     * @returns the data formatted into an array
     * */
    [[nodiscard]] std::vector<int> getData(std::string const& fileName) const;

    /**
     * @brief given a file and a sequence of integers, it writes "size" integers into the file
     * @param file is the file to write into
     * @param data is the sequence of integers
     * @param size the number of integers to write
     * */
    void writeData(std::ofstream & file, std::vector<BigInt > const& data, int size)const;

    /**
     * @brief the seed to generate random numbers
     * */
    BigInt randomSeed;

    /**
     * @param is the size of the sequence to generate
     * */
    unsigned int sequenceSize;

};


#endif //A_DATA_MANAGER_H
