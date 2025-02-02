#include <stdlib.h>
#include <stdio.h>

/*
Fila de prioridades:
    . É um tipo abstrato de dados (TAD)
        -> Estrutura de dados com comportamento específicos
        -> Acessadas por um conjunto de operações (interface)
    . Existem operações que envolvem um grande fluxo de informações que precisam de alguma ordenação
        -> Não necessariamente precisam estar totalmente organizados
            => O importante é saber qual tem maior prioridade
        -> Não necessariamente precisam processar todos os dados
            => Conforme os dados forem coletados, atualiza-se a fila de prioridade
        -> Dados que não são rankeados conforme um critério em que o mais importante é saber quem está no topo
        -> Exemplo: Mineração de dados, caminhos em grafos (verificar adjacentes na decisão do caminho)
    . A fila pode ser com prioridade máxima (maior chave, maior prioridade) ou mínima (menor valor, maior prioridade)
Heap 
    . Heap binária (heap): Árvore binária quase completa com vetores
    . Forma uma árvore binária quase completa com as seguintes características
        -> Todas as folhas estão no nível "d" ou "d-1"
        -> Todos os níveis exceto o último estão cheios
        -> Os nós dos últimos níveis estão o mais a esuqerda possível
    . Chama-se de raiz a chave de maior prioridade
    . Não ordena por completo, só garante que:
        -> Quanto mais próximo a raiz, maior a prioridade
        -> Cada nó possui filhos com valores menores ou iguais
    . Representada por um vetor
        -> Eficiente para operações básicas (logarítmica) da fila de prioridades
        -> Representação sequencial da árvore: Facilidade de deixá-la completa
        -> Acesso direto aos nós
        -> Níveis das árvore acessada pelos seus índices:
            => Raiz: Posição 1
            => Filhos: Posição 2 e 3
            => Netos: Posição 4, 5, 6 e 7
            => E assim por diante
    . Navegação trivial para cima e para baixo
        -> Simples operação aritmética
        -> Sendo um nó a posição k
            => Pai: k/2
            => Filhos: 2k e 2k+1
    . Tamanho N em um vetor pq[]
        -> pq[N+1]: pq[1...N]
        -> Em alguns casos não se utiliza a posição pq[0], como é mostrado no exemplo acima, mas...
        -> E se utilizar
            => Pai: (k-1)/2
            => Filhos: 2k+1 e 2k+2
    . Interface (Manipulação da fila)
        -> PQinit(int maxN): Criar uma fila de prioridade com uma capacidade máxima inicial
        -> PQempty(): Testar se ela está vazia
        -> PQinsert(Item v): Inserir uma chave
        -> PQdelmax(): Retornar e remover (maior prioridade)
        -> Busca ??
*/

// Fazendo as operações acima descritas:

#define less(A,B) ((A)<(B))
#define exch(A,B) {Item t=A; A=B; B=t; }

// static: acessível apenas pelo arquivo
static Item *pq;
static int N;

void PQinit(int maxN){
    pq = malloc(sizeof(Item)*(MaxN+1));
    N = 0;
}

int PQempty(){
    return N==0;
}

/*
Inserção na heap
    . Inserção nas folhas
    . Restauração/conserto: Subindo na heap (maior que o pai?)

    8
  
 Inserir 8 [8]

    8
   /  
  9   

 Inserir 9 [8,9] 

    9
   /  
  8

 Restaurando 9 [9,8]
  
    9
   /  \
  8    7

 Inserir 7 [9,8,7]

    9
   /  \
  8    7
 / \  / \
6   3 5   3

 Inserir 6,3,5,3 [9,8,7,6,3,5,3]  

      9
     /  \
    8    7
   / \  / \
  6   3 5   3
 / \
4  1

 Inserir 4,1 [9,8,7,6,3,5,3,4,1]

        9
       /  \
      8    7
     / \  / \
    6   3 5   3
   / \   \
  4   1  10

 Inserir 10 [9,8,7,6,3,5,3,4,1,10]

        9
       /  \
      8    7
     / \  / \
    6  10 5   3
   / \   \
  4   1   3

 Restaurando 10 [9,8,7,6,10,5,3,4,1,3]

        9
       /  \
     10    7
     / \  / \
    6   8 5   3
   / \   \
  4   1   3

 Restaurando 10 [9,10,7,6,8,5,3,4,1,3]

        10
       /  \
      9    7
     / \  / \
    6   8 5   3
   / \   \
  4   1   3

 Restaurando 10 [10,9,7,6,8,5,3,4,1,3]

    . Vamos ver como ficaria o código para essa aplicação 
*/

// Código de adicionar uma nova chave no fim do vetor

void PQinsert(Item v){
    // Adiconar no fim
    pq[++N] = v;
    // Consertar o elemento na posição N
    fixUp(N);
}

/*
    . Restaura a ordenação da heap: bottom-up(swim-fixUp)
        -> Flutue (swap) caso a chave seja maior que seu pai
        -> Repetidamente, flutue até pai maior ou raiz
*/

// Código inserção na heap

void fixUp (int k){
    // k até 1 - reduzindo metade por interação
    // altura da árvore é aproximadamente log k
    // Se não for raiz e for maior que o pai
    while(k>1 && less(pq[k/2], pq[k])){
        // troque
        exch(pq[k], pq[k/2])
        // Subir: atualizar k
        k = k/2
    }
}

/*
Remoção
    . Remover qual elemento
    . Substituir a raiz por uma folha
    . Restauração/conserto: Descendo na heap
    . Substituir a raiz por uma folha

        10
       /  \
      9    7
     / \  / \
    6   8 5   3
   / \   \
  4   1   3

 Árvore inicial

        3
       /  \
      9    7
     / \  / \
    6   8 5   3
   / \   \
  4   1   10

 Removendo 10 && Restaurando 3 [3,9,7,6,8,5,3,4,1,10]

        9
       /  \
      3    7
     / \  / \
    6   8 5   3
   / \   \
  4   1   10

 Restaurando 3 [9,3,7,6,8,5,3,4,1,10]

        9
       /  \
      8    7
     / \  / \
    6   3 5   3
   / \   \
  4   1   10

 Restaurando 3 [9,8,7,6,3,5,3,4,1,10]

    . No final da remoção, removemos a raiz sem prejudicar nenhum dos filhos, então o 10 "some"

        9
       /  \
      8    7
     / \  / \
    6   3 5   3
   / \   
  4   1   

 [9,8,7,6,3,5,3,4,1]
    
    . Vamos ver como fazer isso em código
*/

// Troca da raiz com o último elemento

Item PQdelmax(){
    // Troque topo -> ultimo
}
//pg:38/14 slide