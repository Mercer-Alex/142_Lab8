//
// Created by amerc on 12/8/2021.
//
#include "Song.h"
#include <iostream>

Song::Song(std::string songTitle, std::string firstLine, int timesPlayed) {
    this->songTitle = songTitle;
    this->firstLine = firstLine;
    this->timesPlayed = timesPlayed;
}
void Song::AddSong(std::string songTitle) {
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
void Song::NumTimesPlayed(int timesPlayed) {
    this->timesPlayed = timesPlayed;
}
int Song::GetTimesPlayed() {
    return timesPlayed;
}
void Song::ListSongs() {
    for (unsigned int i = 0; i < songs.size(); ++i) {
        std::cout << songTitle << " " << timesPlayed;
    }

}