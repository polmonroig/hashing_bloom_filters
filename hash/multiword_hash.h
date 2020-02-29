//
// Created by pol on 2/29/20.
//

#ifndef A_MULTIWORD_HASH_H
#define A_MULTIWORD_HASH_H


#include <vector>
#include <string>

#include "hash_functions/hash_function.h"

class MultiWordHash {


public:

    explicit MultiWordHash(HashFunction const& hash_function);

    unsigned int operator()(std::string const& words) const;

    unsigned int operator()(std::vector<int> const& words) const;

private:

    HashFunction hash;

};


#endif //A_MULTIWORD_HASH_H
