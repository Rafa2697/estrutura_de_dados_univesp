#include <iostream>

using namespace std;

int main() {
    int vetor[5] = {10, 20, 30, 40, 50};

    int soma = 0;

    for (int i = 0; i < 5; i++) {
        soma += vetor[i];
    }

    cout << "A soma dos elementos do vetor é: " << soma << endl;

    return 0;

}