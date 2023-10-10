#include <iostream>
#include "thea.h"
#include "print_pair.h"
#include <cstdlib>

void test1(){
    TabHashEndAberto tab(10);

    tab.inserir(0, 0);
    tab.inserir(3, 0);
    tab.inserir(11, 0);
    tab.inserir(12, 0);
    tab.inserir(6, 0);
    tab.inserir(14, 0);

    tab.imprimir();

    std::cout << std::endl;

    tab.inserir(0, 1);
    tab.inserir(14, 1);
    tab.remover(11);

    tab.imprimir();

    auto el1 = tab.buscar(11);
    if(el1 == tab.invalido){
        std::cout << "Chave 11 nao encontrada" << std::endl;
    } else {
        std::cout << "Chave 11 encontrada" << std::endl;
    }

    auto el2 = tab.buscar(0);
    if(el2 == tab.invalido){
        std::cout << "Chave 0 nao encontrada" << std::endl;
    } else {
        std::cout << "Chave 0 encontrada, valor: " << el2.second << std::endl;
    }

    std::cout << std::endl;    
}

void test2(){
    TabHashEndAberto tab(10);

    tab.inserir(0, 0);
    tab.inserir(3, 0);
    tab.inserir(11, 0);
    tab.inserir(12, 0);
    tab.inserir(6, 0);
    tab.inserir(14, 0);

    tab.imprimir();

    std::cout << std::endl;

    tab.inserir(0, 1);
    tab.inserir(14, 1);
    tab.remover(11);

    tab.imprimir();

    auto el1 = tab.buscar(11);
    if(el1 == tab.invalido){
        std::cout << "Chave 11 nao encontrada" << std::endl;
    } else {
        std::cout << "Chave 11 encontrada" << std::endl;
    }

    auto el2 = tab.buscar(0);
    if(el2 == tab.invalido){
        std::cout << "Chave 0 nao encontrada" << std::endl;
    } else {
        std::cout << "Chave 0 encontrada, valor: " << el2.second << std::endl;
    }

    auto chaves = tab.chaves();
    std::cout << "Chaves: ";
    for(auto& el : chaves){
        std::cout << el << " ";
    }

    std::cout << std::endl;

    auto itens = tab.itens();
    std::cout << "Itens: ";
    for(auto& el : itens){
        std::cout << "(" << el.first << "," << el.second << ") ";
        //std::cout << el << " "; // operador << sobrecarregado em print_pair.h
    }

    std::cout << std::endl;    
}

void test3(int argc, char** argv){
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    float limiar = atof(argv[3]);

    TabHashEndAberto tab(m, limiar);

    for(int i = 0; i < n; i++){
        tab.inserir(rand() % (n*100), rand() % (n*100));
    }

    tab.imprimir();
    tab.imprimir_info();
}


int main(int argc, char** argv){
    
    //test1();
    //test2();
    test3(argc, argv);

    return 0;
}
