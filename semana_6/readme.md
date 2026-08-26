# Anotações semana 6 (arvores AVL)

## O que é uma arvore desbalanceada. 

Quando o nó está com +2 ou -2, ele é considerado um nó desbalanceado. A arvore deve ficar no intervalo de -1 a 1 para que seja uma arvore balanceada. 
-   Um nó sem filhos ou com um filha a direita e um filho a esquerda, é um nó balanceado e portante tela valor 0.

![arvore_desbalanceada](./aula_16/image/exemplo_arvore_desbalanceada.png)

## Rotação e regras para uso das rotações

![regras para rotacao](./aula_16/image/regras%20de%20rotacao.png)

## Exemplos de rotação

![exemplos](./aula_16/image/exemplos%20de%20rotacao.png)

Os arquivos desta pasta podem ser compilados com:
````
$ g++ *.cpp
````
Feito isso, a execução será feita com:
````
$ ./a.out
````