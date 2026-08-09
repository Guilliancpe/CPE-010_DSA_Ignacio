#include <iostream>
#include "queuell.h"

int main(){
    

    qnode<char>* front = nullptr;
    qnode<char>* back = nullptr;

    enqueue(&front, &back, 'G');
    std::cout << front->data << " " << back->data << std::endl;
    enqueue(&front, &back, 'U');
    std::cout << front->data << " " << back->data << std::endl;
    enqueue(&front, &back, 'I');
    std::cout << front->data << " " << back->data << std::endl;
    enqueue(&front, &back, 'L');
    std::cout << front->data << " " << back->data << std::endl;
    enqueue(&front, &back, 'L');
    std::cout << front->data << " " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data << std::endl;

    frontvar(&front);
    Display(&front, &back);
    


    return 0;
}