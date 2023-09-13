#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct Pais{
    Pais(const string& nome, int o, int p, int b)
        : nome(move(nome)), ouro(o), prata(p), bronze(b){}

    void print(){
        cout << nome << " " << ouro << " " << prata << " " << bronze << "\n";
    }

    string nome;
    int ouro;
    int prata;
    int bronze;
};

void ordenar_quadro_medalhas(vector<Pais> &paises){

}

int main(int argc, char** argv){
    int N;
        
    string nome;
    int o, p, b;

    cin >> N;

    vector<Pais> quadro;
    quadro.reserve(500);

    while(N--){
        cin >> nome >> o >> p >> b;
        quadro.emplace_back(nome, o, p, b);
    }

    ordenar_quadro_medalhas(quadro);

    for(auto& p : quadro){
        p.print();
    }

    return 0;
}