#ifndef A_SEPARATE_CHAINING_VECTOR_H
#define A_SEPARATE_CHAINING_VECTOR_H


#include <vector>

#include "../dictionary.h"
#include "../../hash/hash_functions/hash_function.h"


/**
 * @class   Separate Chaining, in this method each bucket is independent, and has some sort of vector of entries with the same index. 
            The time for hash table operations is the time to find the bucket (which is constant) plus the time for the vector operation.
            In a good hash table, each bucket has zero or one entries, and sometimes two or three, but rarely more than that. 
 * */
class SeparateChainingVector : public Dictionary {

public:

    /**
     * @brief Default class constructor with hyper-parameters
     * @param tableSize is the size of the table
     * @param hash definition
     * */
    SeparateChainingVector(int tableSize, HashFunction &hash);

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
    virtual bool find(int value) final;

    virtual unsigned int getColisions() const;
    

private:

    /**
     * @brief the basic hash functions
     * */
    HashFunction* h;

    /**
     * @brief dictionary that stores the vector of keys
     * */
    std::vector<std::vector<int> > dictionary;

    /**
     * @brief function that return the hashed value of a key
     * */
    unsigned int hash(int key) const;

};


#endif //A_SEPARATE_CHAINING_VECTOR_H
