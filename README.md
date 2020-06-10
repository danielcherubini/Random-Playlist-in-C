# Random Playlist in C++

https://labs.spotify.com/2014/02/28/how-to-shuffle-songs/

Basically what this does is shuffle a playlist, or anything like a playlist.

So assuming you have a playlist of music,

10 songs by artist foo
5 songs by artist bar
20 songs by artist qux

Most shuffle algorithms work with Fisher-Yates, which is just going to randomise the list, so you might have like 2+ songs by the same artist in a row.

What this is, is a proof of concept for shuffling so that NONE of the artists are next to eachother, curated randomness.

It will split everything up by artist, then randomly assign a number between each, and plot on a line, then place into an array based on distance between eachother making sure not to place the same artist next to eachother.

