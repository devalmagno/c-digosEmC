#include <stdio.h>
#include <stdlib.h>

int n, i;

#define CLEAR system("cls");

void lerArray(int *array);

int main()
{
    CLEAR;

    printf("Tamanho do array: ");
    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));

    lerArray(array);

    printf("\n\n");

    for (i = 0; i < n; i++)
    {
        printf("Valor %d: %d\n", i + 1, array[i]);
    }

    free(array);

    return 0;
}

void lerArray(int *array)
{
    for (i = 0; i < n; i++)
    {
        printf("Valor %d: ", i + 1);
        scanf("%d", &array[i]);
    }
}