#include <stdio.h>
#include <stdlib.h>

// 4) Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2 valores de entrada e retorne o maior valor na primeira variável e o menor valor na segunda variável. Escreva o conteúdo das 2 variáveis na tela.

void trocaValoresSeMaior();

int main()
{
    system("cls");

    int a, b;

    printf(">>> POINTEIROS\n\n");

    printf("Digite o valor de A: \t");
    scanf("%d", &a);
    printf("Digite o valor de B: \t");
    scanf("%d", &b);

    printf("\n\nValores antes de chamar a funcao: \n");
    printf("A: %d \t | \t B: %d\n\n", a, b);

    trocaValoresSeMaior(&a, &b);

    printf("Apos chamar a funcao: \n");
    printf("A: %d \t | \t B: %d\n\n", a, b);

    return 0;
}

void trocaValoresSeMaior(int *a, int *b)
{
    int b_value = *b;

    if (*b > *a) {
        *b = *a;
        *a = b_value;
    }
}