
#include <iostream>
#include "exprtree.h"
#include "shunting_yard.h"

int main(int argc, char** argv){

    char* infixa = argv[1];
    char* posfixa = shunting_yard(infixa);
    std::cout << "Infixa: " << infixa << std::endl;
    std::cout << "Posfixa: " << posfixa << std::endl;

    ExprTree arvore(posfixa);

    std::cout << "Resultado: " << arvore.avaliar() << std::endl;

    delete[] posfixa;

    return 0;

}