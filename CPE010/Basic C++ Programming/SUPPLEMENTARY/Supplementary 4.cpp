#include <iostream>



class Triangle{
	private:
		double totalAngle, angleA, angleB, angleC;
	public:
		//constructor
		Triangle(double A, double B, double C);
		
		//Methods
		void setAngles(double A, double B, double C);
		
		//Validation
		const bool validateTriangle();

	 double Area (double base, double height);
     double Perimeter(double A, double B, double C);
     void Angle();
};



int main(){
	double base, height;
	double A, B, C;

	
	std::cout << "Input first side value" << std::endl;
	std::cin >> A;
	
	std::cout << "Input second side value" << std::endl;
	std::cin >> B;
	
	std::cout << "Input Thirs side value" << std::endl;
	std::cin >> C;
	
	std::cout << "Enter base: ";
    std::cin >> base;

    std::cout << "Enter height: ";
    std::cin >> height;

Triangle set1(A, B, C);
 if(set1.validateTriangle()){
     std::cout << "The shape is a valid triangle.\n";
}  
 else {
     std::cout << "The shape is NOT a valid triangle.\n";
}
 std::cout << std::endl;

std::cout << "Area = " << set1.Area(base, height) << std::endl;
 std::cout << std::endl;
std::cout << "Perimeter = " << set1.Perimeter(A, B, C) << std::endl;
 std::cout << std::endl;
set1.Angle();


	return 0;
}

double Triangle::Area(double base, double height){
	
	return 0.5 * base * height;
}

double Triangle::Perimeter(double A, double B, double C){
	
	return A + B + C;
}

void Triangle::Angle(){
	if(angleA < 90 && angleB < 90 && angleC < 90){
		std::cout << "Acute Triangle";
	}
	else if(angleA > 90 || angleB > 90 || angleC > 90){
		std::cout << "Obtuse Triangle";
	}
	else {
		std::cout << "Others";
	}	
	
}


Triangle::Triangle(double A, double B, double C){
	angleA = A;
	angleB = B;
	angleC = C;
	totalAngle = A+B+C;
		
}

void Triangle::setAngles(double A, double B, double C){
	angleA = A;
	angleB = B;
	angleC = C;
	totalAngle = A+B+C;
	
}
const bool Triangle::validateTriangle(){
	return (totalAngle <= 180);
}
