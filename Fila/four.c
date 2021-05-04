#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define CLEAR system("cls");

void insert();
void delete();
void display();

int rpos = -1, spos = -1;
int registrados = 0;

typedef struct cadastraAviao {
    int id;
    char nome[41]; 
} Aviao;

Aviao avioes[MAX];

int main() {
    int option;


    while (1) {
        CLEAR;
        
        printf(">> FILA\n");
        printf("\n1 - Adicionar aviao\n2 - Listar avioes\n3 - Autorizar decolagem\n0 - Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                delete();
                break;
            case 0:
                system("pause");
                exit(0);
                break;
            default: 
                printf("\nOpcao invalida.\n");
                system("pause");
        }
    }

    return 0;
}

void insert() {
    if (spos == MAX - 1) printf("\nFila cheia!!\n");
    else {
        if (rpos == -1) rpos = 0;

        spos = spos + 1;

        printf("Insira o nome do aviao: ");
        scanf(" %[^\n]*%c\n ", &avioes[spos].nome);
        
        avioes[spos].id = spos + 1;

        registrados++;
    }

    system("pause");
}

void delete() {
    int i;

    if (rpos == -1 || rpos > spos) {
        printf("\nNao ha aviao na fila para autorizar!\n");
        system("pause");
        return;
    }

    printf("\nO aviao %s foi autorizado decolagem.\n", avioes[rpos].nome);
    avioes[rpos].id = -1;

    rpos = rpos + 1;

    registrados--;
    
    system("pause");
}

void display() {
    int i, option;
    char name[41];

    if(rpos == -1) printf("\nA fila de espera esta vazia\n");
    else {
        printf("\nAvioes:\n");

        for (i = 0; i <= spos; i++) {
            if (avioes[i].id > 0) printf("[%d]: %s\n", i + 1, avioes[i].nome);
        }
    
        printf("\nDeseja ver as caracteristicas de algum aviao?\n");
        printf("\n1 - SIM\n2 - NAO\n");
        printf("\nEscolha: ");
        scanf("%d", &option);

        if (option == 1) {
            printf("\nNome do aviao: ");
            scanf(" %[^\n]*%c\n ", &name);

            for (i = 0; i < MAX; i++) {
                if (strcmp(avioes[i].nome, name) == 0) {
                    printf("\nNome do Aviao: %s\n", avioes[i].nome);
                    printf("\nNumero de identificacao: %d\n\n", avioes[i].id);
                }
            }
        }
    }

    system("pause");
}