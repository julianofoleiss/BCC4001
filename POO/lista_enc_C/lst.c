#include "lst.h"
#include <stdlib.h>
#include <stdio.h>

ILISTA* LST_Criar(){
    ILISTA* novo;

    //Alocar memória para a cabeça da lista
    novo = malloc(sizeof(ILISTA));

    //Inicializar a lista vazia
    novo->primeiro = NULL;
    novo->ultimo = NULL;
    novo->tamanho = 0;

    //Retorna o endereço da estrutura alocada
    return novo;
}

void LST_Destruir(ILISTA* L){
    No *p = L->primeiro;
    while(p != NULL){
        No *t = p->proximo;
        free(p);
        p = t;
    }
}

int LST_Inserir(ILISTA* L, int dado){
    No* novo;

    //A lista está apontando para algum endereço diferente de NULL?
    //Assumimos que se for verdadeiro, foi alocada corretamente.
    if(L != NULL){
        //Alocar um novo nó para guardar o dado
        novo = malloc(sizeof(No));
        novo->proximo = NULL;
        novo->dado = dado;

        //Caso 1: a lista é vazia.
        if(LST_Vazia(L)){
            L->primeiro = novo;
            L->ultimo = novo;

        }
        else{
            //Caso 2: a lista tem pelo menos um elemento.
            //Ligar o último elemento da lista ao novo elemento e
            //atualizar o ponteiro para o último elemento.
            L->ultimo->proximo = novo;
            L->ultimo = novo;
        }

        //Atualizar o tamanho da lista
        L->tamanho++;
        return 1;
    }
    return 0;
}

int LST_Buscar(ILISTA* L, int dado){
    No* p;

    //Se a lista for vazia, não é possível queo item buscado esteja presente.
    if(LST_Vazia(L))
        return 0;

    //Fazer a busca linear pelo elemento
    for(p = L->primeiro; p != NULL; p = p->proximo){
        //Caso o elemento for encontrado, retornar 1.
        if(p->dado == dado)
            return 1;
    }

    //Caso todos os elementos forem verificados e não encontramos o dado,
    //retornar 0, indicando que o elemento não está na lista.
    return 0;
}
int LST_Remover(ILISTA* L, int dado){
    No *p, *anterior;

    //Se a lista for vazia, não é possível remover o elemento, pois ele não
    //é possível que ele esteja presente.
    if(LST_Vazia(L))
        return 0;

    //tratar o caso onde dado é o único elemento da lista
    if(L->primeiro == L->ultimo && L->primeiro->dado == dado){
        free(L->primeiro);
        L->primeiro = NULL;
        L->ultimo = NULL;
        L->tamanho = 0;
        return 1;
    }

    //Fazer a busca sequencial pelo elemento
    for(p = L->primeiro; p != NULL; p = p->proximo){
        //Caso o elemento for encontrado, remover o elemento.
        if(p->dado == dado){
            //Caso 1: o elemento a ser removido é o primeiro da lista.
            if(p == L->primeiro){
                L->primeiro = p->proximo;
            }
            //Caso 2: o elemento a ser removido é o último da lista.
            else if(p == L->ultimo){
                L->ultimo = anterior;
                anterior->proximo = NULL;
            }
            //Caso 3: o elemento a ser removido está no meio da lista.
            else{
                anterior->proximo = p->proximo;
            }

            //Liberar a memória do elemento removido
            free(p);

            //Atualizar o tamanho da lista
            L->tamanho--;
            return 1;
        }
        anterior = p;
    }

    //Caso todos os elementos forem verificados e não encontramos o dado,
    //retornar 0, indicando que o elemento não está na lista, e, logo,
    //não pode ser removido.
    return 0;
}

int LST_Vazia(ILISTA* L){
    //O tamanho da lista é diferente de zero? Se sim, a lista
    // não é vazia, caso contrário, é vazia.
    return L->tamanho > 0 ? 0 : 1;
}

int LST_Tamanho(ILISTA* L){
    return L->tamanho;
}

void LST_Imprimir(ILISTA *L){
    No* p;

    if(LST_Vazia(L)){
        return;
    }

    if(L != NULL){
        //Varrer a lista e imprimir todos os elementos.
        for(p = L->primeiro; p != NULL; p = p->proximo){
            printf("%d ", p->dado );
        }
        printf("\n");
    }
}






