#ifndef A_BLOOM_FILTERS_H
#define A_BLOOM_FILTERS_H

#include <vector>
#include <cmath>

#include "../dictionary.h"
#include "../../hash/hash_functions/hash_function.h"


/**
 * @class BloomFilters
 * @brief Bloom Filters implementation for a space-efficient randomized data structure
 *        B. Bloom. “Space/Time Tradeoffs in Hash Coding with Allowable Errors.”
 *        Communications of the ACM 13:7 (1970), 422—426.
 * */
class BloomFilters : public Dictionary{

public:

    /**
     * @brief Default class constructor with hyper-parameters
     * @param tableSize is the size of the filters
     * @param nHashFunctions is the number of hash functions to apply
     * @param hash1 first hash definition
     * @param hash2 second hash definition
     * */
    BloomFilters(int tableSize, int nHashFunctions, HashFunction  &hash1, HashFunction  &hash2);

    /**
     * @brief Function that inserts a value into the bloom filter
     * @param value is the key to insert
     * */
    virtual void insert(int value) final;

    /**
     * @brief Function that finds if an item is in the dictionary
     *        with a probability of false positive greater than 1
     * @param value to search
     * @returns if found
     * */
    virtual bool find(int value) final;

    /**
     * @brief Function that gets how many probes where found in a given lookup
     * @returns ithe number of probes
     * */
    virtual unsigned int getCollisions() const;

    /**
     * @brief Function that gets how many probes where found in a given lookup
     * @returns ithe number of probes
     * */
    virtual double getTheoricalValue(bool success, float loadFactor) const final;

private:

    /**
     * @brief returns the ith hash of a value, function based to
     *        Adam Kirsch,* Michael Mitzenmacher†
     *        Less Hashing, Same Performance:
     *        Building a Better Bloom Filter
     * */
    unsigned int hash(int value, unsigned int i) const;

    /**
     * @brief k is the number of filters
     * */
    unsigned int k;

    /**
     * @brief the two basic hash functions
     * */
    HashFunction* h1, *h2;

    /**
     * @brief filters that save the occurrence of a key
     * */
    std::vector<bool> filters;

};


#endif //A_BLOOM_FILTERS_H
