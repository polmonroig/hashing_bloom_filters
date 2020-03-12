#include "bloom_filters.h"


/* =================================
 *               PUBLIC
 *  =================================*/

BloomFilters::BloomFilters(int tableSize, int nHashFunctions, HashFunction &hash1, HashFunction &hash2) {
    k = nHashFunctions;
    m = tableSize;
    h1 = &hash1;
    h2 = &hash2;
    filters = std::vector<bool>(m, false);
}

bool BloomFilters::find(int value) {

    for(unsigned int i = 0; i < k; ++i){
        if(!filters[hash(value, i)])
            return false;
    }
    return true;
}

void BloomFilters::insert(int value) {
    for(unsigned int i = 0; i < k; ++i){
        filters[hash(value, i)] = true;
    }
}


unsigned int BloomFilters::getCollisions() const {
    return 1;
}
#include<iostream>
double BloomFilters::getTheoricalValue(bool success, float loadFactor) const{
    auto value = 1 / std::exp(k *  loadFactor);
    return std::pow(1.0 - value, 2);
}

/* =================================
 *               PRIVATE
 *  =================================*/

unsigned int BloomFilters::hash(int value, unsigned int i) const {
    return ((*h1)(value, m) + i * (*h2)(value, m)) % m;
}
