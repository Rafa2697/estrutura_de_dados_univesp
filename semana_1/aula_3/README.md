# Noções basicas de vetores
- Na declaração, informamos o tipo e o número de elementos.
```
int c[10];
```
- Declarando e inicializando os elementos
```
int c[10] = {14, 0, 13}; // [14, 0, 13,  0, 0, 0, 0, 0, 0, 0]
```
- Declarando vetor sem definir uma quantidade
```
int c[] = {14, 0, 12}; // [14, 0, 12]
```

    - Inicializamos os primeiros três elementos. 
    - Como não fornecemos valores para toddos os elementos, o restante iniciará com zero. 
- Os elementos podem ser acessados com a sintaxe de colchetes. 
```
c[5] = 30; // coloca o valor 30 na posição 5
c[7] = 40;
c[8] = 50;
```
- É comum iterarmos pelos valores com for.
```
for(int i = 0, i < 10; i++){
    std::cout << "c[" << i << "] = " << c[i] << "\n";
}
```
- É tarefa do programador verificar os limites do vetor antes de fazer o acesso. 
- Especificarmos o tamanho do vetor com uma variavel contante:
    - [Veja esse exemplo de vetor com constante](./ex1_vetor_com_constante.cpp)

### Alocação dinâmica
- Os vetores declarados até aqui eram estáticos, pois o número de elementos era fixado em tempo de compilção.
- Podemos declarar vetores em que o número de elementos é conheciddo apenas durante a execução com a alocação dinâmica.
- O tamanho do vetore não poderá mudar após a declaração.
- Para fazer a alocação dinâmica, usaremos o operador ***new*** que já conhecemos. 
```
int* c = int[num_elem];
```
- O comando alocará uma região de memória de tamanho suficiente para alocar ***num_elem*** elementos inteiros contíguos.
- Em outras palavras, o comando cria ***num_elem*** elementos inteiros consecutivos (um vetor).
- A variável do vetor. Feito isso, podemos usar a sintaxe de colchetes. 
```
c[5] = 30;
c[7] = 40;
c[8] = 50;
```
- [Exemplo](./ex2_vetor_dinamico.cpp)
- Como a alocação foi feita de forma dinâmica com ***new***, precisamos desalocar a memória com o comando ***delete***.
```
int* c = new int[num_elem];

delete [] c;
```
### Passagem de parâmetros
- No comando a seguir:
    ```
    int c[10];
    ```
    - a variável c armazena o endereli base do vetor.
    - Nesse caso, c é um ponteiro
- O mesmo ocorre na alocação finâmica:
    ```
    int* c = new int[num_elem];
    ```
- Quando passamos um vetor para uma função, estamos passando um ponteiro.
- Vamos discutir a passagem de ponteiros:
    ```
    // nada vai mudar fora da função
    void valor_alocando_memoria(int* p){
        p = new int;
        *p = 7;
    }

    void valor_modificando_memoria(int* p){
        *p = 8;
    }

    void referencia(int*& p){
        p = new int;
        *p = 9;
    }
    ```
- [Exemplo](./ex3_ponteiros_como_parametros.cpp)

## Comandos para compilar

>[!NOTE]
> Cada um dos arquivos da aula deve ser compilado separadamente.

Por exemplo: 

```
$ g++ ex0_vetor_inteiros.cpp -o ex0_vetor_inteiros
```
Compilado o código, o arquivo gerado pode ser executado.
```
$ ./ex0_vetor_inteiros
```

É possível compilar sem fornecer o nome do executável. Nesse caso, o
arquivo gerado terá nome "a.out".

Por exemplo: 
```
$ g++ ex0_vetor_inteiros.cpp
```
Compilado o código, o arquivo gerado pode ser executado.
```
$ ./a.out
``` 