#include <stdio.h>
#include <stdlib.h>

// int buscaSequencialDesordenada(int *V, int n, int chave){
//     int p, posic = -1;
//     for (p = 0; p < n; p++)
//     {
//         if (chave == V[p])
//         {
//             posic = p;
//         }
//     }
//     return posic;
// }
//----------------------------------------------------------------------------------------------------------------------------------------
// int buscaSequencialOrdenada(int *V, int n, int chave){
//     int p = 0, posic = -1;
//     while (p < n && V[p] <= chave)
//     {
//         if (chave == V[p])
//         {
//             posic = p;
//             break;
//         }
//         p++;
//     }
//     return posic;
// }
//----------------------------------------------------------------------------------------------------------------------------------------
// int buscaBinaria(int *V, int n, int chave){
//     int inicio = 0, final = n - 1, meio;
//     while(inicio <= final){
//         meio  = (inicio + final)/2;
//         if (chave == V[meio]) return meio;
//         if (chave <= V[meio]) final = meio - 1;
//         else 
//             inicio = meio + 1;} 
//         return -1; 
// }
//----------------------------------------------------------------------------------------------------------------------------------------
// John
// void troca(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int particiona(int *V, int inicio, int final){
//     int p, pivo = V[inicio], posic = final + 1;
//     for(p = final; p > inicio; p--)
//         if(V[p] >= pivo) 
//             troca(&V[p], &V[--posic]);
//     troca(&V[inicio], &V[--posic]);
//     return posic;
// }

// int quickSort(int *V, int inicio, int final){
//     if(inicio <= final){
//         int p = particiona(V, inicio, final);
//         quickSort(V, inicio, p-1);
//         quickSort(V, p+1, final);
//     }
// }
//----------------------------------------------------------------------------------------------------------------------------------------
// int quickSelect(int *V, int inicio, int final, int chave) {
//     if (inicio <= final) {
//         int p = particiona(V, inicio, final);
//         if (p == chave) return V[p];
//         else if (chave < p) return quickSelect(V, inicio, p - 1, chave);
//         else return quickSelect(V, p + 1, final, chave);
//         }return -1;
// }
//----------------------------------------------------------------------------------------------------------------------------------------
//Nilton
// int particiona(int *V, int inicio, int fim){
//     int esq = inicio, dir = fim, pivo = V[inicio], aux;
//     while (esq < dir){
//         while (V[esq] <= pivo)
//             esq++;
//         while (V[dir] >= pivo && V[dir] > pivo)
//             dir--;
//         if (esq < dir){
//             aux = V[esq];
//             V[esq] = V[dir];
//             V[dir] = aux;
//         }
//     }
//     V[inicio] = V[dir];
//     V[dir] = pivo;
//     return dir;
// }

// void quickSort(int *V, int inicio, int fim){
//     int pivo;
//     if (inicio < fim){   
//         pivo = particiona(V, inicio, fim);
//         quickSort(V, inicio, pivo - 1);
//         quickSort(V, pivo + 1, fim);}
// }
//----------------------------------------------------------------------------------------------------------------------------------------
//John
// void intercala(int *V, int inicio, int meio, int final){
//     int *aux = malloc((final - inicio + 1) * sizeof(int));
//     int i = inicio, j  = meio + 1, k = 0;
//     while(i <= meio && j <= final){
//         if (V[i] <= V[j])
//             aux[k++] = V[i++];
//         else 
//             aux[k++] = V[j++];
//     }
//     while(i <= meio) 
//         aux[k++] = V[i++];
//     while(j <= final) 
//         aux[k++] = V[j++];
//     k = 0, i = inicio;
//     while(i <= final) 
//         V[i++] = aux[k++];
//     free(aux);
// }

// void mergeSort(int *V, int inicio, int final){
//     if(inicio < final){
//         int meio = (inicio + final)/2;
//         mergeSort(V, inicio, meio);
//         mergeSort(V, meio + 1, final);
//         intercala(V, inicio, meio, final);
//     }
// }
//----------------------------------------------------------------------------------------------------------------------------------------
//Nilton
// void merge(int inicio, int meio, int fim, int v[]) {
//     int *w;
//     w = malloc((fim - inicio + 1) * sizeof(int));  // Correção do tamanho do buffer temporário
//     int i = inicio, j = meio + 1;
//     int k = 0;

//     while (i <= meio && j <= fim) {
//         if (v[i] <= v[j]) w[k++] = v[i++];
//         else w[k++] = v[j++];}
//     while (i <= meio) w[k++] = v[i++];
//     while (j <= fim) w[k++] = v[j++];
//     for (i = inicio; i <= fim; ++i) v[i] = w[i - inicio];
//     free(w);
// }

// void mergeSort(int *V, int inicio, int fim) {
//     int meio;
//     if (inicio < fim) {
//         meio = (inicio + fim) / 2;
//         mergeSort(V, inicio, meio);
//         mergeSort(V, meio + 1, fim);
//         merge(inicio, meio, fim, V);
//     }
// }
//----------------------------------------------------------------------------------------------------------------------------------------
//Prova
// int particiona(int *v, int e, int d){
//     int p = v[d];
//     int t, j = e;
//     for (int k = e; k < d; k++){
//         if (v[k] <= p){
//             t = v[j], v[j] = v[k], v[k] = t;
//             ++j;
//         } 
//     }
//     t = v[j], v[j] = v[d], v[d] = t;
//     return j;
// }
// void quickSort(int *V, int inicio, int fim){
//     int pivo;
//     if (inicio < fim){   
//         pivo = particiona(V, inicio, fim);
//         quickSort(V, inicio, pivo - 1);
//         quickSort(V, pivo + 1, fim);}
// }
//----------------------------------------------------------------------------------------------------------------------------------------
//Tabela Hash
typedef struct no{
    int x;
    struct no*prox;
}no;

typedef struct{
    no *tabela;
    int M, n;
}th;

th *cria_hash(int M){
    th *hash = malloc(sizeof(th));
    hash -> tabela = calloc(M, sizeof(no));
    hash -> M = M;
    return hash;
}

int funcao_hash(int x, int M){
    int a = 2, b = 3, p = 5;
    return x%M;
    // return ((a*x + b)%p)%M;
}

int busca(th *hash, int x){
    int i = funcao_hash(x, hash -> M);
    no *elem = hash -> tabela[i].prox;
    while (elem != NULL){
        if (elem -> x == x){
            return 1;
        }
        elem = elem -> prox;
    }
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------
int main(){
//     int V[] = {13, 19, 9, 5, 12};
//     int n = sizeof(V)/sizeof(V[0]);

//     int posicao = buscaSequencialDesordenada(V, n, 0);
//     printf("%d",posicao);
//----------------------------------------------------------------------------------------------------------------------------------------
//     int posicao = buscaSequencialOrdenada(V, n, 8);
//     printf("%d", posicao);
//----------------------------------------------------------------------------------------------------------------------------------------
//     int posicao = buscaBinaria(V, n, 3);
//     printf("%d", posicao);
//----------------------------------------------------------------------------------------------------------------------------------------
//     quickSort(V, 0, n - 1);
//     printf("Array ordenado:\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", V[i]);
//     }
//     printf("\n");
//----------------------------------------------------------------------------------------------------------------------------------------
//     mergeSort(V, 0, n - 1);
//     printf("Array ordenado:\n[");
//     for (int i = 0; i < n; i++) {
//         printf(" %d ", V[i]);
//     }
//     printf("]\n");
//----------------------------------------------------------------------------------------------------------------------------------------
//     int resultado = quickSelect(V, 0, n - 1, 0);
//     printf("%d", resultado);
    int M = 7; // Tamanho da tabela hash
    th *hash = cria_hash(M); // Cria a tabela hash

    // Inserção manual para teste
    int valores[] = {10, 14, 5, 24, 3, 15, 18}; // Valores para armazenar na tabela
    for (int i = 0; i < 5; i++) {
        int idx = funcao_hash(valores[i], M);

        // Cria um novo nó
        no *novo = malloc(sizeof(no));
        novo->x = valores[i];
        novo->prox = hash->tabela[idx].prox; // Insere no início da lista encadeada
        hash->tabela[idx].prox = novo;
    }

    // Exibe a tabela hash
    printf("Tabela Hash:\n");
    for (int i = 0; i < M; i++) {
        printf("No %d: ", i);
        no *elem = hash->tabela[i].prox;
        while (elem) {
            printf("%d -> ", elem->x);
            elem = elem->prox;
        }
        printf("NULL\n");
    }

    // Busca por valores
    printf("\nBuscando valores:\n");
    int chaves[] = {5, 10, 18}; // Testando valores na tabela
    for (int i = 0; i < 3; i++) {
        printf("Busca por %d: %s\n", chaves[i], busca(hash, chaves[i]) ? "Encontrado" : "Nao encontrado");
    }
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------
//Exemplo de Tabela Hash (Não executável)
// int *aero = calloc(n,sizeof(int)), o, d;
// while(scanf("%d %d", &o, &d) != EOF){
//     aero[o]++; aero[d]++;
// }
// int maior = aero[o], aero_maior = 0;
// for (int i = 1; i < n; i++){
//     if(aero[i] > maior){
//         maior = aero[i]; aero_maior = i;
//     }
// }
// O vetor *aero* é uma *tabela* cujos índices representam cada aeroporto da seguinte forma: 
//  Se o aeroporto é identificado por *i*, ele é representado em *aero[i]*.
//  Esse mapeamento é uma *função de espalhamento (hash)* que, no caso, é chamada de 
//  endereçamento direto, pois maperia de 1 pra 1.
