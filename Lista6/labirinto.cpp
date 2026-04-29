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

typedef struct posicao{
    pair <int, int> coordenada;
} posicao;


void imprimirLabirinto(labirinto l); 


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

labirinto mover(labirinto l, char direcao, posicao p) {
    int x = p.coordenada.first;
    int y = p.coordenada.second;

    if (direcao == 'C' && x > 0 && !l.matriz[x - 1][y].isWall) {
        x--;
        l.matriz[x][y].isUsed = true;
    } else if (direcao == 'B' && x < 4 && !l.matriz[x + 1][y].isWall) {
        x++;
        l.matriz[x][y].isUsed = true;
    } else if (direcao == 'E' && y > 0 && !l.matriz[x][y - 1].isWall) {
        y--;
        l.matriz[x][y].isUsed = true;
    } else if (direcao == 'D' && y < 4 && !l.matriz[x][y + 1].isWall) {
        y++;
        l.matriz[x][y].isUsed = true;
    }

    if (x >= 0 && x < 5 && y >= 0 && y < 5 && !l.matriz[x][y].isWall) {
        l.matriz[x][y].isUsed = true;
    }

    return l;
}

labirinto backtraking(labirinto l, posicao p) {
    cout << "Explorando posicao: (" << p.coordenada.first << ", " << p.coordenada.second << ")" << endl;

    imprimirLabirinto(l);

    if (p.coordenada.first == 4 && p.coordenada.second == 4) {
        return l; // Chegou ao destino
    }

    char direcoes[] = {'C', 'B', 'E', 'D'};
    for (char direcao : direcoes) {
        int nx = p.coordenada.first;
        int ny = p.coordenada.second;
        if (direcao == 'C') nx--;
        else if (direcao == 'B') nx++;
        else if (direcao == 'E') ny--;
        else if (direcao == 'D') ny++;

        // Verifique antes de mover!
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 &&
            !l.matriz[nx][ny].isWall &&
            !l.matriz[nx][ny].isUsed) {

            labirinto novoLabirinto = mover(l, direcao, p);
            posicao novaPosicao;
            novaPosicao.coordenada = make_pair(nx, ny);

            labirinto resultado = backtraking(novoLabirinto, novaPosicao);
            if (resultado.matriz[4][4].isUsed) {
                return resultado; // Encontrou o caminho
            }
        }
    }

    return l; // Retorna o labirinto original se não encontrar um caminho válido
}




void imprimirLabirinto(labirinto l) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (l.matriz[i][j].isWall) {
                cout << "X ";
            } else if (l.matriz[i][j].isUsed) {
                cout << "O ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

int main() {

    labirinto l = criarLabirinto();
    imprimirLabirinto(l);

    posicao p;
    p.coordenada = make_pair(0, 0);

    labirinto resultado = backtraking(l, p);
    cout << "Caminho encontrado:" << endl;
    imprimirLabirinto(resultado);

    return 0;




}