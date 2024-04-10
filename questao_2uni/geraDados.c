#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX_MAESTRIA (int)1e6
#define MAX_JOGADORES 5

struct Jogador {
  char nomeJogador[16];
  int maestria;
  char campeao[16];
};

int main(void) {
  struct Jogador jogadores[MAX_JOGADORES] = {};

  char *nomes[] = {
    "João", "Maria", "Pedro", "Ana", "Lucas",
    "Julia", "Marcos", "Fernanda", "Gustavo", "Camila",
    "Carlos", "Daniela","Fabiana","Henrique", "Isabela", 
    "Leonardo", "Mariana", "Nícolas", "Olívia", "Paulo", 
    "Rafael", "Sofia", "Tiago", "Ursula", "Vinícius", "Larissa"
  };

  char *campeoes[] = {
    "Leona", "Braum", "Caitlyn", "Diana", "Caitlyn", 
    "Braum", "Diana", "Hecarim", "Irelia", "Jinx",
    "Varus", "Leona", "Diana", "Zed", "Leona",
    "Caitlyn", "Jinx", "Braum", "Varus", "Zed",
    "Jinx", "Varus", "Warwick", "Hecarim", "Hecarim", "Zed"
  };

  int maestria[] = {
    100000, 175000, 250000, 260000, 300000, 
    333333, 400000, 444444, 480000, 520000, 
    557936, 600000, 678423, 700000, 750000, 
    777777, 799000, 800000, 850000, 875000, 
    890009, 900000, 925000, 950000, 975000, 999999
    };

  srand(time(NULL));

  bool escolhidos[26] = {false};

  for (int i = 0; i < 5;)
  {
    int indice = rand() % 26;

    if (!escolhidos[indice])
    {
      strcpy(jogadores[i].nomeJogador, nomes[indice]);
      jogadores[i].maestria = maestria[indice];
      strcpy(jogadores[i].campeao, campeoes[indice]);

      printf("%s %d %s\n", jogadores[i].nomeJogador, 
        jogadores[i].maestria, jogadores[i].campeao);
      escolhidos[indice] = true;
      i++;
    }
  }

  return 0;
}