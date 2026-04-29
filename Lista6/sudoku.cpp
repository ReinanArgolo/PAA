/* Considere um jogo de Sudoku 4 × 4 tal qual a figura abaixo. Apresente um algoritmo que
resolva o jogo. Simule este algoritmo apresentando a árvore de soluções para o problema. */

/*  PROJETANDO BASE

1. O que são as escolhas?
    As escolhas são os números que não estão dispostos no sub-quadrado, e que não aparecem nem na mesma linha nem na mesma coluna


    Insights:
    - Podemos pensar em um vetor que contêm as possibilidades para cada célula e ir eliminando conforme forem sendo colocados elementos na matriz

2. O vetor solução agora deve ser uma matriz com 4 sub matrizes 2x2

3. podamos se existe um valor igual já inserido linha coluna


PERGUNTAS:

- Se a coluna ainda não chegou no fim ($< 3$), qual a próxima?
    R: Se a ccoluna ainda NAO chegou ao fim i++  

Se a coluna chegou no fim ($== 3$), para onde o "ponteiro" deve ir?
    R: se a coluna chegou ao fim, i = 0, j++;

*/

#include <stdio.h>
#include <iostream>
using namespace std;


typedef struct {
    int matriz[4][4];
} tabuleiro;

void imprimirTabuleiro(tabuleiro t) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", t.matriz[i][j]);
        }
        printf("\n");
    }
}

bool isValid(const tabuleiro &t, int linha, int coluna, int num) {
    for (int i = 0; i < 4; i++) {
        if (t.matriz[linha][i] == num) {
            return false; 
        }

        if (t.matriz[i][coluna] == num) {
            return false;
        }
        
    }

    int Srow = (linha / 2) * 2;
    int Scol = (coluna / 2) * 2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (t.matriz[Srow + i][Scol + j] == num) {
                return false; 
            }
        }
    }

    return true;
}

bool resolverSudoku(tabuleiro &t, int linha, int coluna, int nivel) {
    if (linha == 4) return true;

    int proxL = (coluna == 3) ? linha + 1 : linha;
    int proxC = (coluna == 3) ? 0 : coluna + 1;

    // Indentação para a árvore de decisão
    for (int i = 0; i < nivel; i++) printf("  ");

    if (t.matriz[linha][coluna] != 0) {
        printf("Celula (%d,%d) ja preenchida: %d\n", linha, coluna, t.matriz[linha][coluna]);
        return resolverSudoku(t, proxL, proxC, nivel + 1);
    }

    printf("Tentando celula (%d,%d):\n", linha, coluna);

    for (int i = 1; i <= 4; i++) {
        for (int n = 0; n < nivel + 1; n++) printf("  ");
        
        if (isValid(t, linha, coluna, i)) {
            printf("-> %d (Valido)\n", i);
            t.matriz[linha][coluna] = i;
            if (resolverSudoku(t, proxL, proxC, nivel + 1)) return true;
            
            for (int n = 0; n < nivel + 1; n++) printf("  ");
            printf("<- Backtrack de %d em (%d,%d)\n", i, linha, coluna);
            t.matriz[linha][coluna] = 0;
        } else {
            printf("-> %d (Invalido)\n", i);
        }
    }

    return false;
}


int main() {
    tabuleiro t = {
        {{1, 0, 0, 0},
         {0, 0, 0, 3},
         {0, 0, 0, 0},
         {2, 0, 0, 0}}
    };

    printf("Tabuleiro Inicial:\n");
    imprimirTabuleiro(t);
    printf("\nArvore de Decisao:\n");

    if (resolverSudoku(t, 0, 0, 0)) {
        printf("\nSudoku Resolvido:\n");
        imprimirTabuleiro(t);
    } else {
        printf("\nNao ha solucao.\n");
    }

    return 0;
}