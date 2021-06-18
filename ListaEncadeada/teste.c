#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ponto {
    char cpf[20];
    char nome[41];
    int exibir;
    struct ponto * proximo;
} t_ponto;

void cadastrarCliente(t_ponto *cliente);
void excluiCliente(t_ponto *cliente);

int main() {
    t_ponto * ini_ponto;
    t_ponto * proximo_ponto;
    int resp, i = 0, exec = 0;
    char cpfParaApagar[20];

    ini_ponto = (t_ponto *)malloc(sizeof(t_ponto));
    if(ini_ponto == NULL)
        exit(1);

    proximo_ponto = ini_ponto;
    
    while(1) {
        printf("\n1 - Cadastrar\n2- Excluir\n0 - Sair\n\n");
        printf("Escolha: ");
        scanf("%d", &resp);

        if (resp == 0) exit(1);

        if (resp == 1) {
            cadastrarCliente(proximo_ponto);
            
            exec += 1;
        }

        if (resp == 2) {
            printf("Digite o CPF do cliente que voce deseja apagar: ");
            scanf(" %[^\n]*%c\n ", &cpfParaApagar);

            proximo_ponto = ini_ponto;
        
            for (i = 0; i < exec; i++) {
                if (strcmp(proximo_ponto->cpf, cpfParaApagar) == 0) {
                    proximo_ponto->exibir = 0;
                    printf("Cliente apagado com sucesso!!\n");
                } else {
                    if (i + 1 != exec) {
                        proximo_ponto = proximo_ponto->proximo;
                    }
                }
            }

            printf("\n");
        }

        proximo_ponto = ini_ponto;
        
        for (i = 0; i < exec; i++) {
            if (proximo_ponto->exibir != 0) {
                printf("Cliente [%d]\nCPF: %s\nNome: %s\n\n", i, proximo_ponto->cpf, proximo_ponto->nome);
            }

            if (i + 1 == exec) {
                proximo_ponto->proximo = (t_ponto *)malloc(sizeof(t_ponto));
            }

            proximo_ponto = proximo_ponto->proximo;
        }
    }

    return 0;
}

void cadastrarCliente(t_ponto *cliente) {
    printf("Digite CPF do cliente: ");
    scanf(" %[^\n]*%c\n ", &cliente->cpf);
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]*%c\n ", &cliente->nome);

    cliente->exibir = 1;

    printf("\n\nCliente cadastrado com sucesso!\n\n");
}