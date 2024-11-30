
# Implementações de Estruturas de Dados 2

Este repositório contém exemplos de implementações de algoritmos clássicos de **ordenação**, **busca** e **estruturas de dados**, como a Tabela Hash. O objetivo é servir como material de estudo e consulta para disciplinas relacionadas à Computação e Estruturas de Dados.

## Conteúdo do Código

### Algoritmos de Busca
- **Busca Sequencial Desordenada**: Busca um elemento em um vetor desordenado.
- **Busca Sequencial Ordenada**: Busca um elemento em um vetor ordenado, interrompendo a pesquisa assim que passa da chave.
- **Busca Binária**: Busca eficiente para vetores previamente ordenados.

### Algoritmos de Ordenação
- **QuickSort (várias implementações)**:
  - Implementação com diferentes estratégias de particionamento.
  - Divide e conquista para ordenar vetores de forma eficiente.
- **MergeSort**:
  - Utiliza o conceito de divisão e mesclagem.
  - Divide o vetor em subvetores menores e os combina de forma ordenada.
- **QuickSelect**:
  - Algoritmo para encontrar o k-ésimo menor elemento em um vetor.

### Estrutura de Dados: Tabela Hash
- **Tabela Hash**:
  - Estrutura de dados para armazenar e buscar elementos de forma eficiente.
  - Implementada com listas encadeadas para tratar colisões.

## Como Usar

### Configurando o Ambiente
1. Certifique-se de ter um compilador C instalado (ex.: GCC).
2. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   cd seu-repositorio
   ```

### Compilando e Executando
Compile o arquivo principal com:
```bash
gcc -o main main.c
```
Execute o programa:
```bash
./main
```

### Editando o Código
Descomente as funções e chamadas no `main()` para testar diferentes algoritmos. Por exemplo:
- Para testar o **QuickSort**, descomente:
  ```c
  quickSort(V, 0, n - 1);
  printf("Array ordenado:\n");
  for (int i = 0; i < n; i++) {
      printf("%d ", V[i]);
  }
  printf("\n");
  ```

### Exemplos de Uso
#### QuickSort
```c
int V[] = {13, 19, 9, 5, 12};
int n = sizeof(V)/sizeof(V[0]);

quickSort(V, 0, n - 1);
printf("Array ordenado:\n");
for (int i = 0; i < n; i++) {
    printf("%d ", V[i]);
}
printf("\n");
```

#### Tabela Hash
```c
int M = 7; // Tamanho da tabela hash
th *hash = cria_hash(M); // Cria a tabela hash

int valores[] = {10, 14, 5, 24, 3, 15, 18}; // Valores para armazenar na tabela
for (int i = 0; i < 5; i++) {
    int idx = funcao_hash(valores[i], M);

    no *novo = malloc(sizeof(no));
    novo->x = valores[i];
    novo->prox = hash->tabela[idx].prox;
    hash->tabela[idx].prox = novo;
}
```

## Referências
- [GeeksforGeeks - Algorithms](https://www.geeksforgeeks.org/fundamentals-of-algorithms/)
- [Wikipedia - Sorting Algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)

## Licença
Este projeto está sob a licença MIT. Sinta-se à vontade para usá-lo, modificá-lo e distribuí-lo.
