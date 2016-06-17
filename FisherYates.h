//
// Created by Daniel Cherubini on 17/06/2016.
//

#ifndef RAND_FISHERYATES_H
#define RAND_FISHERYATES_H


#include <iostream>
#include <vector>
#include <random>
#include <MacTypes.h>

using namespace std;

static std::vector<string> rand_array(std::vector<string> elements) {
    std::srand(std::time(nullptr));

    auto currentIndexCounter = elements.size();

    for (auto iter = elements.rbegin(); iter != elements.rend();
         iter++, --currentIndexCounter)
    {
        int randomIndex = std::rand() % currentIndexCounter;

        if (*iter != elements.at(randomIndex)) {
            std::swap(elements.at(randomIndex), *iter);
        }
    }

    return elements;
}

#endif //RAND_FISHERYATES_H
