#ifndef S_DOUBLE_LL_H
#define S_DOUBLE_LL_H



// This is a blue print for the a song
template <typename T>
class music_playlist{
    public:
        T data;
        music_playlist<T>* next; // for storing the address of the next song
        music_playlist<T>* prev; // for storing the address of the prev song
};


// Creating nodes

template <typename T>
music_playlist<T>* new_Node(T newData){
    //Dynamic allocation for a new node
    music_playlist<T>* newNode = new music_playlist<T>;

    //store the music in a new node
    newNode->data = newData;

    //Point it to null after
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    return newNode;
}


// MUSIC INSERTION
template <typename T>
void addmusic(T newData, music_playlist<T>** currenthead){

    //create a new node
    music_playlist<T>* newNode = new_Node(newData);

    //If playlist is empty
    if(*currenthead == nullptr){

        //if its the first song it needs to point back to itself
        newNode->next = newNode;
        newNode->prev = newNode;

        *currenthead = newNode;
        return;

    }

    //Get the last node
    music_playlist<T>* tail = (*currenthead)->prev;

    //connect to a new node
    newNode->next = *currenthead;
    newNode->prev = tail;

    //connect last node to a new node
    tail->next = newNode;

    //current head will be pointed to a new node
    (*currenthead)->prev = newNode;

    //update head pointer
    *currenthead = newNode;

};


//Next song

template <typename T>
void next_music(music_playlist<T>*& currentnode){

    // Checks if playlist is empty
    if (currentnode == nullptr){

        std::cout << "Playlist is empty. \n";
        return;

    }

    currentnode = currentnode->next; 

    std::cout << "Currently Playing: " << currentnode->data << "\n";


};

// Previous 
template <typename T>
void prev_music(music_playlist<T>*& currentnode){

    if (currentnode == nullptr){
        std::cout << "Playlist is empty. \n";
        return;
    }

    currentnode = currentnode->prev;

    std::cout << "Currently Playing: " << currentnode->data << "\n";
};


// Play all songs 
template <typename T>
void play_all_music(music_playlist<T>* currentnode){


    if (currentnode == nullptr){

        std::cout << "Playlist is empty. \n";
        return;

    }

    music_playlist<T>* start = currentnode;
    int song = 1;

    do {
        std::cout << song << "." << currentnode-> data << "\n";

        song++;
        currentnode = currentnode->next;

    } while (currentnode != start);
};

template <typename T>
void Del_music(int pos, music_playlist<T>** currenthead){

    if (currenthead == nullptr){

        std::cout << "Playlist is empty.";
        return;
    }

    music_playlist<T>* currentnode = *currenthead;

    //move to the selected position
    for(int i = 1; i < pos; i++){
        currentnode = currentnode->next;
    }

    //if there is only one song
    if(currentnode->next == currentnode){

        currenthead = nullptr;
        delete currentnode;
        return;
    }

    //connect the prev and next nodes
    currentnode->prev->next = currentnode->next;
    currentnode->next->prev = currentnode->prev;

    //removing the head
    if (currentnode == *currenthead){
        *currenthead = currentnode->next;
    }

    delete currentnode;
};




#endif