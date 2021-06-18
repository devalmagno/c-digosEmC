#include <stdio.h>
#include <stdlib.h>
#define s_str 30

struct lista
{
  char nome[s_str];
  int cpf;
  struct lista *prox;
} typedef t_lista;

t_lista *criarlista()
{
  t_lista *nova_lista = NULL;

  nova_lista = malloc(sizeof(t_lista));

  if (nova_lista == NULL)
  {
    printf("Não foi possivel criar alocar a memoria!");
    exit(1);
  }
  printf("Digite o cpf do primeiro cadastro: ");
  scanf("%d", &nova_lista->cpf);
  printf("Digite o nome do primeiro cadastro: ");
  scanf("%s", nova_lista->nome);

  nova_lista->prox = NULL;

  return (nova_lista);
}

t_lista *inserir_fim(t_lista *lista)
{
  t_lista *ptrant = NULL;
  t_lista *ptrlista = lista;
  t_lista *novono = NULL;

  novono = malloc(sizeof(t_lista));

  while (ptrlista != NULL)
  {
    ptrant = ptrlista;
    ptrlista = ptrlista->prox;
  }
  printf("Digite o cpf do cadastro: ");
  scanf("%d", &novono->cpf);
  printf("Digite o nome do cadastro: ");
  scanf("%s", novono->nome);

  novono->prox = NULL;

  ptrant->prox = novono;

  return (lista);
}

int excluir_no(t_lista *lista)
{
  t_lista *ptrlista = lista;
  t_lista *ptraux = NULL;
  int in_cpf;

  printf("Digite o cpf que deseja excluir: ");
  scanf("%d", &in_cpf);
  while (ptrlista->cpf == in_cpf || ptrlista->prox != NULL)
  {
    ptraux = ptrlista;

    ptrlista = ptrlista->prox;
  }

  ptraux->prox = ptrlista->prox;

  free(ptrlista);
  return 0;
}

int show_lista(t_lista *lista)
{
  t_lista *ptrlista = lista;

  while (ptrlista != NULL)
  {
    printf("\nO Nome da pessoa e: %s", ptrlista->nome);
    printf("\nO CPF da pessoa e: %d\n", ptrlista->cpf);

    ptrlista = ptrlista->prox;
  }
  return 0;
}

int main()
{
  int q;
  t_lista *lista = criarlista();
  //while (1)
  //{
  show_lista(lista);
  lista = inserir_fim(lista);
  show_lista(lista);
  //  printf("Digite 1 para cadastrar, 2 para excluir ou 3 para sair: ");
  // scanf("%d", &q);
  // if (q == 1)
  // {
  //  lista = inserir_fim(lista);
  // } else if (q == 2)
  // {
  // lista = excluir_no(lista);
  // }  else if (q == 3)
  // {
  // exit(1);
  // }  else{
  // printf("\nOpcao invalida\n");
  // }
  //  }
  return 0;
}
