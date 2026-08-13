#include <iostream>
using namespace std;


class Aluno{
    private:
        int ra;
        std::string nome;
    public:
        Aluno(); // Construtor
        Aluno(int ra, std::string nome); // Construtor
        string getNome() const; // Retorna o nome do aluno
        int getRa() const; // Retorna o RA do aluno
};