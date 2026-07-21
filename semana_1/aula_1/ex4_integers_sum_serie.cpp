#include <iostream>

using namespace std; //usando o namespace std, nao preciso mais usar std::cout, std::endl, etc.

int main() {
  int total;

  for (int number = 2; number <= 20; number += 2) // Loop to sum even numbers from 2 to 20
    total += number;

  cout << "A soma da serie e " << total << endl;
 
  return 0;
}
