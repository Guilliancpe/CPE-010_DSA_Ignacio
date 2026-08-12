#include <iostream>

//Create a function that will return whether variable A is greater than variable B.

void greater(int a, int b);


int main(){
    int a;
    int b;

    std::cout << "Input First Number: " << std::endl;
    std::cin >> a;
    std::cout << "Input second Number: "<< std::endl;
    std::cin >> b;


    greater(a,b);

    return 0;
}

void greater(int a, int b){

    if (a > b) {

      std::cout << "A is greater than B";
    
    } 
    else {
        std::cout << "A is not greater than B";
    }

}