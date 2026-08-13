#include "aluno.h"

class Hash{
    public:
        Hash(int max_items = 100);
        ~Hash(); // Destrutor
        bool isFull() const; // Verifica se a tabela está cheia
        int getLength() const; // Retorna o tamanho da tabela

        void retrieveItem(Aluno& aluno, bool& found); // Recupera um aluno da tabela
        void insertItem(Aluno aluno); // Insere um aluno na tabela
        void deleteItem(Aluno aluno); // Remove um aluno da tabela
        void print() const; // Imprime
    private:
        int getHash(Aluno aluno) const; // Retorna o índice do aluno na tabela
        int max_items; // Número máximo de itens na tabela
        int length; // Tamanho da tabela
        Aluno* structure; // Tabela de alunos em vetor 


};