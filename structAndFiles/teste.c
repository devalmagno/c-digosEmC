#include <stdio.h>
#include <stdlib.h>

typedef struct CadastroProduto {
    int id;
    char nome[50];
    double preco;
} Produto;

int main() {
    Produto produtos[100];

    int repete, achou, option = 1, numeroDeProdutos = 0, i = 0;

    printf("Quantos produtos voce deseja cadastrar? ");
    scanf("%d", &repete);

    while (repete > i) {
        printf("\nDigite o nome do produto: ");
        scanf(" %[^\n]*%c\0 ", &produtos[i].nome);
        printf("Digite o preco do produto: R$ ");
        scanf("%lf", &produtos[i].preco);
        printf("Digite o codigo do produto: ");
        scanf("%d", &produtos[i].id);

        numeroDeProdutos += 1;
        i++;
    }

    for (i = 0; i < numeroDeProdutos; i++) {
        printf("Codigo: %d\n", produtos[i].id);
        printf("Produto: %s\n\n", produtos[i].nome);
    }

    printf("Deseja ver o preco de algum produto?\n");
    printf("DIGITE O CODIGO DO PRODUTO OU 0 PARA SAIR.\n");
    
    while (option != 0) {
        printf("Entrada: ");
        scanf("%d", &option);

        if (option == 0) {
            return 0;
        }

        size_t n = sizeof produtos / sizeof *produtos;

        for (i =0; i < n; i++) {
            if (produtos[i].id == option) {
                printf("Preco: R$ %.2lf \n", produtos[i].preco);
                achou = 1;
            }
        }

        if (achou == 0) {
            printf("Não existe nenhum produto com esse código.\n");
        }
    }

    return 0;
}