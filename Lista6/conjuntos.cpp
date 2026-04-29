/* 

Dado um conjunto com n números inteiros positivos cuja soma vale S, apresente um
algoritmo que divida este conjunto em dois subconjuntos cuja soma de cada um seja
S/2, ou que defina que não existe tal divisão.



*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int soma_intervalo(vector <int> conjunto, int inicio, int fim) {

    if(inicio >= fim || fim > conjunto.size()) return 0;

    int S = 0;
    for (int i = inicio; i < fim; i++) {
        S += conjunto[i];
    }
    return S;
}

bool resolver(int index, int soma_atual, vector<int>& conjunto, vector<int>& solucao, int alvo) {
    if (soma_atual == alvo) {
        return true; 
    }

    if (index == conjunto.size() || soma_atual > alvo) {
        return false;
    }

    solucao.push_back(conjunto[index]); // "Tomo a decisão"
    if (resolver(index + 1, soma_atual + conjunto[index], conjunto, solucao, alvo)) {
        return true; 
    }

    solucao.pop_back(); 

   
    if (resolver(index + 1, soma_atual, conjunto, solucao, alvo)) {
        return true;
    }

    return false; 
}

int main() {

    vector <int> conjunto = {1, 9, 4, 7, 3, 4};
    vector <int> solucao;

    int alvo = soma_intervalo(conjunto, 0, conjunto.size()) / 2;
    if (resolver(0, 0, conjunto, solucao, alvo)) {
        cout << "Subconjunto encontrado: ";
        for (int x : solucao) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << "Nao existe tal divisao." << endl;
    }


}


