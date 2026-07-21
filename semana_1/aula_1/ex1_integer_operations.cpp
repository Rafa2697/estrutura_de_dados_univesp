#include <iostream>

int main() {
  int number1;
  int number2;

  std::cout << "Digite o primeiro número: "; //std::cout é o objeto de saída padrão. Ele é usado para imprimir informações na tela.
  std::cin >> number1; // std::cin é o objeto de entrada padrão. Ele é usado para ler informações da entrada padrão (teclado). Seria o rquivalente ao input() do Python. O operador >> é o operador de extração. Ele é usado para extrair informações do objeto de entrada padrão.
  std::cout << "Digite o segundo número: ";
  std::cin >> number2;

  int   sum  = number1 + number2;
  int   sub  = number1 - number2;
  int   mul  = number1 * number2;
  int   div  = number1 / number2;
  float fdiv = (float)number1 / (float)number2;
  int   res  = number1 % number2;

  std::cout << "Soma:            " << sum << std::endl;
  std::cout << "Subtração:       " << sub << std::endl;
  std::cout << "Multiplicação:   " << mul << std::endl;
  std::cout << "Divisão Inteira: " << div << std::endl;
  std::cout << "Divisão Real:    " << fdiv << std::endl;
  std::cout << "Resto:           " << res << std::endl;

  return 0;
}
