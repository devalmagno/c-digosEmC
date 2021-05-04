#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls");
#define ESPACO printf("\n\n");

int main()
{
    CLEAR;

    int tamanho, code, option = 10;

    printf("Digite o numero de bytes para alocar: ");
    scanf("%d", &tamanho);

    int *array = calloc(tamanho, sizeof(int));

    ESPACO;

    while (option != 0)
    {
        printf("O que voce quer fazer?");
        ESPACO;
        printf("1 - Consultar \t | \t 2 - Consultar");
        ESPACO;
        printf("Escolha: ");
        scanf("%d", &option);

        ESPACO;

        switch (option)
        {
            case 2:
                printf("Posicao no array: ");
                scanf("%d", &code);

                printf("Array[%d] = %d\n", code, array[code]);

                break;
            case 1:
                printf("Posicao no array: ");
                scanf("%d", &code);

                printf("Array[%d] = %d, antes da modificacao...\n", code, array[code]);
                printf("Digite o novo valor de Array[%d] = ", code);
                scanf("%d", &array[code]);

                printf("Array[%d] = %d, apos a modificacao...\n", code, array[code]);
                break;
            default:
                break;
        }
    }

    return 0;
}