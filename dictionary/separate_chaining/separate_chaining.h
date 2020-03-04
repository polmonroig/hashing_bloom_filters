#ifndef A_SEPARATE_CHAINING_H
#define A_SEPARATE_CHAINING_H

#include <vector>

#include "../dictionary.h"
#include "../../hash/hash_functions/hash_function.h"


/**
 * @class   Separate Chaining, in this method each bucket is independent, and has some sort of list of entries with the same index. 
            The time for hash table operations is the time to find the bucket (which is constant) plus the time for the list operation.
            In a good hash table, each bucket has zero or one entries, and sometimes two or three, but rarely more than that. 
 * */
class SeparateChaining : public Dictionary{

public:

    /**
     * @brief Default class constructor with hyper-parameters
     * @param tableSize is the size of the filters
     * @param nHashFunctions is the number of hash functions to apply
     * @param hash1 first hash definition
     * @param hash2 second hash definition
     * */
    SeparateChaining(int tableSize, int nHashFunctions, HashFunction const &hash1, HashFunction const &hash2);

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
    virtual bool find(int value) const final;

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
    unsigned int k, m;

    /**
     * @brief the two basic hash functions
     * */
    HashFunction h1, h2;

    /**
     * @brief filters that save the occurrence of a key
     * */
    std::vector<bool> filters;

};


#endif //A_SEPARATE_CHAINING_H
