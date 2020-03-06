#include "experiment.h"


/* =================================
 *               PUBLIC
 *  =================================*/

Experiment::Experiment(Dictionary  &dict) {
    dictionary = &dict;
}


void Experiment::write(std::string const& fileName) const {

}

void Experiment::test(std::vector<int> const &keys, std::vector<int> const &text) {
    buildTable(keys);
    double buildTime = getElapsedTime();
    unsigned int colisions = dictionary->getColisions();
    std::cout << "Colisions: " << colisions << std::endl;
    searchElements(text);
    unsigned int falsePositives = successLookupTimes - keys.size() / 2;
    std::cout << "False positives: " << falsePositives << std:: endl;
}


/* =================================
 *               PRIVATE
 *  =================================*/


void Experiment::buildTable(const std::vector<int> &vector) {
    startTimer();
    for(auto const& value : vector){
        dictionary->insert(value);
    }
    endTimer();
}

void Experiment::searchElements(const std::vector<int> &vector) {
    successLookupTimeMean = 0;
    failLookupTimeMean = 0;
    successLookupTimes = 0;
    failLookupTimes = 0;
    for(auto const& value : vector) {
        startTimer();
        bool found = dictionary->find(value);
        endTimer();
        double lookupTime = getElapsedTime();
        if (found) {
            successLookupTimes++;
            successLookupTimeMean += lookupTime;
        } else {
            failLookupTimes++;
            failLookupTimeMean += lookupTime;
        }
    }

    if(successLookupTimes > 0)
        successLookupTimeMean /= successLookupTimes;
    if(failLookupTimes > 0)
        failLookupTimeMean /= failLookupTimes;

    std::cout << "Succesful lookups: " << successLookupTimes << std::endl;
    std::cout << "Succesful mean lookup time: " <<successLookupTimeMean << std::endl;
    std::cout << "Failed lookups: " << failLookupTimes << std::endl;
    std::cout << "Failed mean lookup time: " <<failLookupTimeMean << std::endl;


}

void Experiment::startTimer() {
    startPoint = std::chrono::steady_clock::now();
}

void Experiment::endTimer() {
    endPoint = std::chrono::steady_clock::now();
}

double Experiment::getElapsedTime() const {
    return std::chrono::duration_cast<std::chrono::microseconds>(endPoint - startPoint).count();
}

