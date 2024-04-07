#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numPedidos; // numberOfItems
int maximoPizzas; // capacity
int qntPizzaspPedido[31]; // weights
int tempoPorEntrega[30]; // values
int tabela[31][31];

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int motoboy(int item, int totPizzasRob)
{
  if (item == -1)
    return 0;

  if (tabela[item][totPizzasRob] < 0)
  {
    int tempo;

    if (totPizzasRob < qntPizzaspPedido[item])
      tempo = motoboy(item - 1, totPizzasRob);
    else
      tempo = max(motoboy(item - 1, totPizzasRob), 
        tempoPorEntrega[item] + motoboy(item - 1, totPizzasRob - qntPizzaspPedido[item]));

    tabela[item][totPizzasRob] = tempo;
  }

  return tabela[item][totPizzasRob];
}

int main(void) {
  scanf("%d", &numPedidos);

  while (numPedidos != 0)
  {
    memset(tabela, -1, sizeof(tabela));
    scanf("%d", &maximoPizzas);
    for (int i = 0; i < numPedidos; i++)
      scanf("%d %d", &tempoPorEntrega[i], &qntPizzaspPedido[i]);

    printf("%d min.\n", motoboy(numPedidos - 1, maximoPizzas));

    scanf("%d", &numPedidos);
  }

  return 0;
}