#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAR system("cls");

void alocaString(char **string, int N);

int main() {
    CLEAR;

    int i, j, N;
    char *string;

    printf("Tamanho da string: ");
    scanf("%d", &N);

    alocaString(&string, N);

    printf("Digite o conteudo da string de %d posicoes: ", N);
    scanf("%s", string);
    printf("%s\n", string);

    while (string[i] != '\0') {
        if (string[i] == 'a') {
            string[i] = ' ';
        }
        i++;
    }

    // printf("String sem vogais: %s", string);

    return 0;
}

void alocaString(char **string, int N) {
    *string = (char *)malloc(N);
}