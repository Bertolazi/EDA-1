/*
Counting sort
    . Linearítmicos
        -> O(n.logn)
        -> Ordenação pela comparação do valor das chaves
    . Lineares
        -> O(n)
        -> Ordenação pela comparação das partes que foram as chaves
    . Ordenação por contagem da frequência das chaves
    . Etapa 1:
        -> Contar as frequências de cada chave
        -> Calcular as posições através das freqências
        -> Distribuir chaves
    . Para chaves com valor de 0 até R-1
        -> Utiliza-se: count[R+1]
    . Para cada chave i
        -> count[i+1] = frequÊncia da chave i
    . Para cada chave
        -> count[0] = posição inicial
        -> count[1] = frequência da chave 0
        -> count[2] = frequência da chave 1
        -> count[R] = frequência da chave R-1
    . R = 5 (Intervalo 0 - 4)
            0  1  2  3  4
    v[5] = [2  3  3  4  1]

                  0  1  2  3  4  5
    count[R+1] = [0  0  0  0  0  0]

            0  1  2  3  4
    v[0] = [2  3  3  4  1]

                     0  1  2   3   4  5
    count[v[0]+1] = [0  0  0  0+1  0  0]

            0  1  2  3  4
    v[1] = [2  3  3  4  1]

                     0  1  2  3   4   5
    count[v[1]+1] = [0  0  0  0  0+1  0]

            0  1  2  3  4
    v[2] = [2  3  3  4  1]

                     0  1  2  3   4   5
    count[v[2]+1] = [0  0  0  1  1+1  0]

            0  1  2  3  4
    v[2] = [2  3  3  4  1]

                     0  1  2  3  4   5
    count[v[2]+1] = [0  0  0  1  2  0+1]

            0  1  2  3  4
    v[4] = [2  3  3  4  1]

                     0  1   2   3  4  5
    count[v[4]+1] = [0  0  0+1  1  2  1]

            0  1  2  3  4
    v[5] = [2  3  3  4  1]

                     0  1  2  3  4  5
    count[v[5]+1] = [0  0  1  1  2  1]
*/

// memset(count, 0, sizeof(int*(R+1)))
for(int i=0; i<=R; i++){
    count[i] = 0;
}
for(int j=l; i<=r; i++){
    count[v[i]+1] = count[v[i]+1]+1;
    // count[v[i]+1]++;
}

/*
    . Etapa 2:
        -> Vetor de frequências
            => count[i] = quantidade de chaves i-1
        -> Calcular posição de i
            => Calcular a posição de i
            => count[i] = count[i] + count[i-1] + ... + count[0]
            => counr[i] = distância de 0 até a chave i (posição de i)
    . Exemplos
        -> R = 5 (Intervalo 0 - 4) 
            => count[k] = (<= k-1)
            => count[k] = (< k-1) + (= k-1)
            => count[k] = count[k-1] + count[k]
        -> Posição inicial da primeira chave 0

        chave  0   1   2   3   4   5
               i  =0  =1  =2  =3  =4
        count[ 0   0   1   1   2   1 ]  Posição inicial

        chave  0   1   2   3   4   5
               i  =0  =1  =2  =3  =4
        count[ 0   0   1   1   2   1 ]  Chaves <= 0
              |__+__|
        
        -> Posição inicial da primeira chave 1

        chave  0    1   2   3   4   5
               i  <=0  =1  =2  =3  =4
        count[ 0    0   1   1   2   1 ]  Chaves <= 0
                    |

        -> Posição iniciala da primeira chave 2

        chave  0    1   2   3   4   5
               i  <=0  =1  =2  =3  =4
        count[ 0    0   1   1   2   1 ]  Chaves <= 1
                   |__+__|

        chave  0    1    2   3   4   5
               i  <=0   <=1  =2  =3  =4
        count[ 0    0    1   1   2   1 ]  Chaves <= 1
                         |
        
        -> Posição iniciala da primeira chave 3

        chave  0    1    2   3   4   5
               i  <=0   <=1  =2  =3  =4
        count[ 0    0    1   1   2   1 ]  Chaves <= 2
                        |__+__|

        chave  0    1    2    3   4   5
               i  <=0   <=1  <=2  =3  =4
        count[ 0    0    1    2   2   1 ]  Chaves <= 2
                              |
        
        -> Posição inicial da primeira chave 4

        chave  0    1    2    3   4   5
               i  <=0   <=1  <=2  =3  =4
        count[ 0    0    1    2   2   1 ]  Chaves <= 3
                             |__+__|
    . A
*/