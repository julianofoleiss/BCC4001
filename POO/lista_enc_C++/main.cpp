#include "lst.h"

#include <iostream>

int teste1(){
    // Neste teste a lista é alocada na heap. Neste caso, é necessário
    // usar o operador new para instanciar um objeto da classe ListaEncadeada.
    // O construtor da classe ListaEncadeada é invocado automaticamente quando
    // o operador new é usado.
    ListaEncadeada* l = new ListaEncadeada();

    l->imprimir();

    l->inserir(1);
    l->imprimir();

    l->inserir(2);
    l->imprimir();

    l->inserir(3);
    l->imprimir();

    l->inserir(4);
    l->imprimir();    

    l->inserir(5);
    l->imprimir();     

    l->remover(1);
    l->imprimir();

    l->remover(5);
    l->imprimir();    

    if(l->buscar(3))
        std::cout << "3 encontrado" << std::endl;
    else
        std::cout << "3 não encontrado" << std::endl;

    l->remover(3);
    l->imprimir();   

    if(l->buscar(3))
        std::cout << "3 encontrado" << std::endl;
    else
        std::cout << "3 não encontrado" << std::endl;        

    l->remover(2);
    l->imprimir();

    l->remover(4);
    l->imprimir();

    std::cout << "Tamanho: " << l->getTamanho() << std::endl;

    // Como a lista foi alocada na heap, é necessário usar o operador delete
    // para invocar o destrutor da lista.
    
    // Embora a destruição manual de objetos alocados em heap  pareça um detalhe inoportuno, 
    // isto é importante para que o programador tenha controle sobre o momento em que a memória
    // alocada é liberada, caso necessário. Considere por exemplo o caso em que uma função
    // é responsável por criar uma lista e retorná-la para o chamador. Neste caso, a lista
    // não deve ser destruída ao final da função, uma vez que ela será usada pelo chamador.

    delete l;
}

int teste2(){
    // Neste teste a lista é alocada na pilha de execução.
    // Neste caso, não é necessário usar o operador new para instanciar um objeto da classe ListaEncadeada.
    // O construtor da classe ListaEncadeada é invocado automaticamente quando a variável l é declarada.
    // Note que quando o construtor não recebe parâmetros, a sintaxe é a mesma da usada para declarar 
    // variáveis de tipos primitivos, como int, float, etc.
    ListaEncadeada l;

    l.imprimir();

    l.inserir(1);
    l.imprimir();

    l.inserir(2);
    l.imprimir();

    l.inserir(3);
    l.imprimir();

    l.inserir(4);
    l.imprimir();    

    l.inserir(5);
    l.imprimir();     

    std::cout << "Tamanho: " << l.getTamanho() << std::endl;

    l.remover(1);
    l.imprimir();

    l.remover(5);
    l.imprimir();    

    std::cout << "Tamanho: " << l.getTamanho() << std::endl;    

    if(l.buscar(3))
        std::cout << "3 encontrado" << std::endl;
    else
        std::cout << "3 não encontrado" << std::endl;

    l.remover(3);
    l.imprimir();   

    if(l.buscar(3))
        std::cout << "3 encontrado" << std::endl;
    else
        std::cout << "3 não encontrado" << std::endl;        

    l.remover(2);
    l.imprimir();

    l.remover(4);
    l.imprimir();

    std::cout << "Tamanho: " << l.getTamanho() << std::endl;

    // Como a lista foi alocada na pilha, não é necessário usar o operador delete para
    // invocar o destrutor, uma vez que ele é invocado automaticamente quando a variável l
    // sai de escopo.

    //Lembre-se que não é possível retornar a lista l, uma vez que ela é destruída
    //automaticamente ao final da execução da função! Caso queira retorná-la, é necessário
    //alocá-la na heap, como no teste1().
}

int main(int argc, char** argv){

    //Há dois testes a seguir que fazem essencialmente a mesma coisa. 
    //Veja os comentários em cada teste para entender a diferença

    //No primeiro a lista é alocada na heap
    teste1();

    //No segundo a lista é alocada na pilha
    teste2();

    return 0;
}
    