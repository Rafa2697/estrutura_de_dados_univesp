#include <iostream>
using namespace std;


class Aluno{
    private:
        int ra;
        std::string nome;
    public:
        Aluno(); // Construtor sem parametros (utilizado para inicializar o RA com -1 e o nome com vazio)
        Aluno(int ra, std::string nome); // Construtor com parametros
        string getNome() const; // Retorna o nome do aluno
        int getRa() const; // Retorna o RA do aluno
};