#include <iostream>
#include <cstddef>
using namespace std;

int main() {
    int variavel;
    int* ponteiro1;
    variavel = 5;
    ponteiro1 = &variavel;

    cout << "Valor da variavel: " << variavel << endl;
    cout << "Endereco armazenado no ponteiro: " << ponteiro1 << endl;
    cout << "Valor da variavel, atraves do ponteiro: " << *ponteiro1 << endl;

    int variavel2;
    variavel2 = *ponteiro1;
    cout << "O valor da variavel 2 recebe o valor da variavel 1 atraves do ponteiro: " << variavel2 << endl;

    // //Vamos mudar o valor da variavel 1 atraves do ponteiro. 
    // *ponteiro1 = 10;
    // cout << variavel << endl;

    // variavel2 = 50;
    // ponteiro1 = &variavel2;
    // cout << "O valor da variavel 1: " << variavel << endl;
    // cout << "O valor da variavel 2: " << variavel2 << endl;
    // cout << "O endereco armazenado no ponteiro: " << ponteiro1 << endl;

    // int* ponteiro2 =  NULL;
    // cout << ponteiro2 << endl;
    // cout << *ponteiro2 << endl;

    int* ponteiro3 = new int; // faz o ponteiro apontar para um espaço na memoria que cabe um inteiro. Para acessar esse espaço, precisamos usar o ponteiro3, ja que não tem uma variavel com nome. 
    *ponteiro3 = 35;

    cout << "Endereco armazenado no ponteiro3: " << ponteiro3 << endl;
    cout << "Valor armazenado no ponteiro3: " << *ponteiro3 << endl;

    
}

