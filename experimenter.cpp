#include <iostream>


#include "data/data_manager.h"
#include "experiment/experiment.h"
#include "dictionary/bloom_filters/bloom_filters.h"
#include "hash_functions/division_hash.h"
#include "hash_functions/multiplicative_hashing.h"

int main(){

    // PARAMETER DEFINITION
    int tableSize = 100;
    int n = 500;
    int nHashFunctions = 5;
    int seed = 4156156;
    unsigned int size = 500;
    float keyPercentage = 0.5;

    // RANDOM DATA GENERATION

    DataManager data{};
    data.setSeed(seed);
    data.setSize(size);
    std::string path = "/home/pol/Documents/fib/A/data/integer/";
    std::string file_name = path + "integer_" + std::to_string(seed);
    data.generateIntegerData(file_name, keyPercentage);

    // DICTIONARY DEFINITION

    BloomFilters filters(tableSize, nHashFunctions, DivisionHash(), MultiplicativeHashing());

    // DEFINE AND RUN EXPERIMENT
    Experiment experiment(filters);
    experiment.test();
    experiment.write("tests/experiment.epx");

    return 0;
}