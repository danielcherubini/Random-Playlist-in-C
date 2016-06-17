cmake_minimum_required(VERSION 3.5)
project(rand)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp FisherYates.cpp FisherYates.h Song.cpp Song.h Playlist.cpp Playlist.h)
add_executable(rand ${SOURCE_FILES})