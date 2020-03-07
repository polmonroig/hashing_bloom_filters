#ifndef A_EXPERIMENT_H
#define A_EXPERIMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include <chrono>

#include "../dictionary/dictionary.h"


/**
  * @typedef type definition for a really big double
  * */
typedef long double BigDouble;

/**
 * @class Experiment
 * @brief The experiment class receives some parameters and a dictionary
 *        and tests them, the results are saved in a data structure
 *        and finally they can be written into a file
 *
 * */
class Experiment {

public:

    /**
     * @brief Generate a basic experiment with a defined dictionary
     * @param dict is the dictionary to test
     * */
    explicit Experiment(Dictionary  &dict);

    /**
     * @brief This functions tests the dictionary with the specified
     *        parameters and saves the results
     * */
    void test(std::vector<int> const& keys, std::vector<int> const& text);


    std::string getCollisions() const;

    std::string getBuildTime() const;

private:

    /**
     * @brief represents the initial time for a task
     * */
    std::chrono::steady_clock::time_point startPoint;

    /**
     * @brief represents the final time for a task
     * */
    std::chrono::steady_clock::time_point endPoint;

    /**
     * @brief contains the number of the successful lookups of the experiment
     * */
    unsigned int successLookupTimes;

    /**
    * @brief contains the number of the failed lookups of the experiment
    * */
    unsigned int failLookupTimes;

    BigDouble successLookupTimeMean;

    BigDouble failLookupTimeMean;

    BigDouble  buildTime;

    unsigned int collisions;

    /**
     * @brief is the current dictionary
     * */
    Dictionary* dictionary;

    void startTimer();
    void endTimer();
    double getElapsedTime() const;

    /**
     * @brief test to build a table with the specified keys
     * @param vector keys to insert into the dictionary
     * */
    void buildTable(const std::vector<int> &vector);

    /**
     * @brief test to search n elements in the dictionary and save the results
     * @param vector contains the elements to search
     * */
    void searchElements(const std::vector<int> &vector);
};


#endif //A_EXPERIMENT_H
