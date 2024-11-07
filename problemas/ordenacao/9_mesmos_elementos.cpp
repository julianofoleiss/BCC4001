#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//Dados dois vetores v1 e v2 de inteiros, retorne true se eles possuem os mesmos elementos,
//ainda que em ordem diferente. Caso hajam elementos repetidos, a quantidade de repetições
//deve ser a mesma. Não use o operador == para comparar vetores.

//Exemplo: v1 = {1, 2, 3, 4, 5}, v2 = {5, 4, 3, 2, 1} deve retornar true
//Exemplo: v1 = {1, 2, 3, 4, 5}, v2 = {5, 4, 3, 2, 0} deve retornar false
//Exemplo: v1 = {1, 2, 3, 4, 5, 1}, v2 = {5, 4, 3, 2, 1, 1} deve retornar true
//Exemplo: v1 = {1, 1, 2, 2} , v2 = {1, 2} deve retornar false

bool mesmos_elementos(vector<int> v1, vector<int> v2) {
    return false;
}

int main(){
   vector<tuple<vector<int>, vector<int>, bool>> testes = {
       {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 1}, true},
       {{1, 2, 3, 4, 5}, {5, 4, 3, 2, 0}, false},
       {{1, 2, 3, 4, 5, 1}, {5, 4, 3, 2, 1, 1}, true},
       {{1, 1, 2, 2}, {1, 2}, false}
    };

    for (int i = 0; i < testes.size(); i++) {
        auto [v1, v2, esperado] = testes[i];
        cout << "Testando caso " << i << endl;
        for (auto x : v1) cout << x << " ";
        cout << endl;
        for (auto x : v2) cout << x << " ";
        cout << endl;
        bool res = mesmos_elementos(v1, v2);
        cout << "Resultado: " <<  res << endl;

        if (res != esperado) {
            cout << "Teste falhou para caso " << i << endl;
            cout << "Esperado: " << esperado << endl;
            cout << "Obtido: " << res << endl;
        }
        cout << endl;
    }

    return 0;
}