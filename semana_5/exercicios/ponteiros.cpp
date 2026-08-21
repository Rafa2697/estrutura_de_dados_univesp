using namespace std;
#include <iostream>

int main() {

    int a = 10;
    int b = 20;

    cout <<"valor de a: " << a;
    cout <<"\nvalor de b: " << b;

    cout << "endereco na memoria de a: " << &a << endl;
    cout << "endereco na memoria de b: " << &b << endl;

    int *ponteiroA = &a;
    int *enderecoA = &a;
    cout << " valor de a atraves do ponteiro: " << *ponteiroA << endl;
    cout << " endereco de a: " << enderecoA << endl;

}