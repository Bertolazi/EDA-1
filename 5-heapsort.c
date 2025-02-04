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