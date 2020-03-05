#ifndef A_SEPARATE_CHAINING_H
#define A_SEPARATE_CHAINING_H

#include <vector>

#include "../dictionary.h"
#include "../../hash/hash_functions/hash_function.h"


/**
 * @class   SeparateChaining
 * @brief   Separate Chaining, in this method each bucket is independent, and has some sort of list of entries with the same index.
 *           The time for hash table operations is the time to find the bucket (which is constant) plus the time for the list operation.
 *           In a good hash table, each bucket has zero or one entries, and sometimes two or three, but rarely more than that.
 * */
class SeparateChaining : public Dictionary{

public:

    /**
     * @brief Default class constructor with hyper-parameters
     * @param tableSize is the size of the table
     * @param nHashFunctions is the number of hash functions to apply
     * @param hash1 first hash definition
     * @param hash2 second hash definition
     * */
    SeparateChaining();

    /**
     * @brief Function that inserts a value into the hash table
     * @param value is the key to insert
     * */
    virtual void insert(int value) final;

    /**
     * @brief Function that finds if an item is in the dictionary
     * @param value to search
     * @returns if found
     * */
    virtual bool find(int value) const final;

private:

    /**
     * @brief the basic hash functions
     * */
    HashFunction h;

    /**
     * @brief dictionary that stores the lists of keys
     * */
    std::vector<list<int>> dictionary;

};


#endif //A_SEPARATE_CHAINING_H
