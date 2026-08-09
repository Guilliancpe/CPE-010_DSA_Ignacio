#ifndef SUP_LL_H
#define SUP_LL_H
#include <string>

template <typename T>
class SNode{
    public:
        T data;
        SNode *next;
};


class Job{
    public:
        int id;
        int page;
        std::string name;
};

//creating a new node but reusable
template <typename T>
SNode<T> *new_Node(T newData){
    SNode<T>* newNode = new SNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

//insertion and deletion but the task said 
//to make it inside a class named printer
template <typename T>
class Printer{
    public:
        SNode<T>* frontptr;
        SNode<T>* backptr;
        
        //Set both to nullptr by using a constructor
        Printer(){
            frontptr = nullptr;
            backptr = nullptr;
        }
        
        void enqueue (SNode<T>** frontptr, SNode<T>** backptr, T newData){
            //create a new node
            SNode<T>* newNode = new_Node(newData);

            if ((*frontptr) == nullptr && (*backptr) == nullptr){
                //insert to an empty queue
                (*frontptr) = newNode;
                (*backptr) = newNode;
            }
            else {
                //inserting to a non empty queue
                //point backptr->next to the newNode
                (*backptr)->next = newNode;
                (*backptr) = newNode;
            }            
        }
    
        void dequeue(SNode<T>** frontptr, SNode<T>** backptr){

            //check if the queue is empty
            if ((*frontptr) == nullptr && (*backptr) == nullptr){
                return;
            }

            // Create a temporary node to store the node that is to 
            // be deleted
            SNode<T>* deletenode = nullptr;
            deletenode = (*frontptr);

            //check if there is only 1 node in the queue
            if ((*frontptr)->next == nullptr && (*backptr)->next == nullptr ){
                (*frontptr) = nullptr;
                (*backptr) = nullptr;
                delete deletenode;
                return;
            }

            //deletion of the node
            (*frontptr) = deletenode->next;
            deletenode->next = nullptr;
            delete deletenode;
        }
};

#endif