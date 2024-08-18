#include <iostream>
#include <ctime>
#include <cstdlib>

int max(int *v, int ini, int fim ){
    int maior = ini;
    for(int i = ini+1; i <= fim; i++){
        if(v[i] > v[maior])
            maior = i;
    }
    return maior;
}

void troca(int *v, int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void SelectionSort(int *v, int n){
    for(int i = n-1; i > 0; i--){
        int pmaior = max(v, 0, i);
        troca(v, pmaior, i);
    }
}

int* vetor_aleatorio(int n, int seed){
    srand(seed);
    int* v = new int[n];
    for(int i = 0; i < n; i++){
        v[i] = rand() % (n*100);
    }
    return v;
}

void imprimir_vetor(int* v, int n){
    for(int i = 0; i < n; i++){
        std::cout << v[i] << " ";
    }
    std::cout << "\n";    
}

int main(int argc, char** argv){
    // int v[] = {3, 1, 0, 4, 6, 2};

    // SelectionSort(v, 6);

    // for(int i = 0; i < 6; i++){
    //     std::cout << v[i] << " ";
    // }
    int n = 10;

    int* v = vetor_aleatorio(n, 1);

    imprimir_vetor(v, n);

    SelectionSort(v, n);

    imprimir_vetor(v, n);

    delete[] v;

    return 0;
}