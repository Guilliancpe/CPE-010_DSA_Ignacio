#include <iostream>


//Create a function that will take two Boolean values and display the result of all logical operations then
//return true if it was a success.
void AND(bool a, bool b);
void OR(bool a, bool b);
void NOT(bool a);


int main(){

    bool a;
    bool b;

    std::cout << "Input 1 or 0" << std::endl;
    std::cin >> a;
    std::cout << "Input 1 or 0" << std::endl;
    std::cin >> b;

    AND(a,b);
    std::cout << std::endl;
    OR(a,b);
    std::cout << std::endl;
    NOT(a);
  


    return 0;
}

void AND(bool a, bool b){

    if (a && b) {
        std::cout << "AND: True";
    }
    else{
        std::cout << "AND: False";
    }
}
void OR(bool a, bool b){

    if (a || b) {
        std::cout << "OR: True";
    }
    else{
        std::cout << "OR: False";
    }
}
void NOT(bool a){

    if (!a) {
        std::cout << "NOT: True";
    }
    else{
        std::cout << "NOT: False";
    }


}
