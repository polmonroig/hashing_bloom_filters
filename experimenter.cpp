#include <iostream>


#include "data/data_manager.h"
#include "experiment/experiment.h"
#include "dictionary/bloom_filters/bloom_filters.h"
#include "hash/hash_functions/division_hash.h"
#include "hash/hash_functions/multiplicative_hash.h"

int main(){

    // PARAMETER DEFINITION
    int tableSize = 10000000;
    int n = 1000;
    int nHashFunctions = 5;
    int seed = 165516;
    float keyPercentage = 0.5;

    // RANDOM DATA GENERATION

    DataManager data{};
    data.setSeed(seed);
    data.setSize(n);
    // creates the files if they do not exist already
    std::string path = "data/integer/";
    data.generateIntegerData(path, keyPercentage);

    // DICTIONARY DEFINITION
    auto h1 = DivisionHash();
    auto h2 = MultiplicativeHash();
    BloomFilters filters(tableSize, nHashFunctions, h1, h2);

    // DEFINE AND RUN EXPERIMENT
    Experiment experiment(filters);
    auto keys = data.getIntegerKeys(path);
    auto text = data.getIntegerText(path);
    std::cout << "Number of keys: " << keys.size() << std::endl;
    std::cout << "Number of texts: " << text.size() << std::endl;
    experiment.test(keys, text);
    experiment.write("tests/experiment.epx");

    return 0;
}
