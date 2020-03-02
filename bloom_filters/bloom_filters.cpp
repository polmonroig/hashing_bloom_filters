#include "bloom_filters.h"


/** =================================
 *               PUBLIC
 *  =================================*/

BloomFilters::BloomFilters(int tableSize, int nHashFunctions, HashFunction const &hash1, HashFunction const &hash2) {
    k = nHashFunctions;
    m = tableSize;
    h1 = hash1;
    h2 = hash2;
    filters = std::vector<bool>(m, false);
}

bool BloomFilters::find(int value) const {

    for(unsigned int i = 0; i < k; ++i){
        if(!filters[h1(value, m) + i * h2(value, m)])
            return false;
    }
    return true;
}

void BloomFilters::insert(int value) {
    for(unsigned int i = 0; i < k; ++i){
        filters[h1(value, m) + i * h2(value, m)] = true;
    }
}
