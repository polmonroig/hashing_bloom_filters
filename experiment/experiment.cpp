#include "experiment.h"


/** =================================
 *               PUBLIC
 *  =================================*/

Experiment::Experiment(Dictionary  &dict) {
    dictionary = &dict;
}


void Experiment::write(std::string const& fileName) const {

}

void Experiment::test(std::vector<int> const &keys, std::vector<int> const &text) {
    buildTable(keys);
    searchElements(text);
}


/** =================================
 *               PRIVATE
 *  =================================*/


void Experiment::buildTable(const std::vector<int> &vector) {
    for(auto const& value : vector){
        dictionary->insert(value);
    }
}

void Experiment::searchElements(const std::vector<int> &vector) {
    for(auto const& value : vector){
        bool found = dictionary->find(value);
        std::cout << found;
    }
}
