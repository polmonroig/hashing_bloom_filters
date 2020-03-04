#include <iostream>


#include "data/data_manager.h"
#include "experiment/experiment.h"
#include "dictionary/bloom_filters/bloom_filters.h"
#include "hash/hash_functions/division_hash.h"
#include "hash/hash_functions/multiplicative_hash.h"

int main(){

    // PARAMETER DEFINITION
    int tableSize = 100;
    int n = 100;
    int nHashFunctions = 5;
    int seed = 4156156;
    float keyPercentage = 0.5;

    // RANDOM DATA GENERATION

    DataManager data{};
    data.setSeed(seed);
    data.setSize(n);
    // creates the files if they do not exist already
    std::string path = "/home/pol/Documents/fib/A/data/integer/";
    data.generateIntegerData(path, keyPercentage);

    // DICTIONARY DEFINITION

    BloomFilters filters(tableSize, nHashFunctions, DivisionHash(), MultiplicativeHash());

    // DEFINE AND RUN EXPERIMENT
    Experiment experiment(filters);
    auto keys = data.getIntegerKeys(path);
    auto text = data.getIntegerText(path);
    experiment.test(keys, text);
    experiment.write("tests/experiment.epx");

    return 0;
}