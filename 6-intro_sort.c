#include <stdlib.h>
#include <stdio.h>

/*
Intro Sort
    . É uma importante combinação de algoritmos de ordenação interna, utilizando no C++, C#
        -> Java é quicksort three-way
            => Particionar o vetor em 3 partes (three-way): Menores, iguais e maiores
    . Híbrido
        -> quick+merge(mais espaço) + insertion
        -> quick+heap(mais constante) + insertion
    . Solução para utilizar as eficiências e evitar as deficiências de cada método
        -> Insertion: Adaptativo
        -> Quick: Bom desempenho na maioria dos casos e inplace
        -> Merge e Heap: Desempenho previsível para todos os casos
        -> Quando a profundidade da recursividade atinge um máximo estipulado, alterna-se para outro métodod de ordenação
    . Complexidade no pior caso: O(n.logn)
    . In-place 
        -> Merge: Espaço extra, proporcional a N
        -> Heap e Quick: Sim
    . Não estável
    . Não adaptativo
*/

void intro(int *v, int l, int r, int maxdeth){
    if(r-l<=15){
        return;
    } else if (maxdeth == 0){
        // mergesort(v, l, r);
        heap_sort(v, l, r);
    } else {
        compexch(v[l], v[(l+r)/2]);
        compexch(v[l], v[r]);
        compexch(v[r], v[(l+r)/2]);

        int p = partition(v, l, r);
        intro(v, l, p-1, maxdeth-1);
        intro(v, p+1, r, maxdeth-1);
    }
}

void intro_sort(int *v, int l, int r){
    // Proporcional à altura de uma árvore balanceada
    int maxdeth = 2*((int)log2((double)(r-l+1)))
}