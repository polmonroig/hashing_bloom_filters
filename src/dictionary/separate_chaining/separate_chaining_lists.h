#ifndef A_SEPARATE_CHAINING_LIST_H
#define A_SEPARATE_CHAINING_LIST_H


#include <list>
#include <vector>

#include "../dictionary.h"
#include "../../hash/hash_functions/hash_function.h"


/**
 * @class   SeparateChainingLists
 * @brief   in this method each bucket is independent, and has some sort of list of entries with the same index.
 *          The time for hash table operations is the time to find the bucket (which is constant) plus the time for the list operation.
 *          In a good hash table, each bucket has zero or one entries, and sometimes two or three, but rarely more than that.
 * */
class SeparateChainingLists : public Dictionary {

public:

    /**
     * @brief Default class constructor with hyper-parameters
     * @param tableSize is the size of the table
     * @param hash definition
     * */
    SeparateChainingLists(int tableSize, HashFunction &hash);

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

    /**
     * @brief Function that gets how many probes where found in a given lookup
     * @returns ithe number of probes
     * */
    virtual unsigned int getCollisions() const;

    /**
     * @brief Function that finds the theorical value of the avg probes of a hash table
     * @param success is if it needs to return in case of success or fail
     * @param loadFactor the loadFactor of the table
     * @return the avg probes
     * */
    virtual double getTheoricalValue(bool success, float loadFactor) const final;


private:

    /**
     * @brief the basic hash functions
     * */
    HashFunction* h;

    /**
     * @brief dictionary that stores the lists of keys
     * */
    std::vector<std::list<int> > dictionary;

    /**
     * @brief function that return the hashed value of a key
     * */
    unsigned int hash(int key) const;

    /**
     * @brief collisions counter
     * */
    unsigned int collisions;

};


#endif //A_SEPARATE_CHAINING_LIST_H
