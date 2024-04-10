/**
 * Partida de LoL
 * @author Romulo
 * 
 * Cinco amigos decidem jogar uma partida de League of Legends: Rômulo, Heitor, Itor,
 * Lanna e Lavínia. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAESTRIA (int)1e6  // Definindo a maestria máxima para o Counting Sort
#define MAX_JOGADORES 5  // Supondo um tamanho fixo para o array de jogadores para simplificar

// Definição do struct Jogaor
struct Jogador {
  char nomeJogador[16];
  int maestria;
  char campeao[16];
};

// Função para ordenar os campeões por maestria usando CountingSort
void ordenarPorMaestria(struct Jogador jogadores[], int n) {
  struct Jogador saida[n];
  int contagem[MAX_MAESTRIA + 1] = {0};
  int i;

  for(i = 0; i < n; ++i)
    contagem[jogadores[i].maestria]++;

  for(i = 1; i <= MAX_MAESTRIA; ++i)
    contagem[i] += contagem[i - 1];

  for(i = n - 1; i >= 0; --i) {
    saida[contagem[jogadores[i].maestria] - 1] = jogadores[i];
    contagem[jogadores[i].maestria]--;
  }
  
  int j = n - 1;
  for(i = 0; i < n; ++i) 
  {
    jogadores[j] = saida[i];
    j--;
  }
}

void ordenaCampeao(struct Jogador jogadores[], char* campeoes[MAX_JOGADORES])
{
  int contagem[28] = {0};
  struct Jogador saida[MAX_JOGADORES];
  char* copia[MAX_JOGADORES];
  
  for (int i = 0; i < MAX_JOGADORES; i++)
    contagem[jogadores[i].campeao[0] - 'A']++;
  
  for (int i = 1; i < 28; i++)
    contagem[i] += contagem[i - 1];
  
  for (int i = MAX_JOGADORES-1; i >= 0; i--)
  {
    copia[contagem[jogadores[i].campeao[0] - 'A'] - 1] = campeoes[i];
    saida[contagem[jogadores[i].campeao[0] - 'A'] - 1] = jogadores[i];
    contagem[jogadores[i].campeao[0] - 'A']--;
  }
  
  for (int i = 0; i < MAX_JOGADORES; i++)
  {
    campeoes[i] = copia[i];
    jogadores[i] = saida[i];
  }
}

// void imprimirJogador(struct Jogador jogadores[], int n) {
//   for(int i = 0; i < n; i++)
//     printf("Nome: %s, maestria: %d, campeao: %s\n", jogadores[i].nomeJogador, jogadores[i].maestria, jogadores[i].campeao);
// }

void getCampeoes(struct Jogador jogadores[], char* campeoes[MAX_JOGADORES])
{
  for (int i = 0; i < MAX_JOGADORES; i++)
  {
    campeoes[i] = malloc(strlen(jogadores[i].campeao + 1));
    if (campeoes[i] != NULL)
      strcpy(campeoes[i], jogadores[i].campeao);
  }
}

void liberaStr(char* campeoes[MAX_JOGADORES])
{
  for (int i = 0; i < MAX_JOGADORES; i++)
    if (campeoes[i] != NULL)
      free(campeoes[i]);
}

void resposta(struct Jogador jogadores[], char* campeoes[MAX_JOGADORES])
{
  int contador = 0;
  for (int i = 0; i < MAX_JOGADORES - 1; i++)
  {
    if ((strcmp(campeoes[i], campeoes[i+1]) == 0) && (contador == 0))
    {
      printf("%s jogará com %s\n", jogadores[i].nomeJogador, campeoes[i]);
      contador++;
    } else if ((strcmp(campeoes[i], campeoes[i+1]) == 0) && (contador != 0))
      contador++;
    else if ((strcmp(campeoes[i], campeoes[i+1]) != 0) && (contador == 0))
      printf("%s jogará com %s\n", jogadores[i].nomeJogador, campeoes[i]);
    else
      contador = 0;
  }
  if (strcmp(campeoes[MAX_JOGADORES - 2], campeoes[MAX_JOGADORES - 1]) != 0)
    printf("%s jogará com %s\n", jogadores[MAX_JOGADORES - 1].nomeJogador, campeoes[MAX_JOGADORES - 1]);
}

int main(void) {
  struct Jogador jogadores[MAX_JOGADORES] = {};
  int n = MAX_JOGADORES;
  char* copia[MAX_JOGADORES];

  for (int i = 0; i < MAX_JOGADORES; i++)
  {
    char nome[16];
    int maestria;
    char campeao[16];
    scanf("%s %d %s", nome, &maestria, campeao);
    strcpy(jogadores[i].nomeJogador, nome);
    jogadores[i].maestria = maestria;
    strcpy(jogadores[i].campeao, campeao);
  }

  ordenarPorMaestria(jogadores, n);
  getCampeoes(jogadores, copia);
  ordenaCampeao(jogadores, copia);

  resposta(jogadores, copia);
  
  liberaStr(copia);
  
  return 0;
}