#include <iostream>
#include <string.h>
#include "S_double_ll.h"


int main (){

    music_playlist<std::string>* head = nullptr;
    int choice;

            do {
                std::cout << "\n===== MUSIC PLAYLIST =====\n";
                std::cout << "1. Add Song\n";
                std::cout << "2. Play All Songs\n";
                std::cout << "3. Next Song\n";
                std::cout << "4. Previous Song\n";
                std::cout << "5. Remove Song\n";
                std::cout << "6. Exit\n";
                std::cout << "Enter choice: ";
                std::cin >> choice;
                std::cin.ignore();

                switch (choice) {

                    case 1:
                    {
                        std::string song;

                        std::cout << "Enter new music: ";
                        std::getline(std::cin, song);

                        addmusic<std::string>(song, &head);

                        break;
                    }

                    case 2:
                    {

                        std::cout << "\nPlaylist:\n";

                        play_all_music(head);

                        break;
                    }

                    case 3:
                    {
                        next_music(head);
                        break;
                    }

                    case 4:
                    {
                        prev_music(head);
                        break;
                    }

                    case 5:
                    {
                        int number;

                        std::cout << "Enter a song number to remove: ";
                        std::cin >> number;

                        Del_music(number, &head);
                        
                        break;
                    }

                    case 6:
                    {
                        std::cout << "Exiting Playlist...\n";
                        break;
                    }

                    default:
                    {
                        std::cout << "Invalid choice.\n";
                    }
                 
                }
            } while (choice != 6);
    return 0;
}
