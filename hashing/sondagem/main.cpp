#include <iostream>
#include "thea.h"
#include <cstdlib>
#include "sondagem.h"

void test(int argc, char** argv){
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    float limiar = atof(argv[3]);

    TabHashEndAberto tab(m, limiar);
    srand(1);
    for(int i = 0; i < n; i++){
        tab.inserir(rand() % (n*100), rand() % (n*100));
    }

    tab.imprimir_info();

    // for(int i = 0; i < n; i++){
    //     tab.buscar(rand() % (n*100));
    // }

    //tab.imprimir();

}


int main(int argc, char** argv){
    
    test(argc, argv);

    return 0;
}