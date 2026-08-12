#include <iostream>

void KtF (int K);


int main(){
	
	int K;
	
	std::cout << "Kelvin value: ";
	std::cin >> K;
	
	KtF(K);
	
	
	return 0;
}

void KtF (int K){
	
	double Fahrenheit;
	
	Fahrenheit = 1.8 * (K - 273.15) + 32;
	
	std::cout << "Fahrenheit: " << Fahrenheit;
	
	
}
