#include "item_type.h"

const int MAX_ITEMS = 100;

// tipos abstratos de dados (TAD) - pilha
class Stack
{
public:
  //metodos
  Stack();  // Construtor
  ~Stack(); // Destrutor
  bool isEmpty() const;
  bool isFull() const;
  void print() const;

  void push(ItemType);
  ItemType pop(); //itemType é um apelido para char, definido em item_type.h

private:
  int length;
  ItemType *structure;
};
