#include <iostream>

#define MAXITENS 100

typedef int ItemType;

class Queue
{
private:
    int front;
    int back;
    ItemType *structure;

public:
    Queue()
    {
        front = 0;
        back = 0;
        structure = new ItemType[MAXITENS];
    }

    ~Queue()
    {
        delete[] structure;
    }

    void enfileirar(ItemType item)
    {
        structure[back] = item;
        back = (back + 1) % MAXITENS;
    }

    ItemType desenfileirar()
    {
        if (!vazia())
        {
            ItemType temp = structure[front];
            front = (front + 1) % MAXITENS;
            return temp;
        }

        return -1;
    }

    bool vazia() const
    {
        return (front == back);
    }
};

int main()
{
    Queue fila;

    fila.enfileirar(10);
    fila.enfileirar(20);
    fila.enfileirar(30);

    std::cout << "Removido: " << fila.desenfileirar() << '\n';
    std::cout << "Removido: " << fila.desenfileirar() << '\n';

    fila.enfileirar(40);

    std::cout << "Removido: " << fila.desenfileirar() << '\n';
    std::cout << "Removido: " << fila.desenfileirar() << '\n';
    std::cout << "Vazia? " << (fila.vazia() ? "sim" : "nao") << '\n';

    std::cout << "Elementos na fila:\n";
    while (!fila.vazia())
    {
        std::cout << fila.desenfileirar() << ' ';
    }

    return 0;
}