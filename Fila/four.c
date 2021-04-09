#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void clear() {
    #if defined(__linux__)
        system("clear");
    #endif

    #if defined(_WIN32)
        system("cls");
    #endif
}

#define MAX 10

int p[MAX];
int spos = 0;
int rpos = 0;

char qretrieve(void);
void qstore(char q);
void enter(void);
void review(void);
void delete(void);

int main() {
    int option;
    int i;

    for (i = 0; i < MAX; i++) p[i] = '\0';

    for (;;) {
        clear();
        printf("\n>> Pista de Decolagem");
        printf("\nI - Inserir numero\nL - Listar numeros\nR- Remover Negativos\nS - Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                enter();
                break;
            case 2:
                review();
                break;
            case 3:
                delete();
                break;
            case 0:
                exit(0);
            default:
                printf("Opção Inválida");
        }
    }

    printf("\n Presione ENTER para sair\n");
    getchar();
    
    return 0;
}

void enter(void) {
    int num;

    printf("Insira 0 para sair. \n\n");

    do {
        printf("Insira o numero [%d]: ", spos + 1);
        scanf(" %d", &num);
        
        if (num == 0) {
            return;
        } else {
            qstore(num);
        }
    } while (num != 0);
}

void qstore(char q) {
    if (spos == MAX) {
        printf("Lista cheia\n");
        return;
    }

    p[spos] = q;
    spos++;
}

void review(void) {
    int i;

    for (i = rpos; i < spos; i++) {
        printf("\n[%d]: %d", i + 1, p[i]);
    }

    printf("\n");
    
    if (rpos == spos) {
        printf("\nSem numeros para exibir.\n");
        printf("\nspos: %p", spos);
        printf("\nrpos: %p\n\n", rpos);
    }

    system("pause");
}

void delete(void) {
    int num;
    int tempNum;

    num = qretrieve();

    if (!num) return;
    printf("%d\n", num);

    scanf("%d", &tempNum);
    system("pause");
}

char qretrieve(void) {
    if (rpos == spos) {
        printf("Sem números para remover.\n");
        system("pause");
    }

    rpos++;
    return p[rpos--];
}