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
    . Complexidade 1 + log N comparações - O(log N)
    . Vamos ver a implementação dessa função
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
    exch(pq[1], pq[N]);
    // Reposicione
    fixDown(1, N-1);
    // Retorne o removido
    return pq[N--];
}

/*
    . Restaura a ordenação da heap: top-down (sink-fixDown)
        -> Afunde caso a chave seja menor que os filhos
            => swap com o maior filho
        -> Repetidamente, afunde até ser maior ou igual que os filhos ou ser folha
        -> Complexidade 2 log N comparações - O(log N)
        -> Vamos ver essa implementação em código
*/

void fixDown(int k, int N){
    // Enquanto tiver filho (?)
    while(2*k<=N){
        int j = 2*k; // Filho da esquerda
        // 2*k até N - dobrando a cada interação
        // Altura aproximadamente lok k
        // Se tiver filho da direita e for maior?
        if(j<N && less(pq[j], pq[j-1]))
            j++;
        // p[k] maior que o filho?
        if(!less(pq[k], pq[j]))
            break;
        // senão, afunde (troque com o filho)
        exch(pq[k], pq[j]);
        // Atualiza k para o maior filho
        k = j;
    }
}

/*
Várias filas
    . Implementação com array
    . Várias filas
*/

typedef int Item;
typedef struct{
    Item *pq;
    int N;
}PQueue;

PQueue *PQinit(int);
int PQempty(PQueue);
void PQinsert(PQueue*, Item);
Item PQdelmax(PQueue);

void fixUp(PQueue*, int);
void fixDown(PQueue*, int);

/*
Alterar prioridade
    . Se temos o índice na fila de prioridades é trivial
*/

void PQchange(int k, int valor){
    v[k] = valor;
    fixUp(k);
    fixDown(k, N);
}

/*
    . Se não tem acesso direto?
    . Alterar a chave de valor 10 por 50?
        -> Veja o exemplo abaixo
    pq[k]
    [0] - -
    [1] - 30
    [2] - 23
    [3] - 17
    [4] - 09
    [5] - 10
    [6] - 04
    . Base de dados: dta[i]
    . Fila de prioridaddes: Posições da base de dados
        -> pq[k] = i
        -> i o índice em data[i]
        -> k sua prioridade (posição na fila)
    . Se alterar algum dado de data?
        -> Se data[0].chave = 50?
        -> Veja abaixo
    data[i]
    [0] {José, 10}
    [1] {Maria, 09}
    [2] {Júlio, 04}
    [3] {Paulo, 23}
    [4] {Ana, 30}
    [5] {Carla, 17}
    . Lista de posições de data em pq
    . Sendo qp[i] = k <-> data[]
        -> pq[k] = i
        -> pq[qp[i]] = i
    . Veja o código abaixo
*/

typedef struct{
    char nome[20];
    int chave;
} Item;

static int *pq;
static int *qp;
static int N;

void PQinit(int);
void PQinsert(int);
void PQchange(int);
int PQdelmax();

int main(){
    int data[6] {{"José", 10},
                 {"Maria", 9},
                 {"Julio", 4},
                 {"Paulo", 23}
                 {"Ana", 30}
                 {"Carla", 17}};
    Pqiniq(6);
    for(int i=0; i<6; i++)
        PQinsert(i);
}

void PQinsert(int k){
    pq=malloc(sizeof(int)*(MaxN+1));
    qp=malloc(sizeof(int)*(MaxN+1));
    N=0;
}

// data[k]
void PQinsert(int k){
    pq[++N]=k; // Inserir na última posição
    qp[k]=N; // Lista de índices
    fixUp(N); // Consertar a heap
              // pq[N/2].chave < pq[N].chave
}

/*
    . data[0].chave = 50
    . Atualziar a fila de prioridades
        -> PQchange(0)
        -> Encontrar a sua posição na fila através da lista
            => data[0]->qp[0]=5->pq[qp[0]]->pq[5]=0
        -> Consertar a heap
            => fixUp(qp[0]): motivo?
            => fixDown(qp[0], N): motivo?
        -> Veja o código abaixo
*/

void PQchange(int i){
    // Atualizar o data[i] na fila
    // data[i] está na posição qp[i]
    fixUp(qp[i]);
    fixDown(qp[i], N);
}

void fixUp(int k){
    while(k>1 && less(pq[k/2], pq[k])){
        exch(pq[k], pq[k/2]);
        k=k/2;
    }
}

void fixDown(int k, int N){
    int j;
    while(2*k <= N){
        j=2*k;
        if(j<N && less(pq[j], pq[j+1]))
            j++;
        if(!less(pq[k], pq[j]))
            break;
        exch(pq[k], pq[j]);
        k=j;
    }
}

// swap das posições para data[a] e data[b]
void exch(int a, int b){
    // Atualizar lista de índices
    int k = qp[a];
    qp[a] = qp[b];
    qp[b] = k;

    // Atualizara  fila de prioridades
    pq[qp[a]] = a; // na fila pq na posição qp[a], está data [a]
    pq[qp[b]]= b;  // Na fial pq na posiçaõ qp[b], está data [b]
}

int main(){
    Item data[6] {{"José", 10},
                  {"Maria", 9},
                  {"Julio", 4},
                  {"Paulo", 23}
                  {"Ana", 30}
                  {"Carla", 17}};
    PQinit(6);
    for(int i=0; i<6; i++)
        PQinsert(i);
    data[0].chave = 50;
    PQchange(0);
    int k = PQdelmax()
    printf("%d %s\n", data[k].chave, data[k].nome);
}