#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls");

int main() {
    CLEAR;

    int i = 0;
    int *array = malloc(5 * sizeof(int));
    
    while (i < 5) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &array[i]);
        i++;
    }

    printf("\n\n");

    i = 0;
    while (i < 5) {
        printf("Valor %d: %d\n", i + 1, array[i]);
        i++;
    }

    free(array);

    return 0;
}