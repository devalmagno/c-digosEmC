#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1) Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando os ponteiros. Imprima os valores das variáveis antes e após a modificação. 

    // Declarando as váriaveis
    int var1 = 5;
    float var2 = 1;
    char var3[2] = "a";
    int *p1;
    float *p2;
    char *p3;
    p3 = (char*)malloc(2*sizeof(char));
    system("cls");

    printf(">>> PONTEIROS\n\n");

    printf("Valor das variaveis antes da modificacao... \n");

    printf("var1: %d\nvar2: %f\nvar3: %s\n\n", var1, var2, var3);

    // Associando os valores das váriaveis aos ponteiros
    p1 = &var1;
    p2 = &var2;
    p3 = var3;

    // Modificando os valores das váriaveis utilizando os ponteiros
    *p1 = 6;
    *p2 = 8;
    *p3 = 'b';

    printf("Valor das variaveis apos a modificacao\n");
    printf("var1: %d\nvar2: %f\nvar3: %s\n\n", var1, var2, var3);

    return 0;
}