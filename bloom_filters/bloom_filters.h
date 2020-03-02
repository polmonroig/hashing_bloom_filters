#ifndef A_BLOOM_FILTERS_H
#define A_BLOOM_FILTERS_H

#include <vector>

#include "../hash/hash_functions/hash_function.h"

class BloomFilters {

public:

    BloomFilters()= default;
    BloomFilters(int tableSize, int nHashFunctions, HashFunction const &hash1, HashFunction const &hash2);


    void insert(int value);
    bool find(int value) const;

private:

    unsigned int k, m;

    HashFunction h1, h2;

    std::vector<bool> filters;

};


#endif //A_BLOOM_FILTERS_H
