#include <iostream> 
#include <string.h>

class Student{
private:
  std::string studentName;
  int studentAge;
public:
 //constructor
 Student(std::string newName = "John Doe", int newAge=18) {
  studentName = std::move(newName);
  studentAge = newAge;
  std::cout << "Constructor called." << std::endl;
 }

 //Deconstructor
 ~Student (){
  std::cout << "Deconstructor Called." << std::endl;
 }

 //Copy Constructor
 Student(const Student& copyStudent){
  studentName = copyStudent.studentName;
  studentAge = copyStudent.studentAge;
  std::cout << "Copy Constructor Called" << std::endl;
 }

 //Display Attributes
 void printDetails(){
  std::cout << this->studentName << " " << this->studentAge << std::endl;

 }


 
};

int main(){

  Student s1("Roman", 28);
  Student s2(s1);
  Student s3;
  s3=s2;

  s1.printDetails();
  s2.printDetails();
  s3.printDetails();

 const size_t j = 5;

 Student studentList [j] = {};
 std::string nameList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
 int ageList[j] = {15, 16, 18, 19, 16};

 for(int i = 0; i < j; i++){ //loop A
    Student *ptr = new Student (nameList[i], ageList[i]);
    studentList[i] = *ptr;
 } 

 for(int i = 0; i < j; i ++){ //loop B
   studentList[i].printDetails();
 }
  return 0;
}