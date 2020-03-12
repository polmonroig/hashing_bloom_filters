#ifndef A_EXPERIMENT_MANAGER_H
#define A_EXPERIMENT_MANAGER_H

#include <iostream>

#include "../data/data_manager.h"
#include "experiment.h"
#include "../dictionary/bloom_filters/bloom_filters.h"
#include "../dictionary/open_hashing/double_hashing/double_hashing.h"
#include "../dictionary/open_hashing/cuckoo_hashing/cuckoo_hashing.h"
#include "../dictionary/open_hashing/linear_probing/linear_probing.h"
#include "../dictionary/separate_chaining/separate_chaining_lists.h"
#include "../dictionary/separate_chaining/separate_chaining_vector.h"
#include "../dictionary/open_hashing/quadratic_probing/quadratic_probing.h"
#include "../hash/hash_functions/division_hash.h"
#include "../hash/hash_functions/fibonacci_hash.h"
#include "../hash/hash_functions/random_hash.h"
#include "../data/csv_file.h"

class ExperimentManager{

public:

    void setParameters(int n, float loadFactor, int tableSize, int nHashFunctions,
                        int seed,float keyPercentage, std::string const& inputPath,
                        std::string const& outputPath);


    void test();


private:

    void generateData();
    CsvRow generateRow(Experiment const& experiment, std::string const& name);
    static std::vector<std::string> generateNames();
    static CsvRow generateColNames();


    DataManager data;


    int n;
    float loadFactor;
    int tableSize;
    int nHashFunctions;
    int seed;
    float keyPercentage;
    std::string inputPath;
    std::string outputPath;


};



#endif // A_EXPERIMENT_MANAGER_H
