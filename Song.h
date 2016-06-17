//
// Created by Daniel Cherubini on 17/06/2016.
//

#ifndef RAND_SONG_H
#define RAND_SONG_H

#include <iostream>

using namespace std;

class Song {
public:
    string artist;
    string title;
    long double position;
};

struct less_than_key
{
    inline bool operator() (const Song& struct1, const Song& struct2)
    {
        return (struct1.position < struct2.position);
    }
};


#endif //RAND_SONG_H
