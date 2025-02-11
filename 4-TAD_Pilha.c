/*
Pilha
    . Listas com coportamento LIFO (Last In, First Out): Último a entrar, primeiro a sair
    . Operações que definem o comportamento de pilha:
        -> Criar: Uma pilha vazia;
        -> Vazia: Verificar se a pilha está vazia;
        -> Empilhar: Inserir um item no topo;
        -> Desempilhar: Remover o item mais recente;
        -> Espiar: O item do topo;
    . Problemas clientes das pilhas 
        -> Desfazer/Refazer
        -> Histórico de navegadores
        -> Gerenciamento de memória: Pilhas de memória são utilizadas para armazenar todas as variáveis de um programa em execução
        -> Recursão: As chamadas de função são mantidas por pilha de memória
        -> Busca em profundidade: Percorrer uma possibilidade completa antes de analisar o próximo caminho
        -> Backtraking: Poder voltar a um ponto para refazer uma decisão
        -> Inversão: De strings
        -> Balanceamento de símbolos ([{}]): Verificação sintaxe (compiladores)
        -> Identificador de expressões/palavras (tokens): Verificação léxica (compiladores)
        -> Conversão de expressões: Infixo para prefixo, posfixo para infixo, etc.
    . Implementação com listas estáticas
        -> Operações constantes
            => Remoção no topo da pilha
            => Inserção no topo da pilha
        -> Decisão: TOPO??
    . Criação da pilha
        -> Código:
*/

// Criação da pilha

int *pilha;
int t;

void criar(int N){
    pilha=malloc(N*sizeof(int));
    t=0;
}

/*
    pilha[0...t-1] -> Tamanho 7

.                         topo da pilha
.                              |
.                              t
.      0    1   2    3    4    5  6   7   8
.   | 10 | 11 | 22 | 55 | 99 |  |   | 5 |   |
.                                     t

    . Inserção no topo da pilha - Empilhar
    . Elemento é alocado na posição indicada por t
        -> Topo da pilha é deslocado

    pilha [0...t-1] -> tamanho 7
    Inserir o elemento na pilha[t]
        Atualiza o topo t=t+1;

.                    topo da pilha
.                         |
.                         t -> t++
.      0    1   2    3    4    5  6   7   8
.   | 10 | 11 | 22 | 55 | 99 |   |   | 4 |   |
.                                     t
        -> Código:
*/

// Inserção no topo da pilha

int *pilha;
int t;

void empilha(Item y){
    pilha[t++] = y;
}

/*
    . Remoção no topo da pilha - desempilhar
    . Topo da pilha t é deslocado para mais próximo do início 
        -> Removendo o elemento da pilha
        -> Item indicado pela nova posição do topo é ignorado

    pilha [0...t-1] -> tamanho 7
    Remover o elemento na pilha[t-1]
        Atualiza o topo t=t-1;

.                    topo da pilha
.                         |
.                         t-1 <- t
.      0    1   2     3    4     5   6    7     8
.   | 10 | 11 | 22 | 55 |  99 |    |   | 5-1 |   |
.                                          t
        -> Código:
*/

// Remoção no topo da fila

int *pilha;
int t;

Item desempilha(){
    return pilha[--t];
}

// Espia e fila vazia

int *pilha;
int t;

Item espia(){
    return pilha[t-1];
}

int vazia(){
    return t == 0;
}

/*
. topo da pilha
.      |
.      t
.      0    1   2     3   4    5    6    7     8
.   |    |    |    |    |   |    |    |  0  |    |
.                                        t
    . Problema: Fila cheia, u == N, com espaços livres na fila ???
.                                      topo da pilha - pilha cheia
.                                           |
.                                           t
.      0    1   2     3    4     5     6    7     8
.   | 10 | 11 | 22 | 55 |  99 | 88 |  33 |  7  |    | 
.                                           t
*/

typedef char Item;
typedef struct{
    Item *item;
    int topo;
}Pilha;

Pilha *criar(int maxN){
    Pilha *p = malloc(sixeof(Pilha));
    p->item = malloc(maxN*sizeof(Item));
    p->topo = 0;
    return p;
}

int vazia(Pilha *p){
    return p->topo == 0;
}

void empilhar(Pilha *p, Item item){
    p->item[p->topo++] = item;
}

Item desempilha(Pilha *p){
    return p->item[--p->topo];
}

Item espiar(Pilha *p){
    return p->item[p->topo-1];
}

/*
    . Implementação com listas encadeadas
*/