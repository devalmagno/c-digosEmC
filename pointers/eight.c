#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 8) Elabore uma função que receba duas strings como parâmetros e verifique se a segunda string ocorre dentro da primeira. Use aritmética de ponteiros para acessar os caracteres das strings.

void checkIfSubstringExists(char *first_str, char *sub_str);

int main()
{
    system("cls");

    char first_str[100], sub_str[100];

    printf(">>> POINTEIROS\n\n");

    printf("Digite o conteudo da primeira string: ");
    scanf(" %[^\n]*%c\n ", &first_str);
    printf("Digite o conteudo da segunda string: ");
    scanf(" %[^\n]*%c\n ", &sub_str);

    checkIfSubstringExists(first_str, sub_str);

    return 0;
}

void checkIfSubstringExists(char *first_str, char *sub_str) {
    if (strstr(first_str, sub_str)) {
        printf("\n\nA segunda string ocorre dentro da primeira.\n\n");
    } else {
        printf("\n\nA segunda string nao ocorre dentro da primeira.\n\n");
    }
}