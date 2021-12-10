//A Note regarding 'using namespace std':
// The author of this code prefers to not have the line 'using namespace std;'
// Instead, you will see 'std::' in front of string, cout, and other identifiers
// You could put 'using namespace std;' at the top of your code and not need 'std::' in front of these words,
// but many people consider it better practice to not have 'using namespace std;'


#include <iostream>
#include <string>
#include <vector>
#include "Playlist.h"
#include "Song.h"


// TODO: clean up memory when it is no longer used
//  (you need to find the appropriate places in the code to do this)

std::string GetUserString(const std::string& prompt);
int GetUserInt(const std::string& prompt);


int main() {
    std::cout << "Welcome to the Firstline Player!  Enter options to see menu options." << std::endl << std::endl;

    std::vector<Playlist> userPlaylist;
    std::vector<Song*> userSongs;


    std::string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {
        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {
            const std::string DONE_KEYWORD = "DONE";
            std::cout << "Enter songs' names and first lines"
                      << " (type \"" << DONE_KEYWORD << "\" when done):" << std::endl;

            std::string songName = "none";
            std::string firstLine = "none";

            songName = GetUserString("Song Name: ");
            while (songName != DONE_KEYWORD) {
                firstLine = GetUserString("Song's first line: ");
                userSongs.push_back(new Song(songName, firstLine));

                songName = GetUserString("Song Name: ");
            }
            std::cout << std::endl;
        }
        else if (userMenuChoice == "list") {
            for (size_t i = 0; i < userSongs.size(); ++i) {
                std::cout << userSongs.at(i)->ToString();
                std::cout << std::endl;
            }
        }
        else if (userMenuChoice == "addp") {
            std::string playlistName = "none";
            playlistName = GetUserString("Playlist name: ");
            userPlaylist.push_back(Playlist(playlistName));
            std::cout << std::endl;
        }
        else if (userMenuChoice == "addsp") {
            int playlistIndex = 0;
            int songIndex = 0;

            for (size_t i = 0; i < userPlaylist.size(); ++i) {
                std::cout << i << ": ";
                std::cout << userPlaylist.at(i).PlaylistString();
                std::cout << std::endl;
            }
            std::cout << "Pick a playlist index number: ";
            std::cin >> playlistIndex;
            std::cin.ignore();

            for (size_t i = 0; i < userSongs.size(); ++i) {
                std::cout << i << ": ";
                std::cout << userSongs.at(i)->GetSongTitle() << std::endl;
            }
            std::cout << "Pick a song index number: ";
            std::cin >> songIndex;
            std::cin.ignore();

            userPlaylist.at(playlistIndex).AddSong(userSongs.at(songIndex));
        }
        else if (userMenuChoice == "listp") {
            for (size_t i = 0; i < userPlaylist.size(); ++i) {
                std::cout << i << ": ";
                std::cout << userPlaylist.at(i).PlaylistString();
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
        else if (userMenuChoice == "play") {
            int playlistIndex = 0;

            std::cout << std::endl << "Pick a playlist index number: ";
            std::cin >> playlistIndex;
            std::cin.ignore();

            userPlaylist.at(playlistIndex).PlayPlaylist();
        }
        else if (userMenuChoice == "remp") {
            int playlistIndex = 0;
            for (size_t i = 0; i < userPlaylist.size(); ++i) {
                std::cout << i << ": ";
                std::cout << userPlaylist.at(i).PlaylistString();
                std::cout << std::endl;
            }
            std::cout << "Pick a playlist index number to remove: ";
            std::cin >> playlistIndex;
            std::cin.ignore();

            userPlaylist.erase(userPlaylist.begin() + playlistIndex);
        }
        else if (userMenuChoice == "remsp") {
            int playlistIndex = 0;
            int songIndex = 0;
            for (size_t i = 0; i < userPlaylist.size(); ++i) {
                std::cout << i << ": ";
                std::cout << userPlaylist.at(i).PlaylistString();
                std::cout << std::endl;
            }
            std::cout << "Pick a playlist index number: ";
            std::cin >> playlistIndex;
            std::cin.ignore();

            userPlaylist.at(playlistIndex).ListSong();
            std::cout << "Pick a song index number to remove: ";
            std::cin >> songIndex;
            std::cin.ignore();

            userPlaylist.at(playlistIndex).DeleteSong(songIndex);
        }
        else if (userMenuChoice == "remsl") {


            //TODO: Implement this menu option
        }
        else if (userMenuChoice == "options") {
            std::cout << "add      Adds a list of songs to the library" << std::endl
                      << "list     Lists all the songs in the library" << std::endl
                      << "addp     Adds a new playlist" << std::endl
                      << "addsp    Adds a song to a playlist" << std::endl
                      << "listp    Lists all the playlists" << std::endl
                      << "play     Plays a playlist" << std::endl
                      << "remp     Removes a playlist" << std::endl
                      << "remsp    Removes a song from a playlist" << std::endl
                      << "remsl    Removes a song from the library (and all playlists)" << std::endl
                      << "options  Prints this options menu" << std::endl
                      << "quit     Quits the program" << std::endl << std::endl;
        }
        else if (userMenuChoice == "quit") {
            for (size_t i = 0; i < userSongs.size(); ++i) {
                delete(userSongs.at(i));
            }
            std::cout << "Goodbye!" << std::endl;
            continueMenuLoop = false;
        }
        else {
            std::cout << "add      Adds a list of songs to the library" << std::endl
                      << "list     Lists all the songs in the library" << std::endl
                      << "addp     Adds a new playlist" << std::endl
                      << "addsp    Adds a song to a playlist" << std::endl
                      << "listp    Lists all the playlists" << std::endl
                      << "play     Plays a playlist" << std::endl
                      << "remp     Removes a playlist" << std::endl
                      << "remsp    Removes a song from a playlist" << std::endl
                      << "remsl    Removes a song from the library (and all playlists)" << std::endl
                      << "options  Prints this options menu" << std::endl
                      << "quit     Quits the program" << std::endl << std::endl;
        }
    }

    return 0;
}

std::string GetUserString(const std::string& prompt) {
    std::string userAnswer = "none";

    std::cout << prompt;
    std::getline(std::cin, userAnswer);
    std::cout << std::endl;
    return userAnswer;
}
int GetUserInt(const std::string& prompt) {
    int userAnswer = 0;

    std::cout << prompt;
    std::cin >> userAnswer;
    std::cin.ignore();
    std::cout << std::endl;
    return userAnswer;
}


