//
// Created by pol on 2/29/20.
//

#ifndef A_MULTIWORD_HASH_H
#define A_MULTIWORD_HASH_H


#include "hash_functions/hash_function.h"

class MultiWordHash {


public:

    explicit MultiWordHash(HashFunction const& hash_function);

private:

    HashFunction hash;

};


#endif //A_MULTIWORD_HASH_H
