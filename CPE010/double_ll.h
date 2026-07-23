#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H


template <typename T>
class doublelist{
    public:
        T data;
        doublelist<T>* next = nullptr;
        doublelist<T>* prev = nullptr;
};

// ---------------
// Creating a node
// ---------------

template <typename T>
doublelist<T>* new_Node(T newData){
	// Dynamic Allocation for a new node
	doublelist<T>* newNode = new doublelist<T>;
	
	//store the data in a new node
	newNode->data = newData;
	
	//since its a new node point it to null
	newNode->next = nullptr;
	newNode->prev = nullptr;
	
	return newNode;
};

//-----------
//TRAVERSAL
//-----------

template <typename T>
void dllTraverse(doublelist<T>* currentNode){
  doublelist<T>* tail = nullptr; 
	//TRAVERSAL TO THE END
	while (currentNode != NULL){
        //prints the data
		std::cout << currentNode->data << " ";
        //saves the current node as the last visited node
		tail = currentNode;
        //move to the next node
            currentNode = currentNode->next;
        }
	
	
	        //REVERSE TRAVERSAL
    std::cout << "\nReverse Traversal: " << std::endl;
    while(tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
	
	
}


//---------------------
//INSERTION AT THE HEAD
//---------------------


template <typename T>
void dllInsertHead(T newData, doublelist<T>** currentHead){
    
    //creates a new node
    doublelist<T>* newNode = new_Node(newData);

    //point to the current head
    newNode->next = *currentHead;

    //current head will be pointed to a new node
    (*currentHead)->prev = newNode;

    //update head pointer
    *currentHead = newNode;

}



//-------------------
//GENERAL INSERTION
//-------------------

template <typename T>
void dllGeneralInsertion(T newData, doublelist<T>* prev){
    

    //NODE ALLOCATION
    doublelist<T>* newNode = new_Node(newData);
    //store data inside new node
    newNode->data = newData;
    //connecting new node to the next node
    newNode->next = prev->next;
    //connecting new node to prev
    newNode->prev = prev;

    //Connect the next node back to newNode
      if (prev->next != nullptr) {
        prev->next->prev = newNode;
    }
    //Connect prev to newNode
     prev->next = newNode;
}


//------------------
//INSERT AT THE END
//------------------
template <typename T>
void dllInsertEnd(T newData, doublelist<T>* currenthead){

    //Create a new node
    doublelist<T>* newNode = new_Node(newData);

    //Traverse until the last nod
    while(currenthead->next != nullptr){
        currenthead = currenthead->next;
    }

    currenthead->next = newNode;
    newNode->prev = currenthead;


}


//---------
//DELETION
//---------

template <typename T>
void dllDelete(T findData, doublelist<T>** currentHead) {

    // Check if the list is empty
    if (*currentHead == nullptr) {
        return;
    }

    // Start at the head
    doublelist<T>* currentNode = *currentHead;

    // Find the node
    while (currentNode != nullptr && currentNode->data != findData) {
        currentNode = currentNode->next;
    }

    // Data not found
    if (currentNode == nullptr) {
        return;
    }

    // If deleting the head
    if (currentNode == *currentHead) {

        // Move head to the next node
        *currentHead = currentNode->next;

        // New head has no previous node
        if (*currentHead != nullptr) {
            (*currentHead)->prev = nullptr;
        }
    }
    else {

        // Previous node points to the next node
        currentNode->prev->next = currentNode->next;

        // Next node points back to the previous node
        if (currentNode->next != nullptr) {
            currentNode->next->prev = currentNode->prev;
        }
    }

    // Remove current node from memory
    delete currentNode;
}


#endif