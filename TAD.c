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

#define N 7

int fila[N];
int p, u;

void criar_fila(){
    p = u = 0; // Criamos a fila iniciando o início e o fim dela no primeiro espaço do vetor, já que ela está vazia
}