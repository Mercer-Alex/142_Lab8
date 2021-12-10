//
// Created by amerc on 12/8/2021.
//
#include "Song.h"
#include <iostream>
#include <sstream>

Song::Song(std::string songTitle, std::string firstLine) {
    this->songTitle = songTitle;
    this->firstLine = firstLine;
    this->timesPlayed =0;
}
std::string Song::GetSongTitle() {
    return songTitle;
}
std::string Song::GetFirstLine() {
    return firstLine;
}
void Song::PlaySong() {
    this->timesPlayed++;
}
std::string Song::ToString() {
    std::stringstream out;
    out << songTitle << ": \"" << firstLine << "\", " << timesPlayed << " play(s).";
    return out.str();
}
