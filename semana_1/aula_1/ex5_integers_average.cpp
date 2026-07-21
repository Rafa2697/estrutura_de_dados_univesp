 #include <iostream>

using namespace std;

int main() {
  int count = 0;
  int number;
  int sum = 0;
  
  do {
    cout << "digite um numero: " << endl;
    cin >> number;

    sum += number;
    count++;
  } while (number != 0);

  if (count <= 1) {
    cout << "Nenhum numero valido foi digitado." << endl;
  } else {
    float media = (float)sum / (float)(count - 1);
    cout << "A media dos numeros digitados e: " << media << endl;
  }
 
  return 0;
}