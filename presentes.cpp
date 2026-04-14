#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

typedef struct presentes{
    int id;
    int volume;
} presentes;
 

int main() {
 
    int t, n, k;

    int I, W, H, L;

    int m_Volume = 0, m_Vol2 = 0;


    cin >> t; // quantidade de casos de teste
    if(t < 1 || t<= 20) return 1;
 

    for (int i = 0; i < t; i++)  {
        cin >> n >> k; // quantidade de presentes e capacidade da caixa
        
        for (int j = 0; j < n; j++) {
            presentes p;
            cin >> p.id >> W  >> H >> L; // id e volume do presente

            p.volume = W * H * L; // calculando o volume do presente

            if (p.volume > m_Volume) {
                m_Vol2 = m_Volume;
                m_Volume = p.volume;
            } else if (p.volume > m_Vol2 && p.volume < m_Volume) {
                m_Vol2 = p.volume;
            } 
        }
        
    }


    return 0;
}