//
// Created by amerc on 12/8/2021.
//

#ifndef INC_142_LAB8_PLAYLIST_H
#define INC_142_LAB8_PLAYLIST_H
#include "Song.h"


class Playlist {
private:
    std::string playlistName;
    std::vector<Song*> playlist;
public:
    Playlist(std::string playlistName = "none");
    void AddSong(Song* newSong);
    void PlayPlaylist();
    std::string GetPlaylistName();
    std::string PlaylistString();
    void ListSong();
    void DeleteSong(int songIndex);
};


#endif //INC_142_LAB8_PLAYLIST_H
