#pragma once

#include <vector>
#include <utility>

class TabHashEncadeamento {
public:
    //Construtor: inicializa uma nova tabela com tamanho m
    TabHashEncadeamento(int tamanho, int limiar = 5);

    //Destrutor: libera todos os recursos alocados para a tabela
    ~TabHashEncadeamento(); 
    
    //Insere um novo par (chave, valor) na tabela
    void inserir(int chave, int valor);
    
    //Remove o par com a chave da tabeka
    void remover(int chave);
    
    //Busca o valor associado a chave na tabela
    std::pair<int,int>& buscar(int chave);
    
    //Imprime a tabela
    void imprimir();

    //Imprime informações sobre a tabela (m, n e fator de carga)
    void imprimir_info();

    //par chave-valor inválido para indicar que a chave não foi encontrada
    std::pair<int,int> invalido;

    // retorna as chaves da tabela
    std::vector<int> chaves();

    // retorna todos os pares (chave, valor) da tabela
    std::vector<std::pair<int,int>> itens();

private:
    int m; // tamanho da tabela
    int n; // número de elementos na tabela
    // limiar para redimensionamento. quando n/m > limiar, redimensionar
    int limiar; 
    int redims; // número de redimensionamentos realizados

    std::vector<std::pair<int,int>> *tabela; // tabela hash
    int hash(int chave); // função hash

    // redimensiona a tabela para o novo tamanho (novo_m)
    void redimensionar(int novo_m); 
    
};