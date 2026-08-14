# Aplicação da Estrutura

Podemos utilizar as tabelas hash sempre que queremos armazenar uma coleção de dados para depois obter os registro de maneira eficiente. 

Se a função hash foi bem estruturada, conseguimos inserir o obter os valores em tempo constante. 

## função de dispersão

A **função de dispersão** (ou função de espalhamento, denotada como (h)) é o componente central de uma Tabela Hash. Sua função principal é realizar um **mapeamento de uma chave de busca ((k)) para um número inteiro**, que servirá como o índice de um vetor onde o registro será armazenado.

Aqui estão os detalhes fundamentais de como ela funciona:

### 1. Transformação de Chaves em Índices
O objetivo é que a chave (que pode ser uma string, um objeto ou um ponto flutuante) forneça diretamente o endereço de memória do seu valor. Para isso, a função segue geralmente dois passos:
*   **Mapeamento para Inteiro:** Se a chave for uma string (como um nome), a função transforma os caracteres em números (usando a tabela ASCII, por exemplo) e os combina para gerar um valor inteiro.
*   **Compressão:** Para garantir que o número gerado "caiba" dentro do tamanho do vetor (N), utiliza-se comumente o resto da divisão (**operador módulo**):h(k) = k (mod N).

### 2. O que define uma "Boa" Função?
Uma função de dispersão é considerada boa quando ela **minimiza a ocorrência de colisões** (que ocorrem quando duas chaves diferentes resultam no mesmo índice). Para alcançar um bom espalhamento, as fontes destacam:
*   **Uso de Números Primos:** Definir o tamanho do vetor (N) como um número primo ajuda a quebrar padrões repetitivos nos dados, distribuindo-os melhor e reduzindo colisões.
*   **Consideração da Posição:** Em strings, somar apenas os valores dos caracteres pode gerar muitas colisões (como nos nomes "Orlando" e "Rinauldo"). Funções mais eficientes usam fórmulas polinomiais que levam em conta a **posição de cada letra**.

### 3. Desempenho
Quando a função de dispersão é bem estruturada e os dados estão bem distribuídos, as operações de busca, inserção e remoção podem ser realizadas em **tempo constante (O(1))**. Isso ocorre porque, em vez de percorrer toda a estrutura (como na busca sequencial), o sistema "calcula" onde o elemento deve estar e vai direto para aquela posição no vetor.

### 4. O Problema das Colisões
Mesmo uma boa função raramente elimina as colisões por completo. Quando o cálculo (h(k)) aponta para um índice que já está ocupado, a estrutura precisa de técnicas de tratamento, como:
*   **Encadeamento Separado:** Onde cada posição do vetor inicia uma lista encadeada com todos os elementos que colidiram naquele índice.
*   **Endereçamento Aberto (Teste Linear):** Onde o sistema procura a próxima posição vazia no próprio vetor para inserir o novo item.