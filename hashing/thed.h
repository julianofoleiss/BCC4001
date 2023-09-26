#include <vector>
#include <utility>

class TabHashEncadeamento {
public:
    //Construtor: inicializa uma nova tabela com tamanho m
    TabHashEncadeamento(int tamanho);

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

    //par chave-valor inválido para indicar que a chave não foi encontrada
    std::pair<int,int> invalido;

private:
    int m; // tamanho da tabela
    std::vector<std::pair<int,int>> *tabela; // tabela hash
    int hash(int chave); // função hash
    
};