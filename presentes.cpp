#include <stdio.h>
#include <iostream>
using namespace std;
#include <vector>

typedef struct presente{
    int id;
    int volume;
} presente;



/* bee crowd 2720

Bruninho adora o natal! Ele gosta da comida, das músicas clássicas, e, especialmente, dos presentes que o Papai Noel lhe dá todos os anos!

Assim como nos anos anteriores, Bruninho irá ganhar exatamente K presentes dentre os N presentes que Papai Noel tem disponível. Agora, ele deve decidir quais presentes ele irá pedir para o bom velhinho.

Como toda criança pensa, quanto maior é o pacote do presente, mais legal o presente é! Logo, ele decidiu pedir os presentes com os K maiores volumes. Dada a descrição de todos os N presentes que o Papai Noel tem, determine os K presentes que Bruninho deve pedir.

Entrada
A primeira linha contém um inteiro T (≤20), o número de casos de teste.

A primeira linha de cada caso de teste contém dois inteiros N e K (1 ≤ N ≤ 103 * ou 1 ≤ N ≤ 105 **, 1 ≤ K ≤ N), o número de presentes que o Papai Noel tem e o número de presentes que Bruninho irá ganhar.

Cada uma das próximas N linhas descrevem um presente. Cada linha contém quatro inteiros I, H, W e L (0 ≤ I ≤ 109, 1 ≤ H, W, L ≤ 100), o número de identificação (id) do presente e a altura, largura e comprimento do seu pacote, em centímetros. Todos os presentes tem ids diferentes.

* Em aproximadamente 40% dos casos de teste
** Nos demais casos de teste

Saída
Para cada caso de teste, imprima uma linha contendo K inteiros, separados por espaços, descrevendo os ids dos presentes que Bruninho deve pedir. Imprima os ids em ordem crescente. Não imprima um espaço após o último id.

Se existir mais de uma solução possível, imprima a lexicograficamente menor, isto é, o menor id na saída deve ser minimizado; no caso de empate, o segundo menor id na saída deve ser minimizado, e assim por diante.

*/

int main() {
 
    int t, n, k;

    int I, W, H, L;


    cin >> t; // quantidade de casos de teste
    if(t < 1 || t >= 20) return 1;
 

    for (int i = 0; i < t; i++)  {
        cin >> n >> k; // quantidade de presentes e capacidade da caixa

        // lista de presentes
        
        presente presentes[k] = {0}; // inicializando a lista de presentes

        for (int j = 0; j < n; j++) {
            presente p;
            cin >> p.id >> W  >> H >> L; // id e volume do presente

            p.volume = W * H * L; // calculando o volume do presente 
            
           presentes[j] = p; // adicionando o presente na lista de presentes
        }

        vector<presente> presentesV(presentes, presentes + n); // convertendo o array de presentes para um vetor

        sort
        


        // ordenar pelo volume do presente
        for (int j = 0; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                if (presentes[j].volume < presentes[l].volume) {
                    presente temp = presentes[j];
                    presentes[j] = presentes[l];
                    presentes[l] = temp;
                }
            }
        }

        // imprimir os k maiores volumes
        for (int j = 0; j < k; j++) {
            cout << presentes[j].id << " ";
        }
        cout << endl;
    }

    return 0;
}