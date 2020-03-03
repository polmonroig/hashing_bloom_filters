#ifndef A_DICTIONARY_H
#define A_DICTIONARY_H


/**
 * @class The Dictionary class is an interface for all the hash tables
 *        and data structures that implement a key search
 * */
class Dictionary {

public:

    /**
     * @brief Function that inserts a value into the data structure
     * @param value is the key to insert
     * */
    virtual void insert(int value);


    /**
     * @brief Function that finds if an item is in the dictionary
     * @param value to search
     * @returns if found
     * */
    virtual bool find(int value) const;


protected:
    int m;

};


#endif //A_DICTIONARY_H
