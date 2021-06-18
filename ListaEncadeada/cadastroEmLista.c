#include <stdio.h>
#include <stdlib.h>

typedef struct cliente {
    int cpf;
    char nome[41];
    struct ponto * proximo;
} t_cliente;

int main() {
    t_cliente * ini_cliente;
    t_cliente * proximo_cliente;
    int resp, i = 1;

    ini_cliente = (t_cliente *)malloc(sizeof(t_cliente));
    if(ini_cliente == NULL)
        exit(1);

    while (1) {
        printf("Digite CPF do cliente [%d] (SOMENTE NUMEROS): ", i);
        scanf("%d", &proximo_cliente->cpf);
        printf("Digite o nome do cliente [%d]: ", i);
        scanf(" %[^\n]*%c\n ", &proximo_cliente->nome);
        
        printf("Deseja continuar?\n1 - SIM\n2 - NAO\n\n");
        printf("Escolha: ");
        scanf("%d", &resp);

        if (resp == 1) {
            proximo_cliente->proximo = (t_cliente *)malloc(sizeof(t_cliente));
            proximo_cliente = proximo_cliente->proximo;
        }
        else 
            break;
    }

    proximo_cliente->proximo = NULL;
    proximo_cliente = ini_cliente;

    return 0;
}