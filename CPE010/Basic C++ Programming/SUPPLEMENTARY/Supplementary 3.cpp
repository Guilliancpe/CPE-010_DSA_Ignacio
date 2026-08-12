#include <iostream>
#include <cmath>

void Distance(double a, double b, double c, double d);

int main(){
	int a;
	int b;
	int c;
	int d;
	
	
	std::cout << "Input value of x1: " << std::endl;
	std::cin >> a;
	
	std::cout << "Input value of x2: " << std::endl;
	std::cin >> b;
	
	std::cout << "Input value of y1: " << std::endl;
	std::cin >> c;
	
	std::cout << "Input value of y2: " << std::endl;
	std::cin >> d;
	
	Distance(a, b, c, d);
	
	
	return 0;
}

void Distance(double a, double b, double c, double d){
	

	
	double x = b - a;
	double y = d - c;
	
	double distance = std::sqrt((x * x) + (y * y));
	
	std::cout << "The Distance is: " << distance;
	
	
	
}
