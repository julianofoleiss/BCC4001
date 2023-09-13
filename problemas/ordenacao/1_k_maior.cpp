#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "utils.h"

#include <algorithm>

#define DEBUG 1

// retorna o k-ésimo maior elemento do vetor.
// Os elementos de v podem ser permutados durante a execução.
// pré-condição: o vetor não possui elementos repetidos
// k=1 retorna o maior elemento
// k=2 retorna o segundo maior elemento
// k=....
// k=n retorna o menor elemento
int k_maior(std::vector<int> &v, int k){
    return 0;
}

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    auto v = gerar_vetor_aleatorio_sem_reps(n, 42);

    #if DEBUG
    imprimir_vetor(v.data(), n);
    #endif

    int res = k_maior(v, k);

    #if DEBUG
    std::cout << "O " << k << "-ésimo maior elemento do vetor é o " << res << "!\n";
    #endif    

    return EXIT_SUCCESS;
}