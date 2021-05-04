#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cadastraContaBancaria
{
    char cpf[14];
    char nome[50];
    double saldo;
} Cliente;

#define CLEAR_SCREEN system("cls");

int main()
{
    CLEAR_SCREEN;

    FILE *fp;

    Cliente clientes[3];

    int option, i = 0;
    double valorPSacar, valorPDepositar;
    char cpfPesquisa[14];

    fp = fopen("customers.txt", "a+b");
    if (fp == NULL)
    {
        printf("\nError cannot open file");
        exit(1);
    }

    while (3 > i)
    {
        printf("\nDigite o cpf do cliente n. %d: ", i + 1);
        scanf(" %[^\n]*%c\0 ", &clientes[i].cpf);
        printf("Digite o nome do cliente n. %d: ", i + 1);
        scanf(" %[^\n]*%c\0 ", &clientes[i].nome);
        printf("Digite o valor do deposito inicial do cliente n. %d: R$ ", i + 1);
        scanf("%lf", &clientes[i].saldo);

        i++;
    }

    printf("\n");

    for (i = 0; i < 3; i++)
    {
        printf("cpf: %s\n", clientes[i].cpf);
        printf("Saldo: %.2lf\n\n", clientes[i].saldo);
    }

    while (option != 0)
    {
        printf("Deseja realizar saque ou deposito?\n");
        printf("1 - Saque \t 2 - Deposito \t 0 - Sair \n");
        printf("Escolha: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0: 
            printf("Voce escolheu sair.");
            getchar();
            break;
        case 1:
            printf("\n\nDigite o cpf do cliente: ");
            scanf(" %[^\n]*%c\0 ", cpfPesquisa);

            for (i = 0; i < 3; i++)
            {
                if (strcmp(clientes[i].cpf, cpfPesquisa) == 0)
                {
                    printf("Quanto voce deseja sacar? R$ %.2lf \t R$ ", clientes[i].saldo);
                    scanf("%lf", &valorPSacar);

                    clientes[i].saldo -= valorPSacar;

                    printf("Nome do cliente: %s\n\n", clientes[i].nome);
                    printf("Saldo final: %.2lf\n", clientes[i].saldo);
                }
            }

            break;

        case 2:
            printf("\n\nDigite o cpf do cliente: ");
            scanf(" %[^\n]*%c\0 ", cpfPesquisa);

            for (i = 0; i < 3; i++)
            {
                if (strcmp(clientes[i].cpf, cpfPesquisa) == 0)
                {
                    printf("Quanto voce deseja depositar? R$ %.2lf \t R$ ", clientes[i].saldo);
                    scanf("%lf", &valorPDepositar);

                    clientes[i].saldo += valorPDepositar;

                    printf("Nome do cliente: %s\n\n", clientes[i].nome);
                    printf("Saldo final: %.2lf\n", clientes[i].saldo);
                }
            }

            break;
        default:
            printf("\n\nEssa opcao nao existe.\n");

            break;
        }
    }

    
    fwrite(&clientes, sizeof(Cliente), 3, fp);

    fclose(fp);

    return 0;
}