#include <iostream>

#include <string>


 
int main() {

    int numeroFuncionarios;

    std::string nome;


    std::cout << "Informe o número de Funcionários: ";

    std::cin >> numeroFuncionarios;

    std::cin.ignore(); // Ignorar o newline deixado no buffer


    int contador = 0;

    while (contador < numeroFuncionarios) {

        std::cout << "Informe o nome do Funcionário: ";

        std::getline(std::cin, nome); // Substitui gets() e fflush(stdin)

    }    

    return 0;

}

/*
Vetores (ou arrays) são uma das estruturas de dados mais fundamentais na programação em C++. Eles permitem armazenar múltiplos valores em uma única variável, usando um índice para acessar cada valor individualmente. A posição de cada elemento no vetor é indicada por um índice numérico, começando do zero. Vetores são particularmente úteis quando você precisa armazenar uma coleção de dados e acessar esses dados de forma eficiente através de um índice. Dessa forma, os vetores são estruturas de dados [preencher 1].

Os termos [preencher 1] é corretamente substituído por:
Questão 3Resposta

A.
heterogêneas

B.
escaláveis

C.
homogêneas

D.
complexas

E.
dinâmicas
Questão 4
Completo
Atingiu 2,50 de 2,50
Marcar questão
Texto da questão
Na linguagem C++, os comandos de loop são fundamentais para a realização de tarefas repetitivas de forma eficiente. Os loops permitem que um bloco de código seja executado várias vezes, até que uma condição específica seja atendida. Existem três tipos principais de loops em C++: for, while e do-while. 

Após o contexto apresentando, observe o código a seguir:
 

#include <iostream>

#include <string>
 
int main() {

    int numeroFuncionarios;

    std::string nome;


    std::cout << "Informe o número de Funcionários: ";

    std::cin >> numeroFuncionarios;

    std::cin.ignore(); // Ignorar o newline deixado no buffer


    int contador = 0;

    while (contador < numeroFuncionarios) {

        std::cout << "Informe o nome do Funcionário: ";

        std::getline(std::cin, nome); // Substitui gets() e fflush(stdin)

    }    

    return 0;

}


Dentro do contexto apresentado, analise as afirmativas a seguir.

I. O código entrará em looping infinito.

II. Nesse caso, o correto é utilizar o looping com teste no fim.

III. Faltou incrementar o contador dentro do looping.

IV. O contador deveria ser inicializado em 1 ao invés de 0.


Está correto o que se afirma em:
Questão 4Resposta

A.
I, II, III e IV.

B.
I e III, apenas. correta

C.
I e II, apenas.

D.
I, II, III, apenas.

E.
II e III, apenas.

*/