#ifndef QUEUELL_H
#define QUEUELL_H

template <typename T>
class qnode{
    public:
        T data;
        qnode *next;

};

//creating a new node
template <typename T>
qnode<T> *new_Node(T newData){
    qnode<T>* newNode = new qnode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}


//inserting an item 
template <typename T>
void enqueue(qnode<T>** frontptr, qnode<T>** backptr, T newData){
    //create a new node
    qnode<T>* newNode = new_Node(newData);

    if ((*frontptr) == nullptr && (*backptr) == nullptr){
    //inserting to an empty queue
    (*frontptr) = newNode;
    (*backptr) = newNode;
    }

    //inserting to a non empty queue
    //POINT THE backpoint->next to the newNode
    (*backptr)->next = newNode;
    (*backptr) = newNode;
    

}


template <typename T>
void dequeue(qnode<T>** frontptr, qnode<T>** backptr){
    //create a temporary node to store the node to be deleted
    qnode<T>* deletenode = nullptr;
    deletenode = (*frontptr);
    //Check if the queue is only 1 node

    if ((*frontptr)->next == nullptr && (*backptr)->next == nullptr){
        (*frontptr) = nullptr;
        (*backptr) = nullptr;
        delete deletenode;
        return;
    }


    //deleting of the node
    (*frontptr) = deletenode->next;
    deletenode->next = nullptr;
    delete deletenode;
}

//display all elements in the list

template <typename T>
void Display(qnode<T>** frontptr, qnode<T>** backptr){
    //check if front and back is empty
    if((*frontptr) != nullptr && (*backptr) != nullptr){
        std::cout << " " <<  (*frontptr)->data << " " << (*frontptr)->next->data << " " << (*backptr)->data << std::endl;
    }


   
}

//return the front variable
template <typename T>
void frontvar(qnode<T>** frontptr){
    if((*frontptr != nullptr)){
        std::cout << " " << (*frontptr)->data << std::endl;
        return;
    }
}

#endif