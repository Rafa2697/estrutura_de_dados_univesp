#include <iostream>
#include "hash.h"

using namespace std;

int main()
{
    Hash alunosHash(10); // Cria uma tabela hash com capacidade para 10 alunos

    int ras[7] = {
        12704, 31300, 1234,
        49001, 52202, 65606,
        91234};
    string nomes[7] = {
        "Pedro", "Raul", "Paulo",
        "Carlos", "Lucas", "Maria",
        "Samanta"};

    for (int i = 0; i < 7; i++){
        Aluno aluno = Aluno(ras[i], nomes[i]); // Cria um objeto Aluno com RA e nome
        alunosHash.insertItem(aluno); // Insere o aluno na tabela hash
    }

    alunosHash.print(); // Imprime a tabela hash
    cout << "------------------------------" << endl;

    Aluno aluno(12704, ""); // Cria um objeto Aluno com RA 12704 e nome vazio
    bool found = false; // Variável para verificar se o aluno foi encontrado
    alunosHash.retrieveItem(aluno, found); // Busca o aluno na tabela hash
    if (found) {
        cout << "Aluno encontrado: " << aluno.getNome() << endl;
    } else {
        cout << "Aluno nao encontrado." << endl;
    }

    cout << "------------------------------" << endl;
    alunosHash.deleteItem(aluno); // Remove o aluno da tabela hash
    alunosHash.print(); // Imprime a tabela hash após a remoção
    cout << "Fim" << endl;
}