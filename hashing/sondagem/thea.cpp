#include "thea.h"
#include <iostream>

//Construtor: inicializa uma nova tabela com tamanho m
TabHashEndAberto::TabHashEndAberto(int tamanho, float limiar){
    this->m = tamanho;
    this->n = 0;
    this->redims = 0;
    this->tabela = new Elemento[this->m];
    this->limiar = limiar;
    for(int i = 0; i < this->m; i++){
        this->tabela[i].estado = Estado::LIVRE;
    }
}

//Destrutor: libera todos os recursos alocados para a tabela
TabHashEndAberto::~TabHashEndAberto(){
    delete[] this->tabela;
}

//função hash
int TabHashEndAberto::hash(int chave, int k){
    return (chave % this->m + k) % this->m;
} 

    
//Insere um novo par (chave, valor) na tabela
void TabHashEndAberto::inserir(int chave, int valor){

    int h = this->buscar_pos(chave);
    if (h >= 0) {
        this->tabela[h].valor = valor;
        return;
    }

    if( (float)this->n/this->m > this->limiar){
        this->redimensionar(this->m * 2);
        this->redims++;
    }

    int k = 0;
    h = hash(chave, k);
    while(this->tabela[h].estado == Estado::OCUPADO){
        k++;
        h = hash(chave, k);
        if(k == this->m)
            return;
    }

    this->tabela[h].chave = chave;
    this->tabela[h].valor = valor;
    this->tabela[h].estado = Estado::OCUPADO;
    this->n++;

}
    
//Busca o valor associado a chave na tabela
std::pair<int,int> TabHashEndAberto::buscar(int chave){
    int pos = buscar_pos(chave);
    if(pos >= 0){
        return std::make_pair(
            this->tabela[pos].chave,
            this->tabela[pos].valor
        );
    }
    return this->invalido;
}
    
//Imprime a tabela
void TabHashEndAberto::imprimir(){
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
void TabHashEndAberto::imprimir_info(){
    std::cout << "m: " << this->m << std::endl;
    std::cout << "n: " << this->n << std::endl;
    std::cout << "fator de carga: " << (float)this->n/this->m << std::endl;
    std::cout << "redimensionamentos: " << this->redims << std::endl;
}

// redimensiona a tabela para o novo tamanho (novo_m)
void TabHashEndAberto::redimensionar(int novo_m){
    Elemento* nova = new Elemento[novo_m];
    for(int i = 0; i < novo_m; i++){
            nova[i].estado = Estado::LIVRE;
        }
        Elemento* antiga = this->tabela;
        this->tabela = nova;
        int m_antigo = this->m;
        this->n = 0;
        this->m = novo_m;
        for(int i = 0; i < m_antigo; i++){
            if(antiga[i].estado == Estado::OCUPADO){
                this->inserir(antiga[i].chave, 
                                antiga[i].valor);
            }
        }
        delete[] antiga;
    }

//retorna a posição que a chave ocupa na tabela. 
//(ou -1 se a chave não estiver na tabela)
int TabHashEndAberto::buscar_pos(int chave){
    int k = 0;
    int h = hash(chave, k);
    while(this->tabela[h].estado != Estado::LIVRE){
        if((this->tabela[h].estado == Estado::OCUPADO) 
            && (this->tabela[h].chave == chave)){
            return h;
        }
        k++;
        h = hash(chave, k);
    }
    return -1;
}
