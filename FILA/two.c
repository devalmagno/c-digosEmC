#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define CLEAR system("cls");

void insert();
void delete();
void display();

int queueArray[MAX];
int rpos = -1, spos = -1;

int main() {
    int option;

    while (1) {
        CLEAR;
        
        printf(">> FILA\n");
        printf("\n1 - Inserir numeros\n2 - Ver numeros\n3 - Remover negativos\n0 - Sair\n");
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
    int item, i;
    if (spos == MAX - 1) printf("\nFila cheia!!\n");
    else {
        if (rpos == -1) rpos = 0;

        for (i = 0; i < MAX; i++) {
            printf("Insira o numero na fila[%d]: ", i + 1);
            scanf("%d", &item);
        
            spos = spos + 1;
            queueArray[spos] = item;
        }
    }

    system("pause");
}

void delete() {
    int i;

    if (rpos == -1 || rpos > spos) {
        printf("\nNao ha nada na fila para deletar!\n");
        system("pause");
        return;
    }

    for (i = 0; i < MAX; i++) {
        if (queueArray[i] < 0) {
            printf("\nO elemento excluido da fila[%d] foi: %d\n", i + 1, queueArray[rpos]);
            queueArray[rpos] = 0;
        }

        rpos = rpos + 1; 
    }
    system("pause");
}

void display() {
    int i;

    if(rpos == -1) printf("\nA fila esta vazia\n");
    else {
        printf("\nFila:\n");

        for (i = 0; i <= spos; i++) {
            if (queueArray[i] != 0) printf("[%d]: %d\n", i + 1, queueArray[i]);
        }
    }

    system("pause");
}