#include "random_hash.h"

unsigned int RandomHash::operator()(int key, unsigned int tableSize) const {
    return RandGenerator::generate(key) % tableSize;
}
