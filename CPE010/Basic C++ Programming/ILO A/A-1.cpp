#include <iostream>


void sotn(int Fnum, int Lnum);

int main(){

  int Fnum;
  int Lnum;

  std::cout << "Input first number: " << std::endl;
  std::cin >> Fnum;
  std::cout << "Input second number: " << std::endl;
  std::cin >> Lnum;

  sotn(Fnum, Lnum);
    

  return 0;
}


void sotn(int Fnum, int Lnum) {

  int Total = Fnum + Lnum;

  std::cout << "Total: "<< Total << std::endl;

}



