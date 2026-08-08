#include <iostream>

// Estrutura do nó

struct Node
{

    int data;

    Node *next;
};

// Classe Pilha com Lista Encadeada

class Stack
{

private:
    Node *top;

public:
    Stack()
    {

        top = nullptr;
    }

    void push(int value)
    {

        Node *newNode = new Node(); // 

        newNode->data = value;

        newNode->next = top;

        top = newNode;
    }

    void pop()
    {

        if (top == nullptr)
        {

            std::cout << "Stack Underflow" << std::endl;

            return;
        }

        Node *temp = top;

        top = top->next;  

        delete temp;
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    int peek() const
    {
        if (top == nullptr)
        {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return top->data;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Topo: " << s.peek() << std::endl;

    s.pop();

    std::cout << "Topo apos pop: " << s.peek() << std::endl;

    while (!s.isEmpty())
        s.pop();

    // tenta remover de pilha vazia (vai imprimir underflow)
    s.pop();

    return 0;
}