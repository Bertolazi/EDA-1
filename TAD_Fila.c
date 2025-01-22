#include <stdlib.h>
#include <stdio.h>
/*
Tipos abstratos de dados:
Fila:
    . O que é uma fila? 
        -> É o alinhamento de uma série de indivíduos ou objetos em sequência, de modo que um esteja imediatamente atrás do outro.
    . Como funcionaa o procedimento/atendimento de uma fila?
        -> Os dados que estão na frente são processados primeiro.
    . Funcionam pelo esquema FIFO (first in  first out), ou seja, primeiro a entrar também é o primeiro a sair.
    . Justo: Ordem de chegada/infileiramento
        -> Processamento de dados obedecendo a ordem de chegada:
            => Sistemas de inscrições;
            => Julgadores automáticos.
        -> Fila de impressão;
        -> Fila de processos no sistema operacional;
        -> Gravação de mídia (ordem dos dados importa);
        -> Busca: Varredurapelos mais próximos primeiro.
    . Inserção no fim, remoções no início.
    . Complexidade constante.
    . Operações básicas:
        -> vazia;
        -> tamanho;
        -> primeiro-busca_início;
        -> ultimo-busca_fim;
        -> enfilera-insere_fim;
        -> desenfilera-remove_inicio;
Fila: Implementação com lista estática:
    . Operações constantes:
        -> Remoção no início da fila;
        -> inserção no fim da fila.
        -> Exemplo (Criação daa fila):
*/

// Criação da FILA 

#define N 7

int fila[N];
int p, u;

void criar_fila(){
    p = u = 0; // Criamos a fila iniciando o início e o fim dela no primeiro espaço do vetor, já que ela está vazia
}

/*
Explicação:
    . Acima temos uma a criação de uma fila[p...u-1]  (7 posições)

    Início e fim da fila
       |
      p=u
       0    1    2    3    4    5    6    7    8      
    -------------------------------------------------  
    |    |    |    |    |    |    |    |  0  |  0  |
    -------------------------------------------------
.                                         p     u
*/

// Fila vazia 

#define N 7

int fila[N];
int p, u;

int vazia(){
    return p == u; // Como dito anteriormente na criação da lista se p e u estão na mesma posição ela está vazia
}

/*
Explicação:
    . Quando criamos a fila, nela criamos duas variáveis, o p (primeiro) e o u (último), ambas servem para indicar o índice do vetor onde está o o primeiro ou o último elemento 
    respectivamente, com isso se o primeiro elemento e o último estão na mesma posição nenhum elemento foi adicionado nessa fila.

.              Início e fim da fila
.               |
.              p=u
.     0    1    2    3    4    5    6    7    8      
    -----------------------------------------------  
    |    |    |    |    |    |    |    |    |    |
    -----------------------------------------------

Remoção no início da fila:
    . Desenfileirar
    . O início da fila (p) é deslocado para mais próximo do fim
        -> "Removendo" o elemento da fila
    . Veja o exemplo abaixo:

.         Início da fila      Fim da fila
.          |                   | 
.          p = p+1             u
.     0    1    2    3    4    5     6    7     8      
    -------------------------------------------------  
    |    | 11 | 22 | 55 | 99 |    |    | 1+1 |  5  |
    -------------------------------------------------
*/

// Remoção no início da fila

#define N 7

int fila[N];
int p, u;

int desenfilera(){
    return fila[p++]; // Incrementamos 1 no p, assim eliminamos o primiro "item" da fila
    // p++ ou ++p? 
    // p++ geralmente é usado para garantir que você está utilizando o elemento correto da fila antes de incrementar o p, usar o ++p poderia levar a um acesso incorreto dos elementos
    // da fila.
}

/*
Inserção no fim da fila:
    . Enfileirar
    . Elemento é colocado na posição indicada por u
        -> Fim da fila é deslocado
    . Veja o exemplo abaixo:

.           Início da fila     Fim da fila
.                |              |  
.                p              u = u+1
       0    1    2    3    4    5    6    7    8      9      
    ------------------------------------------------------  
    |    | 11 | 22 | 55 | 99 | 88 |    |  2  | 5+1 |    |
    ------------------------------------------------------
.                                         p     u

*/

// Inserção no final da fila

#define N 7

int fila[N];
int p, u;

void enfilera(int y){
    fila[u++] = y; // Incrementamos o u, para dicionar mais um item na lista e adicionamos o item y
}

/*
Fila cheia: 
    . u == N
.           Início da fila               Fim da fila - "Fila cheia"
.                |                        |  
.                p                        u 
       0    1    2    3    4    5    6    7    8      9      
    ------------------------------------------------------  
    |    |    | 22 | 55 | 99 | 88 | 33 |  2  | 7 |    |
    ------------------------------------------------------
.                                   N-1   p     u
    
    . Se inserir em uma lista cheia
        -> Ocorre transbordamento
        -> Como mostra no exemplo abaixo:   

        . fila[u] = 4
        . fila [7] = 4 como 7 > N-1, ocorre transbordamento
        .
        .           Início da fila                 Fim da fila - "Fila cheia"
        .                |                          |  
        .                p                          u 
        .      0    1    2    3    4    5    6      7     8    9      
            ------------------------------------------------------  
            |    |    | 22 | 55 | 99 | 88 | 33 |  2 -> 4 | 7 |    |
            ------------------------------------------------------
        .                                   N-1     p     u
        .                                           |
        .                                          Invadiu a área de p

        .                  Início da fila      Fim da fila
        .                   |                   |  
        .                   p                   u 
        . 0    1    2    3    4    5    6     7      8    9      
        ------------------------------------------------------  
        |    |    | 22 | 55 | 99 | 88 | 33 |  4  |  7  |    |
        ------------------------------------------------------
        .                               N-1   p     u

    . Problema: E se a lista cheia, u == N, com espaços livres?
    . Solução: Chegou ao fim, volta para o primeiro (circular).
        -> Como mostra o exemplo abaixo:
        -> fila[u] = 33 


        .          Início da fila      Fim da fila
        .           |                   |  
        .           p                   u -> (u+1==N? u=0)
        . 0    1    2    3    4    5    6     7        8      9      
        -----------------------------------------------------------  
        |    |    | 22 | 55 | 99 | 88 | 33 |  2  |  6 -> 0  |    |
        -----------------------------------------------------------
        .                               N-1   p     u

Fila: Implementação com lista estática circular:
    . Problema: E se a fila cheia, u == N, tem espaços livres
    . Solução: chegou ao fim, volta para o primeiro (circular)
        -> Veja os exemplos de código abaixo:
    */

// Enfilera 

void enfilera(int y){
    fila[u++] = y;
    if(u==N) // Se u = N, u iguala a zero, assim temos uma solução circular
    u=0;        // <=
}

// Desenfilera

int desenfilera(){
    int x=fila[p++];
    if(p==N) // O mesmo ocorre com p
    p=0;        // <=
    return x;
}

/*
Lista estática circular - vazia X cheia
    . Decisão: posição entes de p fica vazio (diferenciar cheia e vazia)
        -> Fila cheia:
            => u+1==p ou (u+1==N e p==0)
            => Ou seja, se (0+1)%N==p
            (0+1)%7 = 1 | (1+1)&7 = 2 | (2+1)%7 = 3
            (3+1)%7 = 4 | (4+1)%7 = 5 | (5+1)%7 = 6
            (6+1)%7 = 0
        -> Fila vazia: u==p
        -> Veja o exemplo a abaixo
            => fila[p...u-1] : N=7
            => cheia (1+1)%7 = 2 = p

            .     Fim  Início
            .      |    |  
            .      u = u+1=p                  
            . 0     1    2    3    4    5    6    7     8     9      
            -----------------------------------------------------------  
            | 44 |    | 22 | 55 | 99 | 88 | 33 |  2  |  1  |    |
            -----------------------------------------------------------
            .                               N-1   p     u
*/

// Implementação com lista estática - possibilidade de ter várias filas

typedef int Item;
typedef struct 
{
    Item *item;
    int primeiro, ultimo;
}Fila;

Fila *criar(int maxN){
    Fila *p = malloc(sizeof(Fila));     // Aloca espaço para a fila
    p->item = malloc(maxN*sizeof(Item));  // Aloca espaço dentro da fila para o Item
    p->primeiro = p->ultimo = 0;        // Faz como vimos nas filas com listas estáticas, iguala o primeiro ao último, indicando que a lista ta vazia
    return p;                          // Retorna o pomteiro da lista criada
}

int vazia(Fila *f){
    return f->primeiro == f->ultimo; // Se o ponteiro que aponta para o primeiro for o mesmo que aponta para o último a lista está vazia
}

int desenfilera(Fila *f){
    return f->item[f->primeiro++];  // Nessa função pelo esquema de FIFO, ela tira o primeiro item alocado e incremenat para o primeiro agora ser o segundo
}

void enfilera(Fila *f, int y){
    f->item[f->ultimo++] = y;   // Nessa função adicionamos um inteiro y que será o item do novo último, que será adicionado depois do antigo último
}

void imprime(Fila *f){
    printf("\nFila p=%d e u=%d\n", f->primeiro, f->ultimo);
    for(int i=f->primeiro; i<f->ultimo; i++){
        printf("F[%d]", i);
    }
    printf("\n");
    for (int i=f->primeiro; i<f->ultimo;i++){
        printf(" %3d  |", f->item[i]);
    }
    printf("\n");
}

int main(){
    printf("\n\n Criando a dila e enfileirando 10 elementos\n");
    Fila *fila1 = criar(100);
    for(int i=0; i<10; i++){
        enfilera(fila1, i);
    }
    imprime(fila1);
    printf("\n\nDesenfileirando os 3 primeiros elementos\n");
    for(int i = fila1->primeiro; i<3; i++){
        desenfilera(fila1);
    }
    Fila *fila2 = criar(400);
    // ...
    return 0;
}

/* 
Lista estática com redimensionamento
    . Problema: Fila cheia u == N, com espaços livres na fila
    . Solução: redimensionamento da lista que armazena a fila
    . Implementação:
*/

// Lista estática com redimensionamnento

void redimensiona (void){
    N *= 2;
    fila = realloc(fila, N*sizeof(int));
}

// Reajustar a variável p e u de acordo 
void redimensiona(){
    N *= 2; // Evitar novos redimensionamentos
    int *novo = malloc(N*sizeof(int));
    int j=0;
    for(int i=p; i<u, i++, j++)
        novo[j] = fila[i];
    p = 0;
    u = j;
    free(fila);
    fila = novo;
}
