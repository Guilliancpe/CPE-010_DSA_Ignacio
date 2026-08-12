#include <iostream>
#include <utility>


int main(){
	
	int a;
	int b;
	
	std::cout << "Input first number" << std::endl;
	std::cin >> a;
	
	std::cout << "Input second number" << std::endl;
	std::cin >> b;
	
	std::swap(a, b);
	std::cout << std::endl;
	
	std::cout << "First number: " << a <<std::endl << "Second number: " << b << std::endl;
		
	
	return 0;
}


