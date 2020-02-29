//
// Created by pol on 2/29/20.
//

#include "multiword_hash.h"

MultiWordHash::MultiWordHash(HashFunction const &hash_function) {
    hash = hash_function;
}

unsigned int MultiWordHash::operator()(std::string const &words) const {
    return 0;
}

unsigned int MultiWordHash::operator()(std::vector<int> const &words) const {
    return 0;
}
