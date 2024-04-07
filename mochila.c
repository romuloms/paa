// qnt pizzas é o peso da mochila
// tempo é o valor dos itens
// maximo de 10 pizzas é a capacidade da mochila

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pesos[100];
int valores[100];
int tabela[100][100];
int qtdeItens, capacidade;

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int mochila(int item, int capacidade)
{
  if (item == qtdeItens)
    return 0;
  
  if (tabela[item][capacidade] != -1)
    return tabela[item][capacidade];

  int naoPega = mochila(item + 1, capacidade);
  int pega = 0;

  if (pesos[item] <= capacidade)
    pega = valores[item] + mochila(item + 1, capacidade - pesos[item]);

  tabela[item][capacidade] = max(pega, naoPega);

  return tabela[item][capacidade];
}

int main(void) {
  scanf("%d %d", &qtdeItens, &capacidade);

  for (int i = 0; i < qtdeItens; i++)
    scanf("%d %d", &pesos[i], &valores[i]);
  
  memset(tabela, -1, sizeof(tabela));
  printf("valor max: %d\n", mochila(0, capacidade));

  return 0;
}
