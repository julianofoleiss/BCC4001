#ifndef LST_H_INCLUDED
#define LST_H_INCLUDED

//TAD: Lista encadeada simples para armazenar inteiros
//Esta estrutura armazena uma lista encadeada de elementos inteiros.

//A estrutura ILISTA_EL é responsável por armazenar um único elemento e o endereço do próximo elemento.
typedef struct No{
    int dado;
    struct No* proximo;
} No;

//A estrutura ILISTA representa a lista toda, com ponteiros para o primeiro e o ultimo elemento.
typedef struct ILISTA{
    int tamanho;
    No* primeiro;
    No* ultimo;
}ILISTA;

//LST_Criar retorna uma nova lista, pronta para as operações.
ILISTA* LST_Criar();

//LST_Destruir libera toda a memória alocada para a lista *L*.
void LST_Destruir(ILISTA* L);

//LST_Inserir insere o elemento *dado* no final da lista *L*
int LST_Inserir(ILISTA* L, int dado);

//LST_Buscar retorna 1 se o elemento *dado* estiver na lista, ou caso contrário, 0.
int LST_Buscar(ILISTA* L, int dado);

//LST_Remover remove o elemento *dado* da lista *L*.
//Retorna 1 se o elemento foi removido, ou caso contrário, 0.
int LST_Remover(ILISTA* L, int dado);

//LST_Vazia retorna 1 se a lista *L* não tiver elementos, ou caso contrário, 0.
int LST_Vazia(ILISTA* L);

//LST_Tamanho retorna a quantidade de elementos na lista *L*.
int LST_Tamanho(ILISTA* L);

//LST_Imprimir imprime os elementos da lista *L* no console.
void LST_Imprimir(ILISTA *L);

#endif // LST_H_INCLUDED