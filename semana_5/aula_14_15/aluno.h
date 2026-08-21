#include <iostream>
using namespace std;

class Aluno {
    private:
        int ra;
        std::string nome;

    public:
        Aluno(); // Construtor padrão
        Aluno(int ra, std::string nome);
        string getNome() const;
        int getRa() const;
};