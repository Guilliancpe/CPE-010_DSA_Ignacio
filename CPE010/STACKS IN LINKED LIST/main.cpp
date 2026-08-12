#include <iostream>
#include "Stack_ll.h"


int main(){

    push<int>(10);
    push<int>(20);
    push<int>(30);

    top<int>();

    std::cout << "Popped: " << pop<int>() << std::endl;

    top<int>();

    if (IsEmpty<int>()) {
        std::cout << "Stack is empty." << std::endl;
    }
    else {
        std::cout << "Stack is not empty." << std::endl;
    }


    return 0;
}