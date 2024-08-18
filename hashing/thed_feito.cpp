#include "thed.h"
#include <iostream>
#include <cmath>
#include <string>

TabHashEncadeamento::TabHashEncadeamento(int tamanho, int limiar) 
    : invalido(std::make_pair(-1,-1))
 {
    this->m = tamanho;
    this->n = 0;
    this->limiar = limiar;
    this->tabela = new std::vector<std::pair<int,int>>[m];
    this->redims = 0;
}

TabHashEncadeamento::~TabHashEncadeamento() {
    delete[] this->tabela;
}

int TabHashEncadeamento::hash(int chave) {
    return chave % this->m;
}

int TabHashEncadeamento::hash_string(std::string& chave) {
    int hashvalue = 0;
    for(char c : chave){
        hashvalue = (31*hashvalue + c) % this->m;
    }
    return hashvalue;
}



void TabHashEncadeamento::inserir(int chave, int valor) {
    
    auto& el = this->buscar(chave);
    if (el != this->invalido) {
        el.second = valor;
        return;
    }

    if(this->n / this->m >= this->limiar ){
        this->redimensionar(this->m*2);
    }

    int h = hash(chave);
    this->tabela[h].push_back(std::make_pair(chave,valor));
    this->n++;
}

void TabHashEncadeamento::remover(int chave) {
    int h = hash(chave);
    for (auto it = this->tabela[h].begin(); it != this->tabela[h].end(); it++) {
        if (it->first == chave) {
            this->tabela[h].erase(it);
            this->n--;
            return;
        }
    }
}

std::pair<int,int>& TabHashEncadeamento::buscar(int chave) {
    int h = hash(chave);
    for (auto& el : this->tabela[h]) {
        if (el.first == chave) {
            return el;
        }
    }
    return this->invalido;
}

void TabHashEncadeamento::imprimir() {
    imprimir_info();
    for (int i = 0; i < this->m; i++) {
        std::cout << i << ": ";
        for (auto& el : this->tabela[i]) {
            std::cout << "(" << el.first << "," << el.second << ") ";
        }
        std::cout << std::endl;
    }
}


float DesvioPadrao(std::vector<int> v, float media){
    float soma = 0;
    for(auto& el : v){
        soma += (el - media)*(el - media);
    }
    return sqrt(soma/v.size());
}

void TabHashEncadeamento::imprimir_info() {
    std::cout << "M = " << m << ", n = " << n << ", carga = " << (float)n/m;
    std::cout << ", redims = " << redims;

    int maior_lista = 0;
    for(int i = 0; i < this->m; i++){
        if(this->tabela[i].size() > maior_lista){
            maior_lista = this->tabela[i].size();
        }
    }

    std::vector<int> v;
    for(int i = 0; i < this->m; i++){
        if(this->tabela[i].size() > 0){
            v.push_back(this->tabela[i].size());
        }
    }

    std::cout << ", maior lista = " << maior_lista;
    std::cout << ", desvio padrao = " << DesvioPadrao(v, (float)n/m) << std::endl;

}

std::vector<int> TabHashEncadeamento::chaves() {
    std::vector<int> v;

    for(int i = 0; i < this->m; i++){
        if(this->tabela[i].size() > 0){
            for(auto& el : this->tabela[i]){
                v.push_back(el.first);
            }
        }
    }

    return v;
}

std::vector<std::pair<int,int>> TabHashEncadeamento::itens() {
    std::vector<std::pair<int,int>> v;

    for(int i = 0; i < this->m; i++){
        if(this->tabela[i].size() > 0){
            for(auto& el : this->tabela[i]){
                v.push_back(el);
            }
        }
    }

    return v;
}

void TabHashEncadeamento::redimensionar(int novo_m) {
    this->redims++;
    auto* antiga = this->tabela;
    int m_antigo = this->m;
    this->tabela = new std::vector<std::pair<int,int>>[novo_m];
    this->m = novo_m;
    this->n = 0;
    for (int i = 0; i < m_antigo; i++) {
        if(antiga[i].size() > 0){
            for(auto& el : antiga[i]){
                this->inserir(el.first, el.second);
            }
        }
    }

    delete[] antiga;
}
