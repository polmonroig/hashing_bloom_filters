//
// Created by pol on 2/29/20.
//

#ifndef A_MULTIWORD_HASH_H
#define A_MULTIWORD_HASH_H


#include <vector>
#include <string>

#include "hash_functions/hash_function.h"

/**
 * @class Represents a hash function that recursively hashes
 *        a sequence of integers with a specified single hash function
 * */
class MultiWordHash {


public:

    /**
     * @brief Basic constructor of the class
     * @param hash_function is the single hash function used
     *        to compute the multi word hashing
     * */
    explicit MultiWordHash(HashFunction const& hash_function);

    /**
     * @brief Hash function operator for a sequence of characters
     * @param words is the sequence of characters (string) to hash
     * @returns the hashed string
     * */
    unsigned int operator()(std::string const& words) const;

    /**
     * @brief Hash function operator for a sequence of integers
     * @param words contains each integer
     * @returns the hashed integer sequence
     * */
    unsigned int operator()(std::vector<int> const& words) const;

private:

    /**
     * @brief the single hash function
     * */
    HashFunction hash;

};


#endif //A_MULTIWORD_HASH_H
