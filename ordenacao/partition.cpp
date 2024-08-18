#include <iostream>

void troca(int* v, int a, int b){};

int partition(int* v, int p, int r){
    int x;
    int i,j;
    
    x = v[r];
    i = p-1;

    for(j = p; j < r; j++){
        if(v[j] <= x){
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i+1, r);
    return i+1;

}