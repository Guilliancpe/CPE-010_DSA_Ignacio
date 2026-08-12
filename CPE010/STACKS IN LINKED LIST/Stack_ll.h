#ifndef STACK_LL_H
#define STACK_LL_H

#include <iostream>

template <typename T>
class Sllnodes {
public:
    T data;
    Sllnodes<T>* next;

    Sllnodes() {
        next = nullptr;
    }
};

// Create a new node
template <typename T>
Sllnodes<T>* new_Node(T newData) {
    Sllnodes<T>* newNode = new Sllnodes<T>;

    newNode->data = newData;
    newNode->next = nullptr;

    return newNode;
}

// Head of the stack
template <typename T>
Sllnodes<T>* head = nullptr;

// Push
template <typename T>
void push(T newData) {
    Sllnodes<T>* newNode = new Sllnodes<T>;

    newNode->data = newData;

    // New node points to current top
    newNode->next = head<T>;

    // New node becomes the top
    head<T> = newNode;
}

// Pop
template <typename T>
T pop() {

    if (head<T> == nullptr) {
        std::cout << "Stack underflow." << std::endl;
        return T();
    }

    // Save current top node
    Sllnodes<T>* temp = head<T>;

    // Store its data
    T tempVal = temp->data;

    // Move head to next node
    head<T> = head<T>->next;

    // Delete removed node
    delete temp;

    // Return removed value
    return tempVal;
}

// Is Empty
template <typename T>
bool IsEmpty() {
    return head<T> == nullptr;
}

// Top
template <typename T>
void top() {

    if (head<T> == nullptr) {
        std::cout << "Stack underflow." << std::endl;
        return;
    }

    std::cout << "The element at the top of the stack is: "
              << head<T>->data << std::endl;
}

#endif