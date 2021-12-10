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
void Song::SetTitle(std::string songTitle) {
    this->songTitle = songTitle;
}
std::string Song::GetSongTitle() {
    return songTitle;
}
void Song::AddFirstLine(std::string firstLine) {
    this->firstLine = firstLine;
}
std::string Song::GetFirstLine() {
    return firstLine;
}
void Song::PlaySong() {
    this->timesPlayed++;
}
int Song::GetTimesPlayed() {
    return timesPlayed;
}
std::string Song::ToString() {
    std::stringstream out;
    out << songTitle << ": \"" << firstLine << "\", " << timesPlayed << " play(s).";
    return out.str();
}

