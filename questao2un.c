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

#define MAX_MAESTRIA 100  // Definindo a maestria máxima para o Counting Sort
#define TAMANHO_ARRAY 10  // Supondo um tamanho fixo para o array de jogadores para simplificar

// Definição do struct Aluno
struct Jogador {
  char nomeJogador[16];
  int maestria;
  char campeao[16];  // 'M' para masculino, 'F' para feminino
};

// Função para ordenar os jogadores por maestria usando Counting Sort
void ordenarPormaestria(struct Jogador jogadores[], int n) {
  struct Jogador saida[n];  // Array de saída que terá os jogadores ordenados
  int contagem[MAX_MAESTRIA + 1], i;
  
  memset(contagem, 0, sizeof(contagem));  // Inicializa o array de contagem com 0
  
  // Armazena a contagem de ocorrências de cada maestria
  for(i = 0; i < n; ++i) {
    contagem[jogadores[i].maestria]++;
  }
  
  // Altera contagem[i] para que contagem[i] agora contenha a posição real desta maestria na array de saída
  for(i = 1; i <= MAX_MAESTRIA; ++i) {
    contagem[i] += contagem[i - 1];
  }
  
  // Constrói o array de saída
  for(i = n - 1; i >= 0; --i) {
    saida[contagem[jogadores[i].maestria] - 1] = jogadores[i];
    contagem[jogadores[i].maestria]--;
  }
  
  // Copia o array de saída para jogadores[], para que agora contenha os jogadores ordenados por maestria
  for(i = 0; i < n; ++i) {
    jogadores[i] = saida[i];
  }
}

// Função para imprimir os jogadores
void imprimirJogador(struct Jogador jogadores[], int n) {
  for(int i = 0; i < n; i++) {
    printf("Nome: %s, maestria: %d, campeao[16]: %s\n", jogadores[i].nomeJogador, jogadores[i].maestria, jogadores[i].campeao);
  }
}

int main() {
  struct Jogador jogadores[TAMANHO_ARRAY] = {
    {"Romulo", 499000, 'Kayn'},
    {"Heitor", 380000, 'Yasuo'},
    {"Itor", 379999, 'Yasuo'},
    {"Lanna", 400000, 'Lulu'},
    {"Lavinia", 250000, 'Lulu'},
  };
  int n = 4;  // Atualizar com o número correto de jogadores
  
  printf("---------------\n");
  ordenarPormaestria(jogadores, n);
  imprimirJogador(jogadores, n);
  printf("---------------\n");
  return 0;
}
