#pragma once

#include <vector>
#include <utility>

class TabHashEndAberto {
public:
    //Construtor: inicializa uma nova tabela com tamanho m
    TabHashEndAberto(int tamanho, float limiar);

    //Destrutor: libera todos os recursos alocados para a tabela
    ~TabHashEndAberto();
    
    //Insere um novo par (chave, valor) na tabela
    void inserir(int chave, int valor);
    
    //Busca o valor associado a chave na tabela
    std::pair<int,int> buscar(int chave);
    
    //Imprime a tabela
    void imprimir();

    //Imprime informações sobre a tabela (m, n e fator de carga)
    void imprimir_info();

    //par chave-valor inválido para indicar que a chave não foi encontrada
    std::pair<int,int> invalido = {-1,-1};

private:

    enum class Estado {
        LIVRE,
        OCUPADO,
        APAGADO
    };

    struct Elemento {
    public:
        int chave;
        int valor;
        Estado estado;
    };

    int m; // tamanho da tabela
    int n; // número de elementos na tabela
    // limiar para redimensionamento. quando n/m > limiar, redimensionar
    float limiar; 
    int redims; // número de redimensionamentos realizados

    Elemento *tabela; // tabela hash

    //função hash
    int hash(int chave, int k);

    // redimensiona a tabela para o novo tamanho (novo_m)
    void redimensionar(int novo_m);

    //retorna a posição que a chave ocupa na tabela. 
    //(ou -1 se a chave não estiver na tabela)
    int buscar_pos(int chave);
    
};
