#ifndef QUEUEARR_H
#define QUEUEARR_H
#include <iostream>
#include <cstddef>

template <typename T>
class Qarr {
    private:
        // create pointer array
        T* q_array;
        size_t q_capacity;
        size_t q_size;

        int q_front;
        int q_back;

    public:
        // Constructor
        Qarr(size_t capacity = 10);

        bool Empty();
        bool Full();

        size_t size();
        void Clear();

        T Front();
        T Back();

        void enqueue(T newData);
        void dequeue();

        // Destructor
        ~Qarr();

        // Copy Constructor
        Qarr(const Qarr& other);

        // Copy assignment operator
        Qarr& operator=(const Qarr& other);
};


// Constructor
template <typename T>
Qarr<T>::Qarr(size_t capacity) {

    q_capacity = capacity;
    q_size = 0;
    q_front = 0;
    q_back = -1;

    q_array = new T[q_capacity];
}


// Destructor
template <typename T>
Qarr<T>::~Qarr() {

    delete [] q_array;
}


// Empty
template <typename T>
bool Qarr<T>::Empty() {

    return q_size == 0;
}


// Full
template <typename T>
bool Qarr<T>::Full() {

    return q_size == q_capacity;
}


// Size
template <typename T>
size_t Qarr<T>::size() {

    return q_size;
}


// Clear
template <typename T>
void Qarr<T>::Clear() {

    q_front = 0;
    q_back = -1;
    q_size = 0;
}


// Front
template <typename T>
T Qarr<T>::Front() {

    // Check if queue is empty
    if (Empty()) {

        std::cout << "The Queue is empty\n";
        return T();
    }

    // Return front item
    return q_array[q_front];
}


// Back
template <typename T>
T Qarr<T>::Back() {

    // Check if queue is empty
    if (Empty()) {

        std::cout << "The Queue is empty\n";
        return T();
    }

    // Return back item
    return q_array[q_back];
}


// Enqueue
template <typename T>
void Qarr<T>::enqueue(T newData) {

    // Check if queue is full
    if (Full()) {

        std::cout << "The Queue is full\n";
        return;
    }

    // Move back circularly
    q_back = (q_back + 1) % q_capacity;

    // Add new value
    q_array[q_back] = newData;

    // Increase size
    q_size++;
}


// Dequeue
template <typename T>
void Qarr<T>::dequeue() {

    // Check if queue is empty
    if (Empty()) {

        std::cout << "The Queue is empty\n";
        return;
    }

    // Move front circularly
    q_front = (q_front + 1) % q_capacity;

    // Decrease size
    q_size--;
}


// Copy Constructor
template <typename T>
Qarr<T>::Qarr(const Qarr& other) {

    q_capacity = other.q_capacity;
    q_size = other.q_size;
    q_front = other.q_front;
    q_back = other.q_back;

    q_array = new T[q_capacity];

    for (size_t i = 0; i < q_capacity; i++) {

        q_array[i] = other.q_array[i];
    }
}


// Copy Assignment Operator
template <typename T>
Qarr<T>& Qarr<T>::operator=(const Qarr& other) {

    if (this != &other) {

        delete [] q_array;

        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;

        q_array = new T[q_capacity];

        for (size_t i = 0; i < q_capacity; i++) {

            q_array[i] = other.q_array[i];
        }
    }

    return *this;
}

#endif