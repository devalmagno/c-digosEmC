#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    
    int option=10;


    printf("\n>>>    PONTEIROS\n\n");

    while(option != 0) {
        printf("Exercicio 1 - ID: \t 1\n\n");

        printf("Digite o ID do exercicio: ");
        scanf("%d\n\n", &option);

        switch (option)
        {
        case 1: ;
            int v1=0;
            int * p1;
            float v2=0; 
            float * p2;
            char v3=0;
            char * p3;

            printf("Digite o valor de INTEIRO v1: ");
            scanf("%d%*c\n", &v1);
            printf("Digite o valor de REAL v2: ");
            scanf("%f%*c\n", &v2);
            printf("Digite o valor de CHAR v3: ");
            scanf("%c%*c\n", v3);

            system("pause");
            break;
        default:
            break;
        }
    }
}