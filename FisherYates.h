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

static std::vector<string> RandomizeArray(std::vector<string> elements) {
    //Loop through elements in array
    for (size_t i = 0; i != elements.size(); i++) {

        //Generate Random Index
        size_t randomIndex = std::rand() % elements.size();

        //Check to see if the current element does not match the random element
        if (elements[i] != elements[randomIndex]) {
            //swap elements
            std::swap(elements.at(randomIndex), elements[i]);
        }
    }
    return elements;
}

#endif //RAND_FISHERYATES_H
