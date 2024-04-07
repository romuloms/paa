#include <stdio.h>

#define TAM 5

int labirinto[TAM][TAM];
int visitados[TAM][TAM] = {0};
int encontrou = 0;

void resetaVetores(int vet[TAM][TAM])
{
  for (int i = 0; i < TAM; i++)
    for (int j = 0; j < TAM; j++)
      vet[i][j] = 0;
}

int validaCasa(int x, int y)
{
  return (x >= 0 && x < TAM) && (y >= 0 && y < TAM) && (labirinto[x][y] == 0) && !visitados[x][y];
}

void policiaLadrao(int x, int y) {
  if (x == TAM - 1 && y == TAM - 1) 
  {
    encontrou = 1;
    return;
  }

  visitados[x][y] = 1;

  // cima
  if (validaCasa(x - 1, y))
    policiaLadrao(x - 1, y);
  // baixo
  if (validaCasa(x + 1, y))
    policiaLadrao(x + 1, y);
  // esquerda
  if (validaCasa(x, y - 1))
    policiaLadrao(x, y - 1);
  // direita
  if (validaCasa(x, y + 1))
    policiaLadrao(x, y + 1);
}

int main() 
{
  int T;
  scanf("%d", &T);

  for (int k = 0; k < T; k++)
  {
    for (int i = 0; i < TAM; i++)
      for (int j = 0; j < TAM; j++)
        scanf("%d", &labirinto[i][j]);

    policiaLadrao(0, 0); // comeca na casa [0][0]

    if (encontrou)
      printf("COPS\n");
    else
      printf("ROBBERS\n");

    encontrou = 0;
    resetaVetores(visitados);
    resetaVetores(labirinto);
  }
  return 0;
}