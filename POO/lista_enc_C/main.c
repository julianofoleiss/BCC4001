#include <stdlib.h>
#include <stdio.h>
#include "lst.h"

int main(int argc, char** argv){

    ILISTA* L = NULL;

    L = LST_Criar();

    LST_Imprimir(L);

    LST_Inserir(L, 1);
    LST_Imprimir(L);

    LST_Inserir(L, 2);
    LST_Imprimir(L);

    LST_Inserir(L, 3);
    LST_Imprimir(L);

    LST_Inserir(L, 4);
    LST_Imprimir(L);

    LST_Inserir(L, 5);
    LST_Imprimir(L);    

    printf("Tamanho: %d\n", LST_Tamanho(L));

    LST_Remover(L, 1);
    LST_Imprimir(L);

    LST_Remover(L, 5);
    LST_Imprimir(L);

    printf("Tamanho: %d\n", LST_Tamanho(L));

    if(LST_Buscar(L, 3))
        printf("3 encontrado\n");
    else
        printf("3 não encontrado\n");

    LST_Remover(L, 3);
    LST_Imprimir(L);

    if(LST_Buscar(L, 3))
        printf("3 encontrado\n");
    else
        printf("3 não encontrado\n");

    LST_Remover(L, 2);
    LST_Imprimir(L);

    LST_Remover(L, 4);
    LST_Imprimir(L);    

    printf("Tamanho: %d\n", LST_Tamanho(L));

    LST_Destruir(L);

    return 0;
}