#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls");
#define ESPACO printf("\n\n");
#define LINHA printf("\n");

int main()
{
    CLEAR;

    int linhas, colunas, i, j, armazenaI;

    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    int(*matriz)[colunas] = malloc(sizeof(int[linhas][colunas]));

    armazenaI = 0;

    ESPACO;

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("Digite o valor na posicao [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    ESPACO;

    for (i = 0; i < linhas; i++) {

        if (i > armazenaI) {
            printf("\n");
        }

        armazenaI = i;

        for (j = 0; j < colunas; j++) {
            printf("[%d]", matriz[i][j]);
        }
    }

    free(matriz);

    return 0;
}