# Estrutura de dados - Classes

## Noções Básicas

A unidade básica da POO é a classe, que encapsula atributos estátivos e comportamento dinâmico em uma caixa.

A classe é um modelo usado para criar objetos, tambem chamados de instâncias.

A comunicação com os objetos é feita pelo uso da interface pública do objeto.

A complexidade envolvida na realização de uma tarefa fica escondida dentro da classe.

Uma vantagem do paradigma é o isolamento, quando alterações não afetam todo o sistema.

Esse isolamento facilita a adição de novas funcionalidades e correção de problemas.

Como os detalhes de implementação ficam escondidos dentro da classe, podemos gerar implementações diferentes facilmente.

Em estruturas de dados, isso permitirá separar a visão lógica, da visão de implementação e da visão de aplicação.

A visão lógica de uma classe será sempre criada em um arquivo de extensão .h.
Nesse arquivo, definiremos os **membros públicos e privados** de uma classe. A implementação da classe, será sempre feita em um arquivo de extensão .cpp, e o arquivo .cpp deverá sempre importar o arquivo .h com a diretiva include.

É comum tentar incluir uma definiçãop de cklasses mais de uma vez. Nesse caso, utilizamos algumas diretivas que impedem que isso aconteça:
-   #ifndef: se não definido
    -   Pule este código se já tiver sido incluído.
-   #define
    -   Define um nome para evitar dupla inclusão.
-   #endif
    -   ```
        #ifndef TIME_H // inclua esse bloco apenas se TIME_H não está definido
        #define TIME_H // Na primeira inclusão, defina TIME_H para que este bloco não seja incluído mais de uma vez

        #endif // Final do bloco "#ifndef"
        ``` 

Os arquivos desta pasta podem ser compilados com:
```
$ g++ *.cpp
```

Feito isso, a execução será feita com:

```
$ ./a.out
```
