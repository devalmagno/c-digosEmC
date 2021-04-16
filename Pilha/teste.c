#include <stdio.h>
#include <stdlib.h>

#define PAUSE system("pause");
#define CLEAR system("cls");
#define TITLE printf("\n\n>> Pilha\n");

void push(int stack[], int *top, int stackSize, int Fila);
void pop(int stack[], int *top, int stackSize, int Fila);
void list(int stack[], int *top, int stackSize, int Fila);

int main() {
    CLEAR;
    
    int N, option, top[2] = {-1, 39};

    TITLE;

    int *stack = malloc(80 * sizeof(int));

    while(1) {
        CLEAR;
        TITLE;

        printf("\n1 - Empilhar valor\n2 - Desempilhar valores\n3 - Listar pilha\n0 - Sair\n\n");
        printf("\nEscolha: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                while (option != 0) {
                    CLEAR;
                    printf("\n>> Empilhar na pilha\n");

                    printf("\n1 - Pilha 1\n2 - Pilha 2\n0 - Sair\n");
                    printf("\nEscolha: ");
                    scanf("%d", &option);

                    if (option == 1) {
                        push(stack, &top[0], 80, 1);
                    } else if (option == 2) {
                        push(stack, &top[1], 80, 2);
                    } else if (option != 0) {
                        printf("Opcao nao existe!!\n");
                        PAUSE;
                    }
                }

                break;
            case 2: 
                while (option != 0) {
                    CLEAR;
                    printf("\n>> Desempilhar da pilha\n");

                    printf("\n1 - Pilha 1\n2 - Pilha 2\n0 - Sair\n");
                    printf("\nEscolha: ");
                    scanf("%d", &option);

                    if (option == 1) {
                        pop(stack, &top[0], 80, 1);
                    } else if (option == 2) {
                        pop(stack, &top[1], 80, 2);
                    } else if (option != 0) {
                        printf("Opcao nao existe!!\n");
                        PAUSE;
                    }
                }

                break;
            case 3:
                while (option != 0) {
                    CLEAR;
                    printf("\n>> Listar pilha\n");

                    printf("\n1 - Pilha 1\n2 - Pilha 2\n0 - Sair\n");
                    printf("\nEscolha: ");
                    scanf("%d", &option);

                    if (option == 1) {
                        list(stack, &top[0], 80, 1);
                    } else if (option == 2) {
                        list(stack, &top[1], 80, 2);
                    } else if (option != 0) {
                        printf("Opcao nao existe!!\n");
                        PAUSE;
                    }
                }

                break;
            case 0:
                PAUSE;
                exit(0);
                break;
            default:
                printf("Nao existe essa opcao!!!\n\n");
                PAUSE;
        }
    }

    return 0;
}

void push(int stack[], int *top, int stackSize, int Fila) {
    int number;

    if (*top == -1) {
        *top = 40 - 1;
    } else if (*top == 39) {
        *top = stackSize - 1;
    }

    printf("\n\nNumero: ");
    scanf("%d", &number);

    printf("\n\nStatus: ");
    stack[(*top) - 1] = number;
    (*top)--;

    printf("Empilhado %d na Fila %d.\n\n", stack[(*top)], Fila);

    PAUSE;
}

void pop(int stack[], int *top, int stackSize, int Fila) {
    printf("\n\nStatus: ");

    if (*top == -1 || *top == 39) {
        printf("A pilha esta vazia. \n\n");
    } else {
        printf("Fila %d - Desempilhado %d\n\n", Fila, stack[(*top)]);

        if (Fila == 1) {
            if ((*top) == 39 - 1) {
                (*top) = -1;
            } else {
                (*top)++;
            }
        } else {
            if ((*top) == stackSize - 2) {
                (*top) = 39;
            } else {
                (*top)++;
            }
        }
    }

    PAUSE;
}

void list(int stack[], int *top, int stackSize, int Fila) {
    int i, cont = 1;
    int nStack;

    if (Fila == 1) nStack = 40 - 1;
    else nStack = stackSize - 1;

    printf("\n\nPilha:\n\n");

    if (*top == -1 || *top == 39) {
        printf("Ainda nao ha elementos na pilha.\n");
        PAUSE;
        return;
    }

    for (i = nStack - 1; i >= *top; i--) {
        printf("Pilha %d [%d]: %d\n", Fila, cont, stack[i]);
        cont++;
    }

    PAUSE;
}