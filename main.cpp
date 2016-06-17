#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct Song {
public:
    string artist;
    string title;
    long double position;
};

struct Playlist {
public:
    string artist;
    std::vector<string> songs;
};

struct less_than_key
{
    inline bool operator() (const Song& struct1, const Song& struct2)
    {
        return (struct1.position < struct2.position);
    }
};

std::vector<Playlist> arr = { {"a", {"1", "2", "3", "4"} }, {"b", {"1"} }, {"c", {"1", "2", "3"} }, {"d", {"1", "2"} } };
std::vector<Song> final_arr;
std::vector<Song> sorted_arr;

long double rando() {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_real_distribution<> distr(0, 1); // define the range

    return distr(eng);
}

int main() {

    for (int i = 0; i < arr.size(); ++i) {
        long double song_position;

        if (arr[i].songs.size() < 2) {
            song_position = rando();

            Song this_song;
            this_song.artist = arr[i].artist;
            this_song.title  = arr[i].songs[0];
            this_song.position = song_position;

            final_arr.push_back(this_song);

        } else {
            song_position = rando() / 100;
            long double spacing = ( 100 / arr[i].songs.size() +rando() ) / 100;


            for (int x = 0; x < arr[i].songs.size(); ++x) {
                song_position = (song_position + spacing);

                Song this_song;
                this_song.artist = arr[i].artist;
                this_song.title  = arr[i].songs[x];
                this_song.position = song_position;

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
