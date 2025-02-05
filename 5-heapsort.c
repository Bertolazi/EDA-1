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
        -> Percebemos que 68 é filho de 10 e é maior
            => k = N/2 -> fixDown(k)
            => fixDown(i): pai(i)<filhos(2i(esquerda) e 2i+1(direita))
            => fixDown(i): swap e (i=2i+1)<N
        -> logo:  
    v       0    1    2    3    4    5    6    7    8
    pq  0   1    2    3    4    5    6    7    8    9
      [     16   94   43   68   22   18   40   12   10  ]
            => fixDown(i): swap e (i=2i)<N? Não: sub-heap ordenada
      16
     /  \
    94   43
    / \  / \
   68 22 18 40
   / \ 
  12  10
        -> Próxima subárvore: pq[x], sendo x>k, possuem filhos?
            => Próxima subárvore: (--k>=1)? fixDown(k)
            => fixDown(i): pai(i)<filhos(2i e 2i+1)? Não, os filhos são menores
      16
     /  \
    94   43
    / \  / \
   68 22 18 40
   / \ 
  12  10
        -> Próxima subárvore
            => (--k>=1)? fixDown(k)
            => Novamente sem fixDown, todos os elementos menores que o pai
    v       0    1    2    3    4    5    6    7    8
    pq  0   1    2    3    4    5    6    7    8    9
      [     16   94   43   68   22   18   40   12   10  ]
        -> Próxima subárvore
            => (--k>=1)? fixDown(k)
            => Chegamos na raiz
            => fixDown(i): pai(i) < filhos(2i e 2i+1)?
            => 94 é o menor filho, logo:
            => fixDown(i): swap e i=2i
    v       0    1    2    3    4    5    6    7    8
    pq  0   1    2    3    4    5    6    7    8    9
      [     94   16   43   68   22   18   40   12   10  ]
            => Com isso:
      94
     /  \
    16   43
    / \  / \
   68 22 18 40
   / \ 
  12  10
        -> Comparamos agora o próprio 16 com os filhos
            => (--k>=1)? fixDown(k)
            => fixDown(i): pai(i) < filhos(2i e 2i+1)?
            =>  68 é o menor filho, então:
    v       0    1    2    3    4    5    6    7    8
    pq  0   1    2    3    4    5    6    7    8    9
      [     94   68   43   16   22   18   40   12   10  ]
            => Temos então a subárvore:
      94
     /  \
    68   43
    / \  / \
   16 22 18 40
   / \ 
  12  10
        -> Como o 16 ainda tem filhos, vemos se ele não é menor que os dois filhos:
            => Como nenhum filho é menor que 16 partimos para seginda fase
        -> Fase 2: Ordenação (decrescente)
            => Remover o máximo repetidamente
            => Raiz para o fim da fila
            => Diminui-se o tamanho da fila
            => fixDown da raiz
        -> Swap do primeiro elemento com o último elemento
    v       0    1    2    3    4    5    6    7    8
    pq  0   1    2    3    4    5    6    7    8    
      [     10   68   43   16   22   18   40   12   94  ]
      10
     /  \
    68   43
    / \  / \
   16 22 18 40
   / \ 
  12  94

        -> fixDown da raiz
            => fixDown(1, --N)
            => Compara com os filhos, sendo 68 o maior filho, swap
    v       0    1    2    3    4    5    6    7    8
    pq  0   1    2    3    4    5    6    7    8    
      [     68   10   43   16   22   18   40   12   94  ]
      68
     /  \
    10   43
    / \  / \
   16 22 18 40
   / \ 
  12  94
        -> fixDown do 10 novamente
            => 22 maior filho, logo swap:
    v       0    1    2    3    4    5    6    7    8
    pq  0   1    2    3    4    5    6    7    8    
      [     68   22   43   16   10   18   40   12   94  ]  
      68
     /  \
    22   43
    / \  / \
   16 10 18 40
   / \ 
  12  94 
        -> Agora o 10 não tem mais filho         
            => Comparamos com seu pai k = k/2
            => No caso seu pai é 22
            => Não fazemos trocas, pois os filhos são menores
        -> Fazemos agora com o pai de 22
            => == Raiz == 68
            => Não há trocas, pois o 68 não tem filhos menores
        -> Agora realizamos os swaps
            => exch(pq[1], pq[N]) (N no nosso exemplo é 9)
            => logo:
    v       0    1    2    3    4    5    6    7    8
    pq  0   1    2    3    4    5    6    7    8    
      [     12   22   43   16   10   18   40   68   94  ]  
        -> Agora fazemos novamente o fixDown da raiz que foi trocada
            => 43 e comparamos com os filhos
Pg 36


*/