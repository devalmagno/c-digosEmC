#include <stdio.h>
#include <stdlib.h>

// 6) Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas. Imprima o endereço de cada posição dessa matriz. 

int main()
{
    system("cls");

    float matriz[3][3];

    printf(">>> POINTEIROS\n\n");

    printf("\t0 \t 1 \t    2\n");

    for (int i = 0; i < 3; i++) {
        printf("%d ", i);     
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = rand() % 100;
        
            if (j != 2) {
                printf("[%p] ", &matriz[i][j]);
            } else {
                printf("[%p]\n", &matriz[i][j]);
            }
        }
    }

    return 0;
}