//
// Created by amerc on 12/8/2021.
//

#ifndef INC_142_LAB8_SONG_H
#define INC_142_LAB8_SONG_H
#include <vector>
#include <string>

class Song {
private:
    std::string songTitle;
    std::string firstLine;
    int timesPlayed;
    std::vector<Song*> songs;
public:
    Song(std::string songTitle = "none", std::string firstLine = "none", int timesPlayed = 0);
    void AddSong(std::string songTitle);
    std::string GetSongTitle();
    void AddFirstLine(std::string songFirstLine);
   std::string GetFirstLine();
    void NumTimesPlayed(int timesPlayed);
    int GetTimesPlayed();
    void ListSongs();
};


#endif //INC_142_LAB8_SONG_H
