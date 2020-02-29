//
// Created by pol on 2/29/20.
//

#ifndef A_DIVISION_HASH_H
#define A_DIVISION_HASH_H

#include "hash_function.h"


class DivisionHash : public HashFunction{


public:

    /**
     * @brief basic constructor, define the name
     * */
    DivisionHash();

    /**
     * @brief hash division function
     *        referencing D.E. Knuth [515-516]
     * @pre tableSize > 0
     * @post true
     * @param value is the key to be hashed
     * @param tableSize is the size of the hash table
     * @returns the hashed value of the key
     * */
    virtual unsigned int operator()(int key, unsigned int tableSize) const override ;

private:


};


#endif //A_DIVISION_HASH_H
