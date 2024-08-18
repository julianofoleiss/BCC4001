#pragma once

#include <vector>
#include <utility>

class TabHashEndAberto {
public:
    //Construtor: inicializa uma nova tabela com tamanho m
    TabHashEndAberto(int tamanho){
        this->n = 0;
        this->m = tamanho;
        this->tabela = new Elemento[this->m];
        for(int i = 0; i < this->m; i++){
            this->tabela[i].estado = Estado::LIVRE;
        }
    }

    //Destrutor: libera todos os recursos alocados para a tabela
    ~TabHashEndAberto(){
        delete[] this->tabela;
    }
    
    //Insere um novo par (chave, valor) na tabela
    void inserir(int chave, int valor){
        int pos = buscar_pos(chave);
        if(pos >= 0){
            //chave já está na tabela, atualizar valor
            this->tabela[pos].valor = valor;
            return;
        }
        if(this->n == this->m){
            std::cout << "tabela cheia!\n";
            return;
        }
        int k = 0;
        pos = hash(chave, k);
        while(this->tabela[pos].estado == Estado::OCUPADO){
            k++;
            pos = hash(chave, k);
        }
        this->tabela[pos].chave = chave;
        this->tabela[pos].estado = Estado::OCUPADO;
        this->tabela[pos].valor = valor;
        this->n++;
    }
    
    //Remove o par com a chave da tabela
    void remover(int chave){
        int pos = buscar_pos(chave);
        if(pos != -1){
            this->tabela[pos].estado = Estado::APAGADO;
            this->n--;
        }
    }
    
    //Busca o valor associado a chave na tabela
    std::pair<int,int> buscar(int chave){
        int pos = buscar_pos(chave);
        if(pos != -1){
            auto& el = this->tabela[pos];
            return std::make_pair(el.chave, el.valor);
        }
        return this->invalido;
    }
    
    //Imprime a tabela
    void imprimir(){
        for (int i = 0; i < this->m; i++) {
            std::cout << i << ": ";
            const auto& el = this->tabela[i];
            std::cout << "(" << el.chave << "," << el.valor << ") ";
            char estado = el.estado == Estado::APAGADO ? 'A' :
                        (el.estado == Estado::LIVRE ? 'L' : 'O');
            std::cout << "[" << estado << "]";
            std::cout << std::endl;
        }    
    }

    //Imprime informações sobre a tabela (m, n e fator de carga)
    void imprimir_info()
    {
        std::cout << "m: " << this->m << std::endl;
        std::cout << "n: " << this->n << std::endl;
        std::cout << "fator de carga: " << (float)this->n/this->m << std::endl;
        std::cout << "redimensionamentos: " << this->redims << std::endl;
    }

    //par chave-valor inválido para indicar que a chave não foi encontrada
    std::pair<int,int> invalido{-1, -1};

    // retorna as chaves da tabela
    std::vector<int> chaves();

    // retorna todos os pares (chave, valor) da tabela
    std::vector<std::pair<int,int>> itens();

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
    int hash(int chave, int k){
        return ((chave % this->m) + k) % this->m;
    }

    // redimensiona a tabela para o novo tamanho (novo_m)
    void redimensionar(int novo_m); 

    //retorna a posição que a chave ocupa na tabela. 
    //(ou -1 se a chave não estiver na tabela)
    int buscar_pos(int chave){
        int k = 0;
        int pos = hash(chave, k);
        while(this->tabela[pos].estado != Estado::LIVRE){
            if((this->tabela[pos].estado == Estado::OCUPADO)
                && (this->tabela[pos].chave == chave)){
                return pos;
            }
            k++;
            pos = hash(chave, k);
            if(k == this->m){
                break;
            }
        }
        return -1;
    }
    
};