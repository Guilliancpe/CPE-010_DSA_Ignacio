#include <iostream>
#include "singly_ll.h"
#include "double_ll.h"



int main(){
    
    //CREATION OF NODE
    doublelist<char>* head = new_Node('C');
    
    //CREATION OF OTHER NODES
    doublelist<char>* second = new_Node('P');
    doublelist<char>* third = new_Node('E');
    
    //LINK THE NODES
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    
    std::cout <<"Initial Traversal: " << std::endl;
    dllTraverse(head);

    std::cout << "\n Insertion at the head \n";
    dllInsertHead('G', &head);
    dllTraverse(head);

    std::cout <<"\n Insertion at the end \n";
    dllInsertEnd('1', head);
    dllTraverse(head);

    std::cout << "\n General Insertion \n";
    dllGeneralInsertion('8', head->next);
    dllTraverse(head);
    
    std::cout <<"\n Delete \n";
    dllDelete('C', &head);
    dllTraverse(head);

   return 0;
}