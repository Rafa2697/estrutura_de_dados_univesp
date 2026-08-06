## Estrutura do nó

Contém os dados e o endereço do sucessor na lista
```
typedef char ItemType;
/*
 Estrutura usada para guardar 
 a informação e o endereço do 
 próximo elemento.
*/
struct NodeType
{
  ItemType info;
  NodeType* next;
};
```
Com essa estrutura é possivel iniciar o encadeamento. ( o que seria isso ?)

Note que basta armazenarmos um único ponteiro, aquele que aponta para o inicio da estrutura. 

Como todas as operações ocorrem na cabeça da pilha, conseguimos efeturar em tempo constante. 

## Tipo abstrato de dados

```
#include "node_type.h"

class Stack
{
 public:
  Stack();  // Construtor       
  ~Stack(); // Destrutor
  bool isEmpty() const;
  bool isFull() const;
  void print() const;

  void push(ItemType);
  ItemType pop();  
 private:
  NodeType* structure;
};
```
