#include <stdlib.h>
#include <stdio.h>
#include "1Listas_encadeadas.h"

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
free(no2);
    }
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
    N *= 2; // Dobra o tamnaho da fila
    fila = realloc(fila, N*sizeof(int)); // Usa o realloc para redimensionar o tamnho em bytes da fila usando o tamnho de N
}

// Reajustar a variável p e u de acordo 
void redimensiona(){
    N *= 2; // Evitar novos redimensionamentos
    int *novo = malloc(N*sizeof(int)); // Cria uma nova fila alocando na quantidade de N
    int j=0;  
    for(int i=p; i<u; i++, j++) //  Faz um loop que vai do rimeiro ao último índice da fila 
        novo[j] = fila[i]; // Copia os índices em um novo array assim esses dados não são perdidos
    p = 0; // reseta o p para zero onde a fila volta a começar
    u = j; // Atualiza o u para j, onde a fila termina agora já que está com o dobro do tamanho
    free(fila); // Liberaespaço de memória alocado na fila original
    fila = novo; // Atribui a fila ao ovo indicando agora um array com o dobro do tamanho
} // Conclusão a função de cima atribui mais espaços dos arrays e a função de baixo realoca os espaços dnos lugares corretos

/*
Implementação com lista encadeada:
    . Agora vamos ver a aplicação de filas com listas encadeadas
    . Item desenfilera(cabeca *lista)
        -> Remover o elemento mais velho => Início da fila
        -> Acesso ao primeiro elemento => constante
    . Item enfilera(cabeca *lista, no *novo)
        -> Ineserir no final da lista
        -> Acesso ao último elemento => constante
    . Aceso ao primeiro elemento: Todas as listas => constante
    . Acesso ao último elemento 
        -> Lista simplesmente/duplamente escadeada com cabeça 
            => Metadados->lista->ultimo
        -> Lista duplamente encadeada circular
            => no *ultimo = lista->prox->ant 
                ~> Anterior do primeiro
        -> Lista simplesmente encadeada circular modificada
            => Último elemento apontar para a cabeça (mesmo tipo dos outros nós)
            => Inserir na cabeça
            => Criar uma nova cabeça que aponta para o que a cabeça velha aponta
            => Velha cabeça/novo elemento: Aponta para??
            => Implementar
        -> Lista simplesmente encadeada com cauda
            => Podemos utilizar um apontador direto para cauda        
*/ 

// Criar e enfileirar
void enfilera(cabeca *lista, Item x){
    no *novo = criar_no(x);
    if(novo){
        if(vazia(lista)) 
            lista->prox = novo;
        else
            lista->ultimo->prox; 
        lista->ultimo = novo; // Inserir no fim 
        novo->prox = NULL;

    }
}

// Desenfilera e devolve os itens
Item desenfilera(cabeca *lista){
    no *lixo = lista->prox; // Remover_inicio
    lista->prox = lixo_prox;
    if(vazia(lista))
        lista->ultimo = NULL;
    lista->tam--;
    Item x = lixo->info;
    free(lixo);
    return x;
}

/*
Exemplo com fila com listas encadeadas
    . Vivo ou morto
        -> Vários participantes (números inteiros) em uma fila única
        -> Ordem "vivo" (1-levantar), "morto" (0-abaixar)
        -> O participante que errar a ordem é retirado fazendo a fila andar
        -> O jogo continua até que tenham apenas um participante (vencedor)
    . Entrada
        -> P e R: Número inicial de participantes (códigos de i a P) e rodadas de ordem respectivamente
        -> P códigos de participantes que estão na ordem que estão na fila
        -> Cada uma das R linhas seguidas:
            => Um número inteiro N indicando o número de participantes da rodada
            => Um número inteiro J (0/morto ou 1/vivo)
            => N números inteiros representado a ação (0/morto ou 1/vivo) do participante na i-ésima posição da fila
    . Saída: Código do vencedor
    . Exemplo:
        -> Entrada: 5 4
        .           3 2 1 4 5
        .           5 1 1 1 1 1 1
        .           5 0 0 1 0 1 0
        .           3 0 0 1 0
        .           2 1 0 1
        -> Saída: 5
*/

criar_fila();

while (participantes--) // Itera até que todos os participantes estejam enfileirados
{
    scanf("%d", &i);    //Lê o identificador do particiapnte
    enfilera(i);    // Insere o participante na fila
}

while(rodadas--) // Processa todas as rodadas que vão acontecer
{
    scanf("%d %d", &n, &e); // Coloca o número de participantes e o comando realizado
    while (n--) // Processa os n participantes da jogada
    {
        scanf("%d", %s); // Para cada partcipanate colocamos uma jogada para o mesmo
        x = desenfilera(); // Desenfilera o participante a menos que...
        if(s == e){
            enfilera(x) // o cmando relizado for igual ao comando pedido
        }
    }   
}
printf("%d\n", desenfilera()); // Após todas as jogadas desenfilera o último elemento da fila e imprime na tela seu identificador

/*
Exemplo 2
    . Campo minado: Abrir casas
    . A partir das posições 1 e c abrir todos os espaços adjacentes
    . Enfileirar os adjacentes para posterior tratamento
*/

// Resposta do exemplo
int abrir_mapa(int m, int n, struct area campo[m][n], int l, int c){
    campo[l][c].visivel = 1;
    if(campo[l][c].item == -1)
        return campo[l][c].item; // -1 perdeu
    struct head fila;
    struct celula *no = malloc(sizeof(struct celula));
    no->l = l;
    no->c = c;
    STAILQ_INIT(&fila);
    STAILQ_ISERT_TAIL(&fila, no, prox);
    while (!STAIL_EMPTY(&fila))
    {
        struct celula *no2 = STAILQ_FIRST(&fila);
        STAILQ_REMOVE_HEAD(&fila, prox);
        if(campo[no->l][no2->c].item==0){
            for(int i=no2->l-1; i<=no2->l+1; i++){
                for(int j=no2->c-1; j<=no2->c+1; j++){
                    if(i>=0 && i<m && j>=0 && j<n && campo[i][j].visivel==0){
                        campo[i][j].visivel = 1;
                        struct celula *no3 = malloc(sizeof no3);
                        no3->1=i; 
                        no3->c=j;
                        STAILQ_INSERT_TAIL(&fila, no3, prox);
                    }
                }
            }
        }
        free(no2);
    }
    return 0;
}