
/* 

Resolvendo problema de labirinto usando backtracking. 
O labirinto é representado por uma matriz 5x5, onde cada célula pode ser um caminho ou uma parede. 
O objetivo é encontrar um caminho do ponto de partida (0,0) até o ponto de chegada (4,4), evitando as paredes.
O programa utiliza a técnica de backtracking para explorar todas as possíveis rotas e encontrar a solução correta.

*/

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct bloco{
    bool isWall;
    bool isUsed;
} bloco;

typedef struct labirinto{
    bloco matriz[5][5];
} labirinto;

labirinto criarLabirinto() {
    labirinto l;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            l.matriz[i][j].isUsed = false;
            l.matriz[i][j].isWall = false;
        }
    }

    l.matriz[0][2].isWall = true;
    l.matriz[1][0].isWall = true;
    l.matriz[2][3].isWall = true;
    l.matriz[4][3].isWall = true;

    return l;
}

int main() {

    labirinto l = criarLabirinto();

    return 0;




}