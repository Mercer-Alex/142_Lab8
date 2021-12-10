//
// Created by amerc on 12/8/2021.
//

#include "Playlist.h"
#include <iostream>
#include <sstream>

Playlist::Playlist(std::string playlistName) {
    this->playlistName = playlistName;
}
void Playlist::AddSong(Song *) {

}
void Playlist::PlayPlaylist() {

}
std::string Playlist::GetPlaylistName() {
    return playlistName;
}
std::string Playlist::PlaylistString() {
    std::stringstream out;
    out << playlistName;
    return out.str();
}
