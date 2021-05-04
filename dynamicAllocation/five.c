#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define CLEAR system("cls");
#define ESPACO printf("\n\n");
#define LINHA printf("\n");

typedef struct cadastraAlunos {
    int matricula;
    char sobrenome[50];
    int dia;
    int mes;
    int ano;
} Alunos;

void gotoxy(int x, int y);

int main() {
    CLEAR;

    int N, i;

    printf("Digite o numero de alunos para armazenar: ");
    scanf("%d", &N);

    Alunos *array = (Alunos*)malloc(N * sizeof(Alunos));

    for (i = 0; i < N; i++) {
        CLEAR;
        printf("Digite o numero da matricula do aluno %d: ", i + 1);
        scanf("%d", &array[i].matricula);
        printf("Digite o sobrenome do aluno %d: ", i + 1);
        scanf(" %[^\n]*%c\n ", &array[i].sobrenome);
        printf("Digite a data de nascimento do aluno %d:  DD/MM/AA ", i + 1);

        gotoxy(52, 2);
        printf("/");
        gotoxy(55, 2);
        printf("/");

        gotoxy(50, 2);
        scanf("%d", &array[i].dia);
        gotoxy(53, 2);
        scanf("%d", &array[i].mes);
        gotoxy(56, 2);
        scanf("%d", &array[i].ano);
    }

    CLEAR;

    for (i = 0; i < N; i++) {
        printf("Aluno[%d]\n", i + 1);
        printf("Matricula: %d\n", array[i].matricula);
        printf("Sobrenome: %s\n", array[i].sobrenome);
        printf("Data de nascimento: %d/%d/%d\n", array[i].dia, array[i].mes, array[i].ano);

        LINHA;
    }

    free(array);

    return 0;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}