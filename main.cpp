#include <iostream>
#include <vector>
#include <random>
#include "FisherYates.h"
#include "Song.h"
#include "Playlist.h"

using namespace std;

long double RandomNumber() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_real_distribution<> distr(0, 1); // define the range

    return distr(eng);
}

std::vector<Playlist> arr = { {"a", {"1", "2", "3", "4"} }, {"b", {"1"} }, {"c", {"1", "2", "3"} }, {"d", {"1", "2"} } };
std::vector<Song> final_arr;

int main() {

    for (int i = 0; i < arr.size(); ++i) {
        long double song_position;

        if (arr[i].songs.size() < 2) {
            song_position = RandomNumber();

            //Create song
            Song this_song;
            this_song.artist = arr[i].artist;
            this_song.title  = arr[i].songs[0];
            this_song.position = song_position;

            //Add to Playlist
            final_arr.push_back(this_song);

        } else {
            song_position = RandomNumber() / 100;
            long double spacing = ( 100 / arr[i].songs.size() + RandomNumber() ) / 100;

            //Fisher-Yates
            std::vector<string> random_array = rand_array(arr[i].songs);

            for (int x = 0; x < arr[i].songs.size(); ++x) {
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

    std::sort(final_arr.begin(), final_arr.end(), less_than_key());

    for (int y = 0; y < final_arr.size(); ++y) {
        cout << final_arr[y].position << " " << final_arr[y].artist << final_arr[y].title << "\n";
    }

    return 0;
}
