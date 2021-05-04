#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAR system("cls");
#define ESPACO printf("\n\n");
#define LINHA printf("\n");

int main()
{
    CLEAR;

    int linhas, i, j, option = 10, modify, found;
    char search[30];

    printf("Digite o numero de nomes para armazenar: ");
    scanf("%d", &linhas);

    char **matriz = malloc(linhas * sizeof(char *));

    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (char *)malloc(30);
    }

    ESPACO;

    while (option != 0) {
        printf("1 - Gravar | 2 - Pesquisar | 3 - Ler | 0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &option);

        CLEAR;

        switch (option)
        {
            case 1:
                printf("Escolha a linha de 0 a %d: ", linhas - 1);
                scanf("%d", &modify);

                printf("Digite o nome a ser inserido: ");
                // scanf(" %[^\n]*%c\0 ", &matriz[modify]);
                // gets(matriz[modify]);
                scanf("%s\0", matriz[modify]);

                break;

            case 2: 
                printf("Informe nome para pesquisar: ");
                scanf("%s", search);

                for (i = 0; i < linhas; i++) {
                    if (strcmp(matriz[i], search) == 0) {
                        printf("Nome: %s Linha: %d\n", matriz[i], i);

                        ESPACO;

                        printf("1 - Alterar | 2 - Remover\n");
                        printf("Escolha: ");
                        scanf("%d", &option);

                        LINHA;

                        switch (option)
                        {
                        case 1:
                            printf("Digite o novo nome: ");
                            scanf("%s\0", matriz[i]);

                            break;

                        case 2: 
                            matriz[i] = "";

                            printf("Apagado com sucesso.\n");
                            getchar();

                            break;
                        
                        default:
                            break;
                        }
                    }
                }

                break;

            case 3: 
                printf("Escolha a linha de 0 a %d: ", linhas - 1);
                scanf("%d", &modify);

                printf("Nome: %s\n", matriz[modify]);

                break;
            
            default:
                break;
        }
    }

    return 0;
}