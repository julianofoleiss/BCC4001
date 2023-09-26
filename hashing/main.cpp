#include <iostream>
#include "thed.h"

int main(int argc, char** argv){
    TabHashEncadeamento tab(7);

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

    auto& el1 = tab.buscar(11);
    if(el1 == tab.invalido){
        std::cout << "Chave 11 nao encontrada" << std::endl;
    } else {
        std::cout << "Chave 11 encontrada" << std::endl;
    }

    auto& el2 = tab.buscar(0);
    if(el2 == tab.invalido){
        std::cout << "Chave 0 nao encontrada" << std::endl;
    } else {
        std::cout << "Chave 0 encontrada, valor: " << el2.second << std::endl;
    }

    return 0;
}
