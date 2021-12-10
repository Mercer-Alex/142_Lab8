//
// Created by amerc on 12/8/2021.
//

#include "Playlist.h"
#include <iostream>
#include <sstream>

Playlist::Playlist(std::string playlistName) {
    this->playlistName = playlistName;
}
void Playlist::AddSong(Song* newSong) {
    playlist.push_back(newSong);
}
void Playlist::PlayPlaylist() {
    std::cout << "Playing songs from playlist: " << playlistName << std::endl;
    for (size_t i = 0; i < playlist.size(); ++i) {
        std::cout << playlist.at(i)->GetFirstLine() << std::endl;
        playlist.at(i)->PlaySong();
    }
    std::cout << std::endl;
}
std::string Playlist::GetPlaylistName() {
    return playlistName;
}
std::string Playlist::PlaylistString() {
    std::stringstream out;
    out << playlistName;
    return out.str();
}
void Playlist::ListSong() {
    for (size_t i = 0; i < playlist.size(); ++i) {
        std::cout << i << ": " << playlist.at(i)->GetSongTitle() << std::endl;
    }
}
void Playlist::DeleteSong(int songIndex) {
    playlist.erase(playlist.begin() + songIndex);
}
