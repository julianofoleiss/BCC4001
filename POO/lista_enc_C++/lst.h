#define DEBUG 1

// De maneira resumida e simplificada, uma "classe" é um tipo de dado 
// definido pelo usuário. É uma evolução do conceito de "struct" do C,
// que permite que sejam definidos tipos de dados que contém atributos
// e métodos (funções-membros) que operam sobre estes atributos.

class ListaEncadeada{

// resumidamente, o modificador de acesso "public" indica que os membros
// públicos da classe definidos após o modificador de acesso e antes do próximo modificador
// podem ser acessados por qualquer objeto que tiverem acesso a um ponteiro ou referência 
// para um objeto da classe.

// Neste exemplo, os membros públicos são o construtor, o destrutor e os métodos inserir, 
// remover, imprimir, getTamanho, buscar e vazia.
public:

    ListaEncadeada();           // Construtor - inicializa a lista
    ~ListaEncadeada();          // Destrutor  - controla a liberação da memória usada pelo objeto

    // Métodos (também chamadas de funções-membras)
    // Veja que não é necessário passar um ponteiro para o objeto explicitamente.
    // Na definição da função, o compilador insere um parâmetro oculto, chamado
    // "this", que é um ponteiro para o objeto que está chamando a função.
    void inserir(int valor);
    bool remover(int valor);
    void imprimir();
    int getTamanho();
    bool buscar(int valor);
    bool vazia();

// resumidamente, o modificador de acesso "private" indica que os membros
// públicos da classe definidos após o modificador de acesso e antes do próximo modificador
// podem ser acessados apenas por objetos da mesma classe.

//Neste exemplo, os membros privados são a classe Nó, e os atributos tamanho, primeiro e ultimo.
private:

    // Classe Nó é uma classe interna à classe ListaEncadeada.
    // Ela é privada, portanto, só pode ser acessada por objetos da classe ListaEncadeada.
    // Esta classe representa cada elemento da lista encadeada.
    class No{
    public:
        No(int dado) : dado(dado){}
        int dado;
        No *proximo;
    };

    // Atributos (também chamados de variáveis-membras)
    int tamanho;
    No *primeiro;
    No *ultimo;

};