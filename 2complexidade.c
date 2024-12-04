/*
Como medir algoritmos:
Tempo real de máquina como medida:
    . real: Tempo total para execução (contando todos os processos em execução)
    . user: Tempo exclusivo do processo executado
    . sys: Tempo do sistema dedicado a execução do programa
    . Problema: São dependentes de fatores como a libguagem, hardware e/ou processos de execução
    . Precisamos então de uma medida independente da máquina

Contar quantas instruções foram executadas?
    . Análise de algoritmos: Analisar a quantidade de recursos que um algoritmo precisa para resolver um problema
    . Considerar somente as operações relevantes
    . Observansdo a tendência do comportamento a medida que a instância do problema cresce, fazendo uma estimativa dos custos da operação
        -> definindo a custo dos algoritmos
        -> E a complexidade assintótica 

Função de custo F(n)
    . F(n): Valor que mensura os recursos necessários para um algoritmo processar a entrada n
    . Conta-se as operações mais relevantes e o custo do processamento da instância do problema
    . Entradas possíveis:
        -> Problemas em ordenação de vetores: tamanho do vetor
        -> Problemas em matrizes: linhas e colunas
        -> Problemas de pesquisa em memória: número de registros
        -> Problemas de grafos: ("objetos/vértices que relacionam entre si"): quantidade de vértices
        -> etc.
    . Cenários (Dependentes do tamanho da instância)
        -> Melhor caso: menor custo
        -> Caso médio: média dos custos
        -> Pior caso: maior custo
    . Exemplo: busca sequencial em vetor:
*/

int v* = {23, 22, 98, 49, 21, 5, 3, 456, 16, 83, 50, 97};

/*
    . Cenários do exemplo:
        -> Melhor caso: procura(23, v);
        -> Pior caso: procura(97,v);
        -> Caso médio: procura(21,v);
    . Aprofundando um pouco:
        -> Melhor caso: f(n) = 1 : O proucurado é o primeiro consultado
        -> Pior caso: f(n) = n : Procurado é o último consultado
        -> Caso médio: f(n) = (n+1)/2 : Examina cerca de metade dos registros
            => Pi é a probabilidade de encontrar o elemento na posição i
            => Todos tem o mesmo Pi = 1/n, 1 < i < n.
            => f(n) = Soma do número de comparações X probabilidade
                f(n) = 1.(1/n) + 2.(1/n) + ... + n.(1/n)
                .    = (1/n).(1 + 2 + 3 + ... + n)
                .    = (1/n).(n.(n+1)/2) = (n+1)/2
        -> Custos em geral se referem ao consumo de tempo no pior caso 

Função custo: Valores comuns
f(n) = c : Constante
    . Valor constante: c > 0
    . Independem o tamanho de n
    . As instruções são executadas um número fixo de vezes
        -> Atribuições, operações aritméticas
        -> Comando de decisões, comparações
        -> Acessos a memória
    . Exemplo: f(n) =~ 6
*/

int operacao(int n, int a, char op){
    int r = 0; // Atribuição
    
    if(op == '+') // Comparação
        r = n + a; 
    else if(op == '-') // Comparação
        r = n - a;
    else if(op == '*') // Comparação + atribuição
        r = n * a;
    return r;
}

/*
Ainda sobre valores constantes:
    . Listas estáticas (array)
        -> Acesso aleatório e direto pelo índice/posição
        -> Inserção
    . Listas encadeadas
        -> Remoção de um nó específico em listas duplamente encadeadas
        -> Inserção após um nó específico
        -> Inserção antes de um nó específico em listas duplamente encadeadas
    . Exemplo:
*/

int busca(int n, int *v, int x){
    int i;
    for(i=0; i<n && v[i]!=x; i++);
    return i;
}

// No melhor caso O(n) = 1 (constante), no pior caso O(n) = n (linear)

/*
f(n) = a*n+b : Linear
    . Função polinomial de primeiro grau: a>0 e b custo das constantes
    . Realiza-se um pequeno trabalho sobre cada elemneto da entrada
    . n processamentos de custos constantes
    . Cresce a uma taxa constante
    . n entradas, n saídas
    . Anel ou laço
        -> (Tempos comandos internos + avaliação da consição) X número de interações
    . Exemplo 
*/

int pesquisa(int x, int n, int v[]){
    for(int i=0; i<n && v[i]!=x; i++)
    return i;
}

int soma(long n){
    int r=0;
    while (n>0)
    {
        r += n%10;
        n /= 10;
    }
    
}

/*
Ainda sobre o custo linear
    . Listas estáticas (array)
        -> Buscas/remoções no meio da lista
    . Listas encadeadas
        -> Busca sequencial
        -> Remoção de um nó específico em listas simplesmente encadeadas
        -> Inserção de um nó específico em listas simplesmente encadeadas
    . Exemplo:
*/
typedef int Item;

typedef struct{
    int tam;
    no *prox;
    no *ultimo;
}cabeca;

typedef struct node no; 
struct node {
    Item info; 
    no *prox; 
};

int busca(int n, int *v, int x){
    int i;
    for(i=0; i<n && v[i]!=x; i++);
    return i;
}

// Linear no pior caso e no caso médio

no *buscar(cabeca *lista, Item x){
    no *a = NULL;
    for(a=lista->prox; a && a->info!=x; a=a->prox);
    return a;
}

// Linear no pior caso e no caso médio

/*
Ainda sobre a complexidade linear
Recorrências
    . Resolver uma recorrência: encontrar uma fórmula que calcule diretamente a função
    . Sem subexpressões da forma: +...+, ou contendo sinais de sequências
    . Resultando em combinações de:
        -> Funções polinomiais: f(x) = An*x^n + An-1*x^n-1 + ... + A1*x+A0
            => n: um número positivo ou nulo
            => x: variável
            =>a's: coeficientes
        -> Funções exponenciais: f(x) = b^x
        -> Funções logarítmicas: log(x)
    . Exemplo:
*/  

// Fatorial iterativo
// f(n) =~ c*n, sendo c uma constante
int fatorial(int n){
    int fat = 1;

    while (n>0) // n..0
        fat += n--; // constante -> n vezes
    
    return fat;
}

// Fatorial recursivo: Fórmula fechada?
int fatorial2(int n){
    if(n==1 || n==0)
        return 1; // Constante
    return n*fatorial2(n-1); // Custo para entrada n-1
}

// f(n) = c + f(n+1)
//      = c + c + f(n-2)
//      = c + c + c + f(n-3)
//            ....
//      = c * i + f(n-i)
//      = c * n + f(1), i = n - 1 (passa 1 para lá e i para cá, fica)
//      = c * (n-1) + c = c * n

/*
f(n) = a*n^2+b*n+c: Quadrática
    . Função polinomial do segundo grau
    . Para cada n processa-ce cerca de n itens
    . n processamentos de custo linear
    . Se n dobra, o tempo quadruplica
    . Valor depende de uma constante exponencial fixa
    . Caracteriza-se por aninhamento de interações
    . Exemplo:
*/

void ordenacao(int v[], int n){
    for(int i=1; i<n; i++){
        for(int j=1; j>0 && v[j]<v[j-1]; j--){ // Comparar com os antecessores
    
    
        troca(v[j], v[j-1]); // Posicionar
        }
    }
}

// Versão recursiva

void ordenacao(int v[], int n){
    if (n<=1)
        return;
    ordenacao(v, n-1); // f(n-1)
    
    for(int j=n-1; j>0 && v[j]<v[j-1]; j--) // n-1
        troca(v[j], v[j-1]); // constante
}

// Fórmula fechada para encontrar o custo
// f(n) =~ f(n-1) + (n-1) + c
//      =~ f(n-2) + (n-2) + c + (n-1) + c
//      =~ f(n-2) + (n-2) + (n-1) + 2*c
//      =~ f(n-3) + (n-3) + (n-2) + (n-1) + 3*c
//      =~ f(n-i) + (n-i) + ... + (n-2) + (n-1) + i*c: n - i = 1, i = n - 1
//                  .............
//      =~ f(1) + (n-(n-1)) + ... + (n-1) + (n-1) *c
//      =~ c + 1 + 2 + ... + (n-1) + (n-1) * c
//      =~ n*c + ((1+(n-1))*(n-1))/2
//      =~ n*c + (n^2)/2 + n/2
//      =~ (n^2)/2 + n/2 + n * c

/*
f(n) = a*n^3+b*n^2+c*n+d: Cúbica
    . Exemplo
*/

// Versão cúbica 
// Se n cresce, a entrada multiplica
void multiplica_matrizes(int A[3][3], int B[3][3], int C[3][3]){
    for(int i=0; i<3; i++){ // n
        for(int j=0; j<3; j++){ // n
            C[i][j];
            for(int h=0; k<3; k++){
                C[i][j] += A[i][k] * B[k][j]; // Cij = Aik * Bkj
            }
        }
    }
    imprime_matriz(c);
}

// Analizar custos slide 21 e 22

/*
f(n) = K^n : Exponencial
    . Problemas resolvidos com força bruta
        -> Procurar a solução verificando as combinações das possibilidades
        -> As chamadas recursivas aumentam múltiplas vezes por chamadas
        -> Alcance lento das condições de parada ocasionando muitas chamadas recursivas
        -> n multiplicações sucessivas de uma base (número fixo de chamadas recursivas)
    . Quando n é 20, o tempo é  cerca de 1 milhão
    . Como por exemplo a tabela verdade
    . Exemplo:
*/

char T[2] = {'V', 'F'};

// Terceiro precisa de 2^2^2 instruções  
for(int a=0; a<2; a++){
    // Segunda chamada precisa de 2^2 instruções
    for(int b=0; b<2; b++){
        // Primeira chamada precisa de 2 instruções
        for(int c=0; c<2; c++){
            printf("%c %c %c", T[a], T[B], T[c]);
        }
    }
}

//  . Exemplo 2

int p(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    return p(n-1) + p(n-2);
}

//  . Exemplo 3 : Fibonacci modificado - custo piorado

int p(int n){
    if(n==0 || n==1)
        return n;
    return p(n-1) + p(n-1);
}

// Fórmula fechada para achar o custo
// f(n) =~ 2*f(n-1)
//      =~ 2*(2*f(n-2))
//      =~ 2*(2*(2*f(n-3)))
//(Simplificando) (2^2)*(2*f(n-3)))
//      =~ (2^i)*f(n-i), i = n-1
//      =~ (2^n-1)*f(1)

/*
F(n) = n! : Fatorial
    . Problemas resolvidos com força bruta
        -> Proucurar a solução verificando todas as possibilidades
        -> Combinatória : Custo fatorial
        -> Cada chamada usa diversas (linear) chamadas recursivas
        -> Alcance lento da condição de parada gerando muitas chamadas recursivas
    . Problema do caxeiro viajante : Proucura um circuito que tenha a menor distância, começando em qualquer cidade, entre várias passando em cada cidade e voltando para a cidade de saída
    . Para resolver
        -> Exatos : Basicamente analisam todas as possibilidades (força bruta)
            => Existe o algoritmo Held-Karp com custo exponencial ((n^2)*(2^n))
        -> Heurísticos através de aluma figura heurística (estratégia), obtem-se soluções aproximadadas
    . Observação: É um programa verificado em tempo polinomial; Dado uma sequência de cidades, verificar se passa por todas pelo menos uma vez
    . Exemplo:
*/

void anagram(char str[], int k){
    char tmp;
    int i, len = strlen(str);
    if(k==len)
        printf("%s\n", str);
    else{
        // Cada chamada gera múltiplas chamadas recursivas
        for(i=k; i<len; i++){
            swap_char(str, k, i); // Uma troca
            anagram(str, k+1); // Próximas permutas
            swap_char(str, i, k); // Volta ao original
        }
    }
}

void subsets(int v[], int i, int n, int sub[], int fim){
    for(int j=0; j<fim; j++)
        printf("%d\n", sub[j]);
    printf("\n");

    for(; i<n; i++){ //n
        sub[fim] = v[i];
        subsets(v, i+1, n, sub, fim+1); // n-1
    }
}

//f(n) = n*f(n-1)
//     = n*(n-1)*f(n-2)
//     = n*(n-1)*(n-2)*...*1
//     = n!




