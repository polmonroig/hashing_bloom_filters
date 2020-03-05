#ifndef A_DATA_MANAGER_H
#define A_DATA_MANAGER_H

#include <fstream>
#include <string>

#include "../random/rand_generator.h"

class DataManager {

public:


    void setSeed(int seed);

    void setSize(unsigned int size);

    void generateIntegerData(std::string const& path, float appearance) const;

    [[nodiscard]] std::vector<int> getIntegerText(std::string const &path) const;

    [[nodiscard]] std::vector<int> getIntegerKeys(const std::string &path) const;

private:

    [[nodiscard]] std::string getFileExtension() const;
    [[nodiscard]] std::vector<int> getData(std::string const& fileName) const;
    void writeData(std::ofstream & file, std::vector<BigInt > const& data, int size)const;

    BigInt randomSeed;
    unsigned int sequenceSize;

};


#endif //A_DATA_MANAGER_H
