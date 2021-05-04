#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define CLEAR system("cls");

void insert(int queue);
void display(int queue);
void intercalar(int queueOne[], int queueTwo[]);

int majorQueue[MAX + MAX];
int queueOne[MAX];
int queueTwo[MAX];
int intercalou = 0;
int rpos[2] = { -1, -1};
int spos[2] = { -1, -1};

int main() {
    int option;

    while (1) {
        CLEAR;
        
        printf(">> FILA\n");
        printf("\n1 - Inserir numeros\n2 - Ver numeros\n3 - Intercalar Filas\n0 - Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("inserir na fila 1 ou 2? ");
                scanf("%d", &option);
                insert(option);
                break;
            case 2:
                printf("\nFilas:\n1\n2\n3 - Intercalada\n");
                printf("\nEscolha: ");
                scanf("%d", &option);
                display(option);
                break;
            case 3:
                intercalar(queueOne, queueTwo);

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

void insert(int queue) {
    int item, i;

    switch (queue) {
        case 1:
            if (spos[0] == MAX - 1) printf("\nFila 1 esta cheia!!\n");
            else {
                if (rpos[0] == -1) rpos[0] = 0;

                for (i = 0; i < MAX; i++) {
                    printf("Insira o numero na fila 1 [%d]: ", i + 1);
                    scanf("%d", &item);
                
                    spos[0] = spos[0] + 1;
                    queueOne[spos[0]] = item;
                }
            }       

            break;
        case 2:
            if (spos[1] == MAX - 1) printf("\nFila 2 esta cheia!!\n");
            else {
                if (rpos[1] == -1) rpos[1] = 0;

                for (i = 0; i < MAX; i++) {
                    printf("Insira o numero na fila 2 [%d]: ", i + 1);
                    scanf("%d", &item);
                
                    spos[1] = spos[1] + 1;
                    queueTwo[spos[1]] = item;
                }
            }       

            break;
    }

    system("pause");
}

void display(int queue) {
    int i;

    switch (queue) {
        case 1:
            if(rpos[0] == -1) printf("\nA fila 1 esta vazia\n");
            else {
                printf("\nFila 1:\n");

                for (i = 0; i <= spos[0]; i++) {
                    printf("[%d]: %d\n", i + 1, queueOne[i]);
                }
            }

            break;
        case 2:
            if(rpos[1] == -1) printf("\nA fila 2 esta vazia\n");
            else {
                printf("\nFila 2:\n");

                for (i = 0; i <= spos[1]; i++) {
                    printf("[%d]: %d\n", i + 1, queueTwo[i]);
                }
            }
        case 3:
            if (intercalou == 0) {
                printf("\nFila ainda nao implementada.\n");
            }

            printf("\nFila intercalada:\n");

            for (i = 0; i < 20; i++) {
                printf("[%d]: %d\n", i + 1, majorQueue[i]);
            }

            break;
    }

    system("pause");
}

void intercalar(int queueOne[], int queueTwo[]) {
    int size = MAX + MAX;
    int i, j;
    int contV1 = 0, contV2 = 0;
    
    for (i = 0; i < 20; i++) {
        if (i % 2 == 0) {
            majorQueue[i] = queueOne[contV1];
            contV1++;
        } else {
            majorQueue[i] = queueTwo[contV2];
            contV2++;
        }
    }

    intercalou = 1;
}