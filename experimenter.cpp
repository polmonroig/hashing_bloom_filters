#include <iostream>

#include "experiment/experiment.h"
#include "dictionary/bloom_filters/bloom_filters.h"
#include "hash_functions/division_hash.h"
#include "hash_functions/multiplicative_hashing.h"

int main(){

    // PARAMETER DEFINITION
    int tableSize = 100;
    int n = 500;
    int nHashFunctions = 5;

    // DICTIONARY DEFINITION

    BloomFilters filters(tableSize, nHashFunctions, DivisionHash(), MultiplicativeHashing());

    // DEFINE AND RUN EXPERIMENT
    Experiment experiment(filters);
    experiment.test();
    experiment.write("tests/experiment.epx");

    return 0;
}