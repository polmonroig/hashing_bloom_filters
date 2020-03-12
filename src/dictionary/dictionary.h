#ifndef A_DICTIONARY_H
#define A_DICTIONARY_H


/**
 * @class Dictionary
 * @brief The Dictionary class is an interface for all the hash tables
 *        and data structures that implement a key search
 * */
class Dictionary {

public:

    /**
     * @brief Function that inserts a value into the data structure
     * @param value is the key to insert
     * */
    virtual void insert(int value) = 0;


    /**
     * @brief Function that finds if an item is in the dictionary
     * @param value to search
     * @returns if found
     * */
    [[nodiscard]] virtual bool find(int value) = 0;

    /**
     * @brief Function that gets how many probes where found in a given lookup
     * @returns ithe number of probes
     * */
    virtual unsigned int getCollisions() const = 0;

    /**
     * @brief Function that finds the theorical value of the avg probes of a hash table
     * @param success is if it needs to return in case of success or fail
     * @param loadFactor the loadFactor of the table 
     * @return the avg probes
     * */
    virtual double getTheoricalValue(bool success, float loadFactor) const = 0;


protected:

    /**
     * @brief m is the size of the table
     * */
    int m;


    /**
     * @brief collisions is the number of collisions of the table
    * */
    unsigned int collisions;

};


#endif //A_DICTIONARY_H
