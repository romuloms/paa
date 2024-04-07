#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANDAR 10000

void countingSortDesc(int andares[], int qntPessoas) {
  int contagem[MAX_ANDAR + 1] = {0};
  int i;

  for(i = 0; i < qntPessoas; i++) {
    contagem[andares[i]]++;
  }

  int pos = 0; 
  for(i = MAX_ANDAR; i >= 0; i--) {
    while(contagem[i] > 0) {
      andares[pos++] = i;
      contagem[i]--;
    }
  }
}

void elevador(int andares[], int qntPessoas, int capacidade) {
  countingSortDesc(andares, qntPessoas);

  int totalEnergia = 0;

  for (int i = 0; i < qntPessoas; i += capacidade) {
    int energiaDessaViagem = 2 * andares[i];
    totalEnergia += energiaDessaViagem;
  }
  printf("%d\n", totalEnergia);
}

int main() {
  int N, C, M, T;

  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    scanf("%d %d %d", &N, &C, &M);

    int* andares = (int*)malloc(M * sizeof(int));
    for (int j = 0; j < M; j++) {
      scanf("%d", &andares[j]);
    }

    elevador(andares, M, C);
    free(andares);
  }

  return 0;
}
