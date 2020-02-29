//
// Created by pol on 2/29/20.
//

#include "multiword_hash.h"

MultiWordHash::MultiWordHash(HashFunction const &hash_function) {
    hash = hash_function;
}
