#include "lst.h"

// Embora a linguagem C++ permita o uso das bibliotecas padrão do C, como
// <stdio.h> e <stdlib.h>, ela também possui suas próprias biliotecas-padrão.

// A biblioteca <iostream> é a biblioteca padrão de entrada e saída de dados
// do C++. Por enquanto vamos nos preocupar apenas com os objetos "cin" e "cout", 
// que são objetos da classe "istream" e "ostream", usados para manipular a entrada 
// e saída padrão do programa (teclado e tela).
#include <iostream>

// Construtor da classe ListaEncadeada é uma função especial que é invocada
// automaticamente quando um objeto da classe é criado. 

// O construtor sempre tem o mesmo nome da classe e não tem tipo de retorno.

// Note que a alocação da memória para o objeto é feita automaticamente pelo
// compilador. A responsabilidade do programador é apenas inicializar os atributos.

// O objeto sendo construído é referenciado pelo ponteiro "this". Portanto, 
// o programador pode acessar os atributos do objeto usando o operador
// "->".
ListaEncadeada::ListaEncadeada(){
    this->tamanho = 0;
    this->primeiro = nullptr;   // a linguagem c++ permite usar "NULL" ou "nullptr" 
                                // para indicar um ponteiro nulo.
    this->ultimo = nullptr;
}
// A definição do construtor abaixo é funcionalmente equivalente a implementação apresentada acima.
// ListaEncadeada::ListaEncadeada() 
//     : tamanho(0), primeiro(nullptr), ultimo(nullptr) 
//     {}


// Destrutor da classe ListaEncadeada é uma função especial que é invocada
// automaticamente quando um objeto da classe é destruído.

// O destrutor sempre tem o mesmo nome da classe, mas é precedido pelo caractere
// "~". O destrutor não tem tipo de retorno.

// A liberação da memória para o objeto é feita automaticamente pelo
// compilador. A responsabilidade do programador é apenas invocar o destrutor
// dos membros que foram alocados na heap.
ListaEncadeada::~ListaEncadeada(){
    No *p = this->primeiro;

    #if DEBUG
        std::cout << "Destruindo a lista..." << std::endl;
    #endif

    while(p != nullptr){
        No *t = p->proximo;
        delete p; //invoca o destrutor do nó
        p = t;
    }
}

void ListaEncadeada::inserir(int dado){
    // O novo nó sendo inserido na lista está sendo alocado na heap, uma vez
    // que não queremos que o nó seja destruído quando a função inserir
    // terminar. O nó deve ser destruído apenas quando a lista for destruída,
    // ou quando o nó for removido da lista.

    // Note que o construtor da classe No recebe um parâmetro inteiro, que é
    // o dado a ser armazenado no nó.
    No* novo = new No(dado);
    
    //Note que para chamar um método do próprio objeto, não é necessário
    //usar o ponteiro "this". Ou seja, invocação do método "vazia()" a seguir
    //é equivalente a "this->vazia()".
    if(vazia()){
        this->primeiro = novo;
        this->ultimo = novo;
    }
    else{
        this->ultimo->proximo = novo;
        this->ultimo = novo;
    }
    //Note que para acessar o atributo "tamanho" do objeto, foi usado o ponteiro
    //"this". Entretanto, isto não é necessário. O atributo "tamanho" também pode
    //ser acessado diretamente, como em "tamanho++". Entretanto, é comum usar o
    //ponteiro "this" para acessar os atributos do objeto, para diferenciá-los
    //de variáveis locais.
    this->tamanho++;
}

bool ListaEncadeada::buscar(int dado){
    No* p;

    if (vazia()) 
        return false;

    for(p = this->primeiro; p != nullptr; p = p->proximo){
        if(p->dado == dado)
            return true;
    }

    return false;
}

bool ListaEncadeada::remover(int dado){
    No *anterior, *p;

    if(vazia())
        return false;

    if(this->primeiro == this->ultimo && this->primeiro->dado == dado){
        delete this->primeiro;
        this->primeiro = nullptr;
        this->ultimo = nullptr;
        this->tamanho = 0;
        return true;
    }

    for(p = this->primeiro; p != nullptr; p = p->proximo){
        if(p->dado == dado){
            if(p == this->primeiro){
                this->primeiro = p->proximo;
            }
            else if(p == this->ultimo){
                this->ultimo = anterior;
                anterior->proximo = NULL;
            }
            else{
                anterior->proximo = p->proximo;
            }

            delete p;
            
            this->tamanho--;
            return true;
        }
        anterior = p;
    }     
    return false;
}

void ListaEncadeada::imprimir(){
    No* p;

    if (vazia())
        return;
    
    // O objeto cout recebe dados que são enviados para a saída
    // padrão do programa (tela). O operador de inserção em fluxo "<<" 
    // é usado para separar os dados que serão enviados para a saída padrão.
    // Em tipos primitivos, como inteiros, o operador de inserção em fluxo
    // já está definido, e insere a representação textual do número na saída.
    // Em tipos definidos pelo usuário, como a classe No por exemplo,
    // é necessário sobrecarregar o operador "<<" para que o compilador saiba como
    // representar o objeto textualmente para que possa ser inserido na saída padrão.
    for(p = this->primeiro; p != nullptr; p = p->proximo)
        std::cout << p->dado << " ";

    //std é o namespace da biblioteca padrão do C++. O operador de resolução de escopo
    //"::" é usado para acessar os elementos do namespace.

    //Resumidamente, namespaces são usados para evitar conflitos de nomes entre
    //elementos de bibliotecas diferentes. Por exemplo, a biblioteca padrão do C++
    //possui uma classe "string", que é usada para representar cadeias de caracteres.
    //Entretanto, o programador pode querer usar uma classe "string" de uma biblioteca
    //externa. Para evitar conflitos de nomes, o namespace é usado para diferenciar
    //os elementos de cada biblioteca.

    // endl é um objeto da classe ostream que representa o caractere de quebra de linha
    // seguido por um flush da saída padrão. Desta forma, endl não é equivalente a 
    // um caractere de quebra de linha "\n", embora ambos tenham o mesmo efeito na tela.
    std::cout << std::endl;
}

int ListaEncadeada::getTamanho(){
    return this->tamanho;
}

bool ListaEncadeada::vazia(){
    // return this->tamanho == 0; // isto é equivalente a:
    return this->tamanho > 0 ? false : true;
}

