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

/**
 * @class   ExperimentManager
 * @brief   this class generates an experiment and saves it to a csv file
 *          given a series of parameters
 * */
class ExperimentManager{

public:

    /**
     * @brief Big setter for all the parameters
     * @param n the number of keys
     * @param loadFactor the loadFactor of the table
     * @param tableSize is the size of the table
     * @param nHashFunctions is the number of hash functions to compute for the bloom filters
     * @param seed is the random seed to generate the data
     * @param keyPercentage percentage of keys that are in the text for lookups
     * @param inputPath is where the data will be generated
     * @param outputPath is the path where the experiment will be written
     * */
    void setParameters(int n, float loadFactor, int tableSize, int nHashFunctions,
                        int seed,float keyPercentage, std::string const& inputPath,
                        std::string const& outputPath);

    /**
     * @brief starts the experiment
     * */
    void test();


private:

    /**
     * @brief generates the data of the experiment to inputPath
     * */
    void generateData();

    /**
     * @brief given an experiment and the name of the hash table
     *        it generates a row with the experiment results
     * @param experiment contains the results
     * @param name is the name of the hash table
     * */
    CsvRow generateRow(Experiment const& experiment, std::string const& name);

    /**
     * @brief generates the names of the hash tables
     * @returns an array of names
     * */
    static std::vector<std::string> generateNames();

    /**
     * @brief generates the data of the experiment to inputPath
     * @returns an array with the name of each column of the experiment
     * */
    static CsvRow generateColNames();

    /**
     * @brief represents the data manager
     * */
    DataManager data;

    /**
     * @brief number of keys
     * */
    int n;

    /**
     * @brief the load factor of the table
     * */
    float loadFactor;

    /**
     * @brief the size of the hash table
     * */
    int tableSize;

    /**
     * @brief number of hash functions for the bloom filters
     * */
    int nHashFunctions;

    /**
     * @brief randoom seed
     * */
    int seed;

    /**
     * @brief key percentage
     * */
    float keyPercentage;

    /**
     * @brief path where the data is saved
     * */
    std::string inputPath;

    /**
     * @brief path where the experiment is saved 
     * */
    std::string outputPath;


};



#endif // A_EXPERIMENT_MANAGER_H
