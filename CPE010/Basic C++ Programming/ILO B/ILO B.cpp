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

	
};

int main(){
	
	double A, B, C;
	
	std::cout << "Input first side value" << std::endl;
	std::cin >> A;
	
	std::cout << "Input second side value" << std::endl;
	std::cin >> B;
	
	std::cout << "Input Thirs side value" << std::endl;
	std::cin >> C;
	
	

	


Triangle set1(A, B, C);
 if(set1.validateTriangle()){
     std::cout << "The shape is a valid triangle.\n";
}  
 else {
     std::cout << "The shape is NOT a valid triangle.\n";
}


	return 0;
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


