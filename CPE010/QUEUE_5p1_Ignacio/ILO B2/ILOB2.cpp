#include <iostream>
#include "queuell.h"
#include "QueueArr.h"

int main() {

    //create an object
    Qarr<int> q(6);
    q.enqueue(1);
    std::cout << "Front: " << q.Front() << "\n" << "Back: " << q.Back()<< "\n" << "Size: " << q.size() << "\n";
    q.enqueue(2);
    q.enqueue(3);
    std::cout << "Front: " << q.Front() << "\n" << "Back: " << q.Back()<< "\n" << "Size: " << q.size();
    q.enqueue(4);
    std::cout << "Front: " << q.Front() << "\n" << "Back: " << q.Back()<< "\n" << "Size: " << q.size();
    q.enqueue(5);
    std::cout << "Front: " << q.Front() << "\n" << "Back: " << q.Back()<< "\n" << "Size: " << q.size();
    q.enqueue(6);
    std::cout << "Front: " << q.Front() << "\n" << "Back: " << q.Back()<< "\n" << "Size: " << q.size();
    q.enqueue(7);
    std::cout << "Front: " << q.Front() << "\n" << "Back: " << q.Back()<< "\n" << "Size: " << q.size();
    q.dequeue();
    std::cout << "Front: " << q.Front() << "\n" << "Back: " << q.Back()<< "\n" << "Size: " << q.size();

    return 0;
}