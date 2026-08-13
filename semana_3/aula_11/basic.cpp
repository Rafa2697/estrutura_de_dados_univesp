#include "hash.h"
#include <iostream>
using namespace std;


Hash::Hash(int max) {
    length = 0;
    max_items = max;
    structure = new Aluno[max_items]; // Aloca dinamicamente a tabela de alunos
}

Hash::~Hash() {
    delete[] structure; // Libera a memória alocada para a tabela de alunos
}

bool Hash::isFull() const {
    return (length == max_items); // Retorna true se a tabela estiver cheia, caso contrário, retorna false
}

int Hash::getLength() const { return length; } // Retorna o tamanho atual da tabela

void Hash::retrieveItem(Aluno& aluno, bool& found) {
    int location = getHash(aluno); // Obtém o índice do aluno na tabela
    Aluno aux = structure[location]; // busca o aluno na tabela
    if (aluno.getRa() != aux.getRa()){
        found = false; // Se o RA do aluno não for encontrado, define found como false
    } else {
        found = true; // Se o RA do aluno for encontrado, define found como true
        aluno = aux; // Atribui o aluno encontrado ao parâmetro aluno
    }
}

void Hash::insertItem(Aluno aluno) {
    int location = getHash(aluno); // Obtém o índice do aluno na tabela
    structure[location] = aluno; // Insere o aluno na tabela
    length++; // Incrementa o tamanho da tabela
}

void Hash::deleteItem(Aluno aluno) {
    int location = getHash(aluno); // Obtém o índice do aluno na tabela
    structure[location] = Aluno(); // Remove o aluno da tabela, substituindo-o por um objeto Aluno vazio
    length--; // Decrementa o tamanho da tabela
}

void Hash::print() const {
    for (int i = 0; i < max_items; i++) {
        cout << i << ":" <<
            structure[i].getRa() << ", " <<
            structure[i].getNome() << endl; // Imprime o índice, RA e nome de cada aluno na tabela
    }
}

int Hash::getHash(Aluno aluno) const {
    return aluno.getRa() % max_items; // Retorna o índice do aluno na tabela usando o RA como chave
}