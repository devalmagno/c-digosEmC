#include <stdio.h>
#include <stdlib.h>

// 10) Considere a seguinte declaração: int A, *B e **C; Escreva um programa que leia a variável A e calcule e exiba o dobro e o triplo desse valor utilizando apenas os ponteiros B e C. O ponteiro B deve ser usada para calcular o dobro e C o triplo.

int main()
{
    system("cls");

    int A = 15;
    int *B, *C;

    printf(">>> POINTEIROS\n\n");

    printf("O valor inicial de A e: %d\n\n", A);

    B = &A;
    *B += *B;

    printf("O valor de A apos o ponteiro B [DOBRO] e: %d\n\n", A);

    C = &A;
    *C += *B/2;

    printf("O valor de A apos o ponteiro C [TRIPLO] e: %d\n\n", A);

    return 0;
}