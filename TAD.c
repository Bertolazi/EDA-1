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
    return p == u;
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
    return fila[p++]; // p++ ou ++p?
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
    fila[u++] = y;
}

/*
Fila cheia: 
    . u == N



*/