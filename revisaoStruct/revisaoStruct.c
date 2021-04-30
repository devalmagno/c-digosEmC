/*Codigo exemplo incompleto, utilizando struct com ponteiro */

/*1 - Faça um tratamento de erro para que o algoritmo verifique se a memoria foi alocada corretamente. */

/*2 - Adicione os demais campos da estrutura nas funcoes inputval e showval*/

/*3 - Comente o código explicando o que está sendo feito nas linhas 48 e 49 explicando a diferença entre elas.*/

/*4 - Faça uma função que verifique se uma ação esta com um ROE maior que 30 e o Dividend Yield maior que 10 */

/*5 - Sugerir melhorias no código */

#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

//Definição do tipo
typedef struct valuation{
  char business_name[30];
  char stock_name[6];
  float stock_value;
  float dy;
  float lp;
  float ROE;
} tValuation;

//Cabecalho das funcoes
int inputval(tValuation *in_stock);
int showval(tValuation *in_stock);
int verifyVal(tValuation *in_stock);

int main()
{
  
  setlocale(LC_ALL, "Portuguese");

  tValuation *stock1 = NULL;

  stock1 =  malloc(sizeof(tValuation));

  if (stock1 == NULL)
    {
      printf("Erro ao alocar memoria!");
      return 1;
    }
  
  inputval(stock1);
  showval(stock1);
  verifyVal(stock1);

    // Professor não entendi muito bem pois as linhas 48 e 49 no arquivo estão apontando para uma vazia e para a função free(stock1), porém creio que o senhor se referiu a chamada das funções inputval e showval.
    // Na linha 48 e 49 são chamadas funções para agir diretamente com a nossa struct valuation. A diferença da linha 48 para a linha 49 é que, na linha 48 é chamada uma função para inserir dados na struct, sendo passado a struct como parâmetro. Já na linha 49 é chamada uma função para mostrar os dados na struct, e também é passado a struct como parâmetro.
  
  free(stock1);
  
  return 0;
}

int inputval(tValuation *in_stock)
{
  printf("Digite o nome da empresa: ");
  setbuf(stdin,NULL);
  fgets(in_stock->business_name,30,stdin);

  printf("Digite o nome da acao: ");
  setbuf(stdin,NULL);
  fgets(in_stock->stock_name,30,stdin);

  printf("Digite o valor por cada acao: ");
  scanf("%f",&in_stock->stock_value);

  printf("Digite o valor pago em dividendos pela empresa em 2020: ");
  scanf("%f",&in_stock->dy);

  printf("Digite o LP da empresa em 2020: ");
  scanf("%f",&in_stock->lp);
  
  printf("Digite o ROE da empresa em 2020: ");
  scanf("%f",&in_stock->ROE);   

  printf("\n%p\n",in_stock);
  printf("\n%p\n",&in_stock->dy);

  in_stock = NULL;
  
  return 0;
}

int showval(tValuation *in_stock)
{
  printf("O nome da empresa e: %s \n",in_stock->business_name);
  printf("O nome da acao e: %s \n", in_stock->stock_name);


  printf("O valor da acao e: %f \n", in_stock->stock_value);
  printf("O valor do dividendo pago pela empresa foi: %.2f\n",in_stock->dy);
  printf("O LP de 2020 foi: %.2f \n", in_stock->lp);
  printf("O ROE de 2020 foi: %.2f \n", in_stock->ROE);

  return 0;
}

int verifyVal(tValuation *in_stock) {
    printf("\n\n");

    if (in_stock->ROE > 30) {
        printf("O ROE e maior do que 30. ROE: %f\n", in_stock->ROE);
    } else {
        printf("O ROE e menor do que 30. ROE: %f\n", in_stock->ROE);
    }

    if (in_stock->dy > 10) {
        printf("O DY e maior do que 10. DY: %f\n", in_stock->dy);
    } else {
        printf("O DY e menor do que 10. DY: %f\n", in_stock->dy);
    }
}