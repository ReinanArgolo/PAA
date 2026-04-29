/* Mario adora convidar seus amigos para brincar em sua casa. Então decidiu convidar seus amigos para brincarem de Polícia e Ladrão. O jogo consiste em dois grupos, um grupo é a polícia e o outro é o grupo dos ladrões. Os ladrões devem se esconder e a polícia deve capturá-los. Caso a polícia consiga capturá-los e prendê-los os ladrões perdem o jogo e caso a polícia não consiga capturá-los os ladrões vencem o jogo.

Mario decidiu que seria do grupo da polícia e que teria que procurar seus amigos do grupo dos ladrões e capturá-los, porém algum de seus amigos sentiram-se em desvantagens por não possuírem lugares estratégicos para se esconder no seu quintal.

Portanto decidiram planejar uma forma em que poderiam deixar os policiais sem saída e terem chances de ganhar o jogo. Para isso montaram um labirinto usando caixas de papelão e marcaram como “0” todos os lugares no quintal aonde os policiais poderiam atravessar e como “1” aonde os policiais não poderiam atravessar.

Os ladrões irão se esconder sempre no último espaço do labirinto, Se os policiais ficarem encurralados no labirinto os ladrões vencem e poderão comemorar a fuga, mas se os policiais alcançarem o ultimo espaço do labirinto os policiais serão os vencedores. Os policiais poderão andar somente nos blocos marcados como 0. Sua tarefa é determinar a partir do labirinto quem vai ganhar o jogo.



Entrada
A primeira entrada consiste de um inteiro T(1 ≤ T ≤ 400) indicando o número de casos de testes.

As próximas T entradas consistem de uma matriz 5x5, composta de valores inteiros, sendo 0 ou 1

Saída



/* 

Resolvendo problema de labirinto usando backtracking. 
O labirinto é representado por uma matriz 5x5, onde cada célula pode ser um caminho ou uma parede. 
O objetivo é encontrar um caminho do ponto de partida (0,0) até o ponto de chegada (4,4), evitando as paredes.
O programa utiliza a técnica de backtracking para explorar todas as possíveis rotas e encontrar a solução correta.

*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define MATRIZ_SIZE 5 

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

bool backtraking(labirinto &l, posicao p) {

    if (p.coordenada.first == 4 && p.coordenada.second == 4) {
        return true; // Chegou ao destino
    }

    l.matriz[p.coordenada.first][p.coordenada.second].isUsed = true;

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

            bool resolvido = backtraking(novoLabirinto, novaPosicao);
            if (resolvido) {
                return true; // Encontrou o caminho
            }
        }
    }

    return false; // Retorna o labirinto original se não encontrar um caminho válido
}


int main() {

    int N_casos;
    std::cin >> N_casos;
    labirinto l;
    int x;

    for(int NC = 0; NC < N_casos; NC++) {
        for(int i = 0; i < MATRIZ_SIZE; i++) {
            for (int j = 0; j < MATRIZ_SIZE; j++) {
                cin >> x;
                if (x == 1) {
                    l.matriz[i][j].isWall = true;
                    l.matriz[i][j].isUsed = false;
                } else if(x == 0) {
                    l.matriz[i][j].isWall = false;
                    l.matriz[i][j].isUsed = false;
                }
               
            }
        }

        posicao p;
        p.coordenada = make_pair(0, 0);

        bool resultado = backtraking(l, p);

        if(resultado) cout << "COPS" << endl;
        else cout << "ROBBERS" << endl;

    
    }

    return 0; 


}