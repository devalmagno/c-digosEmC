#include <stdio.h>
#include <stdlib.h>

// 3) Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis e troque o seu conteúdo (por referência), ou seja, esta função é chamada passando duas variáveis A e B por exemplo e, após a execução da função, A conterá o valor de B e B conterá o valor de A.

void trocaValores();

int main() {
    system("cls");

    int a, b;
    
    printf(">>> POINTEIROS\n\n");

    printf("Digite o valor de A: \t");
    scanf("%d", &a);
    printf("Digite o valor de B: \t");
    scanf("%d", &b);

    printf("\n\nAntes de trocar os valores: \n");
    printf("A: %d \t | \t B: %d\n\n", a, b);

    trocaValores(&a, &b);

    printf("Apos a troca de valores: \n");
    printf("A: %d \t | \t B: %d\n\n", a, b);

    return 0;
}

void trocaValores(int *a, int *b) {
    int b_value = *b;
    *b = *a;
    *a = b_value; 
}