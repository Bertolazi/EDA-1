#include <stddef.h> 
#include <stdio.h> 
#include <sys/queue.h>
#include <stdlib.h>
/*
Estruturas de dados elementares:
    . Estrutura de dados
        -> Organizam uma coleção de dados
        -> Possume um conjunto de operações
    . Elememtar
        -> Utilizados por outras estruturas
    . Estrutura elementar: Lista.

Lista estática:
    . Conjunto de um mesmo tipo de dado
    . Espaço consecutivo na memória RAM
    . Acesso aleatório: Qualquer posição pode ser acessada facilmente através de um index
    . Nome -> Corressponde a um endereço de memória
    . Tamanho fixo (stack), ou alocado dinamicamente (heap)
    . Podem ser chamados de arrays, ou como melhor conecemos vetores
    . Vantagem: Fácil acesso
    . Desvatagem: Difícil manipulação
    . Alternativa: Listas encadeadas

Listas simplesmente encadeadas
    . Conjunto de nós ou células
    . Cada nó é um tipo de contêiner que armazena: item + link (para outro nó)
    . Alocação conforme a necessidade
    . Mais adequado para manipulação do que para acessos
        -> Maior eficiência para rearranjar os itens (reapontamentos)
        -> Não tem acesso direto aos itens pela sua posição
    . Operações
        -> Buscar
        -> Inserir
        -> Remover
    Vamos ver agora um pouco dos códigos necesssários para criar uma lista simplesmente encadeada. Começaremos com:
    => Estrutura dos nós da lista:
*/

// typedef struct item Item
typedef int Item; // Definimos o tipo Item para utilizar em nosso código

typedef struct node no; // Criamos uma macro para não ter que escrever struct node toda hora e podermos escrever somente no
struct node {
    Item info; // Um tipo int interno para ser o que esse nó armazena
    no *prox; // Um ponteiro apontando para o próximo elemneto da lista
};

/*
    Vamos ver os tipos de listas encadeadas
*/

/*
    . Fim da lista: Último nó aponta para NULL
    . TIPO 1
    . Início sem cabeça
        -> Primeiro nó é o primeiro item da lista
        -> Ponteiro (auxiliar) pode armazenar o endereço do primeiro nó
        -> Com ou sem cauda
    => Como fazer o primeiro nó da lista:
*/
#include <stdlib.h> 

no *lista = NULL;

no *novo = malloc(sizeof(no));
novo->prox = NULL; 
novo->info = 2;

lista = novo;
 
/*
    . Fim da lista: Último nó aponta para NULL
    . TIPO 2
    . Início com cabeça do tipo nó:
        -> Conteúdo é ignorado
        -> Elementos da lista: A partir do segundo nó
        -> Com ou sem cauda
    => Como fazer o primeiro nó da lista:
*/

no *lista = malloc(sizeof(no));

no *novo = (malloc(sizeof(no)))
novo->prox = NULL;
novo->info =2;

lista->prox = novo;

/* 
    . Fim da lista: último nó aponta para NULL
    . TIPO 3
    . Início com cabeça, do tipo cabeca (específico):
        -> Aproveita para guardar os metadados
        -> Tamanho da lista e fim da lista (cauda), por exemplo
        -> Elementos da lista: A partir do segundo nó
    => Estrutura do tipo cabeca:
*/

typedef struct{
    int tam;
    no *prox;
    no *ultimo;
}cabeca;

/*
    Agora vamos simular algumas operações básicas:
*/

typedef struct node no;
typedef int Item;

struct node{
    Item info;
    no *prox;
};

typedef struct head cabeca

struct head{
    int tamanho;
    no *prox;
    no *ultimo;
};

// Protótipo operações básicas

cabeca *criar_lista();
no *criar_no(Item);
int vazia(cabeca *);
int tamanho(cabeca*);
void inserir_depois(cabeca *, no *, no *);
void inserir_inicio(cabeca *, no *);
void inserir_fim(cabeca *, no *);
no *remover_inicio(cabeca *);
no *remover_fim(cabeca *);
no *remover_no(cabeca *, no *);
no *buscar(cabeca *, Item);

// Criar lista com cabeça

cabeca *criar_lista(){
    cabeca *le = malloc(sizeof(cabeca))
    le->tamanho = 0;
    le->prox = NULL;
    le->ultimo = NULL;

    return le;
}

// Criar nó dentro da lista

no *criar_no(Item x){
    no *novo = malloc(sizeof(no));
    novo->prox = NULL;
    novo->info = x;
    return novo;
}

// Se a lista estiver vazia 

int vazia(cabeca *lista){
    return lista->prox = NULL;
}

no *buscar(cabeca *lista, Item x){
    no *a = NULL;
    for(a=lista->prox; a && a->info!=x; a = a->prox);
    return a;
}

void inserir_inicio(cabeca *lista, no *elem){
    elem->prox = lista->prox // ponteiro do proximo elemento depois da cebeça agora é depois desse nove elemento alocado
    lista->prox = elem; // dizemos que o próximo depois da lista é esse novo elemento
    // metadados 
    lista->tamanho++; // incrementa +1 no tamanho da lista
    if(elem->prox == NULL) 
    lista->ultimo = elem; // Se não tiver nada depois desse elem ele é o último nó da lista

}

void inserir_depois(cabeca *lista, no *ref, no *elem){
    elem->prox = ref->prox; // Para não digamos "quebrar" a lista, salvamos o endereço do ponteiro do proximo elemento atual para ser o próximo do elemento inserido
    ref->prox = elem; // Igual no caso anterior salvamos o depois do elemento de referência nosso no inserido.
    // metadados
    lista->tamano++; // Incremento no tamanho da lista no dado da cabeça
    if(elem->prox == NULL)
    lista->ultimo = elem; // Se não tiver apontando para nenhum ponteiro depois, ele é o último elemento da lista, atualiza as informações da cabeça.
}

void inserir_fim(cabeca *lista, no *ref, no *elem){
    if(vazia(lista))
    lista->prox = elem; // Se a lista estiver vazia, o elemento inserido no fim também é o primeiro elemento
    
    lista->ultimo = elem; // Atualiza o metadado do último elemento 
    elem->prox = NULL;

    lista->tamanho++; // E encrementa no tamanho da lista 
    // OU
    // if(vazia(lista))
    //      return inserir_inicio(lista, elem);
    // inserir_depois(lista, lista->ultimo, elem);
}

void remover_inicio(cabeca *lista){
    if(vazia(lista))
    return; // Se a lista ta vazia não tem o que remover.

    no *lixo = lista->prox; // Armazena o nó que será removido
    lista->prox = lixo->prox; // Atualiza o ponteiro da lista para o próximo nó

    lista->tamanho--; // Retira um de tamanho, pois removemos um nó da lista
    if(vazia(lista))
    lista->ultimo = NULL; // Se a lista estiver vazia, lista->ultimo aponta para NULL
    // free(lixo)????
}

void remover_no(cabeca *lista, no *lixo){
    if(lista->prox == lixo)
    lista->prox = lixo->prox; // retun remover_inicio(lista); // É o mesmo caso da função anterior
    no *ant;
    for(ant = lista->prox; ant != NULL && ant->prox != lixo; ant = ant->prox); // Percorredo primeiro nó da lista até, que ant seja igual a NULL (chegou n final da lista),
                                                                               // Ou ant->prox seja igual a lixo (achou o elemneto a ser removido)
    if(ant){ // Verifica se o ant foi encontrado
        ant->prox = lixo->prox; // O nó anterior do lixo aponta para o posterior ao lixo.
        lista->tamanho--;  // Retiramos um do tamanho da lista.
        if(ant->prox == NULL) 
        lista->ultimo = ant; // Se não houver posterior ao lixo, o anterior ao lixo é o novo ultimo nó da lista 
    }
    // free(lixo)?????
}