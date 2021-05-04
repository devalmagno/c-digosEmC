#include <stdio.h>
#include <stdlib.h>

// 12) Escreva uma função que aceita como parâmetro um array de inteiros com N valores, e determina o maior elemento do array e o número de vezes que este elemento ocorreu no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15, 8, 6, 15, a função deve retornar para o programa que a chamou o valor 15 e o número 3 (indicando que o número 15 ocorreu 3 vezes). A função deve ser do tipo void. 

void namelessFunction(int array[], int size);

int main()
{
    system("cls");

    int i, size;

    printf(">>> POINTEIROS\n\n");

    printf("Digite quantos campos o array tera: ");
    scanf("%d", &size);

    int array[size];

    for (i = 0; i < size; i++) {
        printf("Digite o valor de Array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    i = 0;

    printf("\n\nEste e o array digitado: \n");

    while (i < size) {
        printf("[%d], ", array[i]);
        i++;
    }

    namelessFunction(array, size);

    return 0;
}

void namelessFunction(int array[], int size) {
    int i, pVezes = 0;
    int *pMaior;

    pMaior = &array[0];

    for (i = 1; i < size; i++) {
        if (*pMaior <= array[i]) {
            *pMaior = array[i];
            pVezes += 1;
        }
    }

    printf("\n\nO maior numero do array e %d\nE ele repete %d vezes dentro do array.\n", *pMaior, pVezes);
}