#include <stdio.h>
#include <stdlib.h>

// 7) Crie um programa contendo um array de inteiros contendo 5 elementos. Utilizando apenas aritmética de ponteiros, leia este array do teclado e imprima o dobro de cada elemento. 

int main()
{
    system("cls");

    int array[5], i = 0;
    int *p;

    printf(">>> POINTEIROS\n\n");

    for (i = 0; i < 5; i++) {
        printf("Digite o valor de Array[%d]: ", i);
        scanf("%d", &array[i]);
        p = &array[i];
        *p += *p;        
    }

    i = 0;

    printf("\n\nEstes sao os valores apos a aritmetica de ponteiros: \n");
    while (i < 5) {
        printf("Array[%d] = %d\n", i, array[i]);
        i++;
    }

    return 0;
}