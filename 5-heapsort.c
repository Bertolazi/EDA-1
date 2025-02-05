#include <stdlib.h>
#include <stdio.h>

/*
Heap Sort
    . Usar filas de prioridades para ordenar elementos
    . Construir e destruir a heap da fila de prioridades
    . Fase 1: Construção/conserto da heap-ordenada (fila de prioridades)
        -> Construção da heap por inserção
        -> fixUp para posicionar na heap
    . Fase 2: Ordenação (decrescente)
        -> Ordenação por remoção (maior prioridade)
        -> Reorganização da fila de prioridades
        -> Cada item removido volta para o vetor original
    . Custo proporcional a 2N.logN - O(n.logn)
*/

// Ideia da utilização da fila de prioridades
void PQsort(Item *v, int l, int r){
    PQinit(r-l+1);
    for(int k=l; k<=r; k++){
        PQinsert(v[k]);
    }
    for(int k=r; k>=l; k--){
        v[k] = PQdelmax();
    }
}

/*
    . Versão utilizada/implementada
    . USar diretamente as funções internas: fixUp(swin) e fixDown(sink)
    . Não há necessidade de espaços extras
        -> O vetor orifginal é usado para construir a heap
        -> Vetor original como uma heap desordenada
    . Fase 1:
        -> Consertar debaixo para cima
        -> Consertar subárvores -> sub-heaps ordenadas
        -> Assim cada nó é reorganizado em uma sub-heap já ordenado
        -> Lembrando que cada nó é uma raiz de uma sub árvore 
        -> Fase 1: construção/conserto de heap
        -> Debaixo para cima: k inicial?
*/

// Primeiro código

int v[10] = {16, 94, 43, 10, 22, 18, 40, 12, 68};
int *pq = v-1; // pq aponta &v[0]-1
               // pq[i] = v[0]
/*
    . Exemplo de implementação na prática

    v       0    1    2    3    4    5    6    7    8
    pq  0   1    2    3    4    5    6    7    8    9
      [     16   94   43   10   22   18   40   12   68  ]

      16
     /  \
    94   43
    / \  / \
   10 22 18 40
   / \ 
  12  68
    
        -> k = Pai da última folha
    v       0    1    2    3    4    5    6    7    8
    pq  0   1    2    3    4    5    6    7    8    9
      [     16   94   43   10   22   18   40   12   68  ]
*/