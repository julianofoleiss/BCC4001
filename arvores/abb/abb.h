#pragma once

#include <iostream>

template<typename C, typename V>
class ABB;

template <typename C, typename V>
class NoABB
{
    public:
        NoABB(C chave, V valor) 
            : chave(chave), valor(valor), 
            esq(nullptr), dir(nullptr) {}

        ~NoABB();

        C getChave() { return chave; }
        V& getValor() { return valor; }

    private:
        C chave;
        V valor;
        NoABB *esq;
        NoABB *dir;

    friend class ABB<C, V>;
};

template <typename C, typename V>
class ABB
{
    public:
        ABB();
        ~ABB() { delete raiz; }

        //insere o par (chave, valor) na árvore
        void inserir(C chave, V valor);
        //retorna uma referência ao nó com a chave especificada
        NoABB<C, V>& buscar(C chave);
        //remove o nó com a chave especificada
        void remover(C chave);
        //imprime a árvore
        void imprimir();
        //retorna uma referência ao nó com a menor chave
        NoABB<C, V>& minimo();
        //retorna uma referência ao nó com a maior chave
        NoABB<C, V>& maximo();
        //retorna uma referência ao nó com a chave sucessora da chave especificada
        NoABB<C, V>& sucessor(C chave);
        //retorna uma referência ao nó com a chave antecessora da chave especificada
        NoABB<C, V>& antecessor(C chave);
        //retorna o número de nós da árvore
        int tamanho();
        //retorna true se a árvore estiver vazia
        bool vazia();

    private:

        NoABB<C, V>* inserirNo(NoABB<C, V>* no, C chave, V valor);
        void imprimirNo(NoABB<C, V>* no, int nivel, char lado);
        NoABB<C, V>* raiz;
};

