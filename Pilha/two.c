#include <stdio.h>
#include <stdlib.h>

#define PAUSE system("pause");
#define CLEAR system("cls");
#define TITLE printf("\n\n>> Pilha\n");

void push(int stack[], int *top, int stackSize);
void pop(int stack[], int *top, int stackSize);
void list(int stack[], int *top, int stackSize);

int main() {
    CLEAR;
    
    int N, option, top = -1;

    TITLE;

    printf("\nDigite a quantidade de elementos para a sequencia de Fibonacci: ");
    scanf("%d", &N);

    int *stack = malloc(N * sizeof(int));

    while(1) {
        CLEAR;
        TITLE;

        printf("\n1 - Acumular valor\n2 - Remover valores\n3 - Listar pilha\n4 - Sair\n\n");
        printf("\nEscolha: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                push(stack, &top, N);
                break;
            case 2: 
                pop(stack, &top, N);
                break;
            case 3:
                list(stack, &top, N);
                break;
            case 4:
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

void push(int stack[], int *top, int stackSize) {
    printf("\n\nStatus: ");

    if (*top == -1) {
        stack[stackSize - 1] = 0;
        *top = stackSize - 1;

        printf("adicionado %d\n\n", stack[*top]);
    } else if (*top == 0) {
        printf("a pilha ja esta cheia.\n\n");
    } else if (*top == stackSize - 1) {
        stack[(*top) - 1] = 1;
        (*top)--;

        printf("adicionado %d\n\n", stack[*top]);
    } else {
        stack[(*top) - 1] = stack[(*top)] + stack[(*top) + 1];
        (*top)--;

        printf("adicionado %d\n\n", stack[(*top)]);
    }

    PAUSE;
}

void pop(int stack[], int *top, int stackSize) {
    printf("\n\nStatus: ");

    if (*top == -1) {
        printf("A pilha esta vazia. \n\n");
    } else {
        printf("Removido %d\n\n", stack[(*top)]);

        if ((*top) == stackSize - 1) {
            (*top) = -1;
        } else {
            (*top)++;
        }
    }

    PAUSE;
}

void list(int stack[], int *top, int stackSize) {
    int i, cont = 1;

    printf("\n\nPilha:\n\n");

    if (*top == -1) {
        printf("Ainda nao ha elementos na pilha.\n");
        PAUSE;
        return;
    }

    for (i = stackSize - 1; i >= *top; i--) {
        printf("[%d]: %d\n", cont, stack[i]);
        cont++;
    }

    PAUSE;
}