#include <stdio.h>
#include <stdlib.h>

typedef struct CadastroProduto
{
    int id;
    char nome[50];
    double preco;
} Produto;

#define CLEAR_SCREEN system("cls");

int main()
{
    CLEAR_SCREEN;

    FILE *fp;

    Produto produtos[3];

    int achou, option = 1, i = 0;

    fp = fopen("products.txt", "a+b");
    if (fp == NULL) {
        printf("\nError cannot open file");
        exit(1);
    }

    while (3 > i)
    {
        printf("\nDigite o nome do %d produto: ", i + 1);
        scanf(" %[^\n]*%c\0 ", &produtos[i].nome);
        printf("Digite o preco do %d produto: R$ ", i + 1);
        scanf("%lf", &produtos[i].preco);
        printf("Digite o codigo do %d produto: ", i + 1);
        scanf("%d", &produtos[i].id);

        i++;
    }

    fwrite(&produtos, sizeof(Produto), 3, fp);


    while (feof(fp))
    {
        fread(&produtos, sizeof(Produto), 1, fp);
    }

    fclose(fp);


    for (i = 0; i < 3; i++)
    {
        printf("Codigo: %d\n", produtos[i].id);
        printf("Produto: %s\n\n", produtos[i].nome);
    }

    printf("Deseja ver o preco de algum produto?\n");
    printf("DIGITE O CODIGO DO PRODUTO OU 0 PARA SAIR.\n");

    while (option != 0)
    {
        printf("Entrada: ");
        scanf("%d", &option);

        if (option == 0)
        {
            return 0;
        }

        for (i = 0; i < 3; i++)
        {
            if (produtos[i].id == option)
            {
                printf("Preco: R$ %.2lf \n", produtos[i].preco);
                achou = 1;
            }
        }

        if (achou == 0)
        {
            printf("Não existe nenhum produto com esse código.\n");
        }
    }

    return 0;
}