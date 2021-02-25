#include <stdio.h>
#include <stdlib.h>

// 2) Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior endereço.

int main() {
    system("cls");

    int var1, var2;
    int *p1, *p2;
    
    printf(">>> POINTEIROS\n\n");
    printf("Digite o valor de var1: \t");
    scanf("%d", &var1);
    printf("Digite o valor de var2: \t");
    scanf("%d", &var2);

    p1 = &var1;
    p2 = &var2;

    printf("\n\nEndereco var1: %d \t | \t Endereco de var2: %d\n\n", p1, p2);

    printf("O conteudo da variavel de maior endereco e: \t");
    if (p1 > p2) {
        printf("%d VAR1", var1);
    } else {
        printf("%d VAR2", var2);
    }
}