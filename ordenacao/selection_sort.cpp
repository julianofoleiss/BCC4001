#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

int max(int* v, int ini, int fim){
    int maior = ini;
    for(int i = ini+1; i <= fim; i++){
        if(v[i] > maior){
            maior = i;
        }
    }
    return maior;
};

int min(int* v, int ini, int fim){
    int menor = fim;
    for(int i = fim; i >= ini; i--){
        if(v[i] < v[menor]){
            menor = i;
        }
    }
    return menor;
}

void troca(int* v, int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
};

void selection_sort(int* v, int n){
    for(int i = n-1; i >= 0; i--){
        int maior = max(v, 0, i);
        troca(v, maior, i);

    }
};

void bubble_sort(int* v, int n){
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(v[j+1] > v[j]){
                troca(v, j, j+1);
            }
        }
        
    }
}

void merge(int *v, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int* e = new int[n1];
    int* d = new int[n2];

    for(int i = 0; i < n1; i++){
        e[i] = v[p+i];
    }

    for(int i = 0; i < n2; i++){
        d[i] = v[(q+1)+i];
    }

    int k,i = 0,j = 0;
    
    while( (i < n1) && (j < n2) ){
        if(e[i] <= d[j]){
            v[k] = e[i];
            i++;
        } else {
            v[k] = d[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        v[k] = e[i];
        i++;k++;
    }
    while(j < n2){
        v[k] = d[j];
        j++;k++;
    }

    delete[] e;
    delete[] d;

}


void selection_sortV2(int* v, int n){
    int i;
    int menor;
    for(i = n-1; i >= 0; i--){
        menor = min(v, 0, i);
        troca(v, menor, i);
        
    }
};

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

int main() {
    int n = 10;
    int* v = vetor_aleatorio(n, 1);

    imprimir_vetor(v, n);

    //selection_sortV2(v, n);
    merge(v, 0, 4, 9);

    imprimir_vetor(v, n);

    delete[] v;

    return 0;
}
