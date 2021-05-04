#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define CLEAR system("cls");
#define ESPACO printf("\n\n");
#define LINHA printf("\n");

typedef struct cadastraCidades {
    char nome[41];
    float cordX;
    float cordY;
} Cidades;

int main() {
    CLEAR;

    int N, i, j;

    printf("Digite o numero de cidades: ");
    scanf("%d", &N);

    Cidades *city = (Cidades*)malloc(N * sizeof(Cidades));

    LINHA;

    for (i = 0; i < N; i++) {
        printf("Nome da cidade [%d]: ", i + 1);
        scanf(" %[^\n]*%c\n ", &city[i].nome);
        printf("Cordenada X: ");
        scanf("%f", &city[i].cordX);
        printf("Cordenada Y: ");
        scanf("%f", &city[i].cordY);

        LINHA;
    }

    float(*distancias)[N] = malloc(sizeof(int[N][N]));

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (strcmp(city[i].nome, city[j].nome) != 0) {
                distancias[i][j] = fabsf(city[i].cordX - city[j].cordX) + fabsf(city[i].cordY - city[j].cordY);
            }
        }
    }

    CLEAR;

    printf("Cidades\n");
    LINHA;

    for (i = 0; i < N; i++) {
        printf("[%d] - %s distancia ate \n", i, city[i].nome);

        for (j = 0; j < N; j++) {
            if (strcmp(city[i].nome, city[j].nome) != 0) {
                printf("%s: %fkm\n", city[j].nome, distancias[i][j]);
            }
        }    

        LINHA;
    }

    printf("Consultar distancia entre duas cidades\n\n");
    printf("Cidade 1: ");
    scanf("%d", &i);
    printf("Cidade 2: ");
    scanf("%d", &j);

    ESPACO;

    printf("A distancia entre %s e %s e de %fkm\n", city[i].nome, city[j].nome, distancias[i][j]);

    return 0;
}