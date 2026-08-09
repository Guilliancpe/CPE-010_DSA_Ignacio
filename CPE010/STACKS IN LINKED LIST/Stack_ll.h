#ifndef STACK_LL_H
#define STACK_LL_H

template <typename T>
class Sllnodes {
    public:
    T data;
    Sllnodes<T>* next = nullptr;
};

template <typename T>
Sllnodes<T>* new_Node(T newData){
    //Dynamic allocation for a new node
    Sllnodes<T>* newNode = new Sllnodes<T>;
    newNode->data = newData;

    //Point it to null after
    newNode->next = nullptr;
    return newNode;
}


template <typename T>
Sllnodes<T>* head = nullptr;

//push
template <typename T>
void push(T newData){
  Sllnodes<T>* newNode = new Sllnodes<T>;


   newNode->data = newData;

   //points to the current top and becomes the new top
   newNode->next = head<T>;
   head<T> = newNode;
}

//pop
template <typename T>
T pop(){


    if(head<T> == nullptr){
        std::cout << "Stack undeflow.";
    }
    //save the current top node
    Sllnodes<T>* temp = head<T>;
    //store its data
    T tempVal = temp->data;
    //move the head to the next node
    head<T> = head<T>->next;
    //free the removed data
    delete temp;
    //return the removed value
    return tempVal;

};

//isEmpty
template <typename T>
bool IsEmpty(){
    return head<T> == nullptr;

};

//top
template <typename T>
void top(){
    //Create an error catching
    if (head<T> == nullptr){
        std::cout << "Stack underflow.";
        return;
    }

    std::cout << "\n The element at the top of the stack is \n" << head<T>->data << std::endl;
};



#endif
