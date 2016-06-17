#include <iostream>
#include <vector>
#include <random>
#include "FisherYates.h"
#include "Song.h"
#include "Playlist.h"

using namespace std;

//Random Number Generator
long double RandomNumber() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_real_distribution<> distr(0, 1); // define the range

    return distr(eng);
}

//Setup dummy data and variables
std::vector<Playlist> arr = { {"a", {"1", "2", "3", "4"} }, {"b", {"1"} }, {"c", {"1", "2", "3"} }, {"d", {"1", "2"} } };
std::vector<Song> final_arr;

int main() {

    //Lets get ready to rock and roll
    for (int i = 0; i < arr.size(); ++i) {
        long double song_position;

        //If there is only one song from that artist
        if (arr[i].songs.size() < 2) {
            //place single song randomly in array
            song_position = RandomNumber();

            //Create song
            Song this_song;
            this_song.artist = arr[i].artist;
            this_song.title  = arr[i].songs[0];
            this_song.position = song_position;

            //Add to Playlist
            final_arr.push_back(this_song);

        } else {
            //There are more than one songs from the artist in playlist
            //space semi randomly based on percentage
            //Spreading out evenly, and adds a slight random element to spacing
            song_position = RandomNumber() / 100;
            long double spacing = ( 100 / arr[i].songs.size() + RandomNumber() ) / 100;

            //Fisher-Yates
            std::vector<string> random_array = rand_array(arr[i].songs);

            //Repeat song in songs
            for (int x = 0; x < arr[i].songs.size(); ++x) {
                //Set the position of the song and add a little randomness to it
                song_position = (song_position + spacing);

                //Create song
                Song this_song;
                this_song.artist = arr[i].artist;
                this_song.title  = random_array[x];
                this_song.position = song_position;

                //Add to Playlist
                final_arr.push_back(this_song);
            }
        }
    }

    //Sort the array based on the position element
    std::sort(final_arr.begin(), final_arr.end(), less_than_key());

    //print it out to console
    for (int y = 0; y < final_arr.size(); ++y) {
        cout << final_arr[y].position << " " << final_arr[y].artist << final_arr[y].title << "\n";
    }

    return 0;
}
