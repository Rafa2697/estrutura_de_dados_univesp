#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() 
{
  length = 0;
  structure = new ItemType[MAX_ITEMS]; // alocação dinâmica de memória para o vetor
}

Stack::~Stack()
{
  delete [] structure;
}

bool Stack::isEmpty() const //Verifica se a pilha está vazia, retorna true se estiver vazia e false caso contrário
{
  return (length == 0);
}

bool Stack::isFull() const //Verifica se a pilha está cheia, retorna true se estiver cheia e false caso contrário
{
  return (length == MAX_ITEMS);
}

void Stack::push(ItemType item)
{
  if (!isFull()){
    structure[length] = item; // Adiciona o item no topo da pilha
    length++;
  } else {
    throw "Stack está cheia!";
  }
}

ItemType Stack::pop()
{
  if (!isEmpty()){
    ItemType aux = structure[length - 1];
    length--;
    return aux;
  } else {
    throw "Stack está vazia!";
  }
}

void Stack::print() const
{
  cout << "Pilha = ";
  for (int i = 0; i < length; i++) {
    cout << structure[i];
  }
  cout << endl;
}
