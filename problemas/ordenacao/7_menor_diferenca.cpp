#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Dado um vetor de inteiros não-negativos v, retorne um par de inteiros 
//cuja diferença é a menor possível dentre todas as diferenças possíveis
//entre dois elementos do vetor.
//Exemplo: v = {10, 14, 4, 7}
//menor_diferenca(v) = {4, 7}
//O vetor de entrada não deve ser modificado.
pair<int,int> menor_diferenca(vector<int> &v){

}

int main(){
    vector<int> v = {10, 14, 4, 7};

    pair<int,int> res = menor_diferenca(v);

    cout << res.first << " " << res.second << "\n";

    return EXIT_SUCCESS;
}