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
    int maxdeth = 2*((int)log2((double)(r-l+1)));

    intro(v, l, r, maxdeth);
    insertion_sort(v, l, r);
}

/*
v[] = 11 10 9 8 7 6 1 4 13 12 5
introsort(v, 0, 10)
|   maxdepth = 2
|   intro(v, 0, 10, 2) // quick sem mediana
|   |   partition(v, 0, 10) : 11 10 9 8 7 6 1 4 13 12 5
|   |   |                     4 10 9 8 7 6 1 11 13 12 5
|   |   |                     4 1 9 8 7 6 10 11 13 12 5
|   |   |                     4 1 5 8 7 6 10 11 13 12 9
|   |   intro(v, 0, 1, 1) // quick esquerda
|   |   | // r-l<=2 : 4 1
|   |   | return
|   |   intro(v, 2, 10, 1) // quick direita
|   |   |   partition(v, 0, 10) : 8 7 6 10 11 13 12 9
|   |   |   |                     8 7 6 10 11 13 12 9
|   |   |   |                     8 7 6 9 11 13 12 10
|   |   |   intro(v, 2, 6, 0) // quick esquerda
|   |   |   |   // maxdepth == 0
|   |   |   |   heap(v, 2, 6) : 8 7 6
|   |   |   |   |               8 7 6
|   |   |   |   |               8 7 6
|   |   |   |   |               6 7 8
|   |   |   |   |               6 7 8
|   |   |   |   |               6 7 8
|   |   |   |   |               7 6 8
|   |   |   |   |               6 7 8
|   |   |   |   |               6 7 8
|   |   |   |   |               6 7 8
|   |   |   Continua ...
*/

// Complexidade ~~ quick(n) + heap(m) + insertion(k)
//              ~~ O(n.logn) + O(m.logm) + O(k*n) = O(n.logn)

void intro(int *v, int l, int r, int maxdepth){
    if(r-l<=15)
        return;
    if(maxdepth == 0){
        // merge_sort(v, l, r)
        heap_sort(v, l, r);
    } else {
        compexch(v[l], v[(l+r)/2]);
        compexch(v[l], v[r]);
        compexch(v[r], v[(l+r)/2]);
        int p = partition(v, l, r);
        intro(v, l, p-1, maxdepth-1);
        intro(v, p+1, r, maxdepth-1);
    }
}

void intro_sort(int *v, int l, int r){
    int maxdepth = ((int)log2((double)(r-l-1)));
    intro(v, l, r, maxdepth);
    insertion_Sort(v, l, r);
}