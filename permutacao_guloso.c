#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct nos
{
  int item;
  struct nos *anterior;
  struct nos *proximo;
} NO;

typedef struct
{
  NO* cabeca;
  NO* cauda;
  int tamanho;
} LISTA_DUP_ENCADEADA;

char compara(int x, int y)
{
  return x > y ? 1 : (x < y ? -1 : 0);
}

bool igual(int x, int y)
{
  return compara(x,y) == 0;
}

void inicializar(LISTA_DUP_ENCADEADA *l)
{
  l->cabeca = NULL;
  l->cauda = NULL;
  l->tamanho = 0;
}

NO* criarNo(int item, NO* anterior, NO* proximo)
{
  NO* novo = (NO*)malloc(sizeof(NO));

  novo->item = item;
  novo->anterior = anterior;
  novo->proximo = proximo;

  return novo;
}

bool inserir(int item, LISTA_DUP_ENCADEADA *l)
{
  if (l->cabeca == NULL)
  {
    l->cabeca = criarNo(item, NULL, NULL);
    l->cauda = l->cabeca;
    l->tamanho++;

    return true;
  }
  l->cabeca = criarNo(item, NULL, l->cabeca);
  l->tamanho++;

  return true;
}

bool inserirNoFim(int item, LISTA_DUP_ENCADEADA *l)
{
  if (l->cabeca == NULL)
  {
    l->cabeca = criarNo(item, NULL, NULL);
    l->cauda = l->cabeca;
    l->tamanho++;

    return true;
  }

  NO* novo = criarNo(item, l->cauda, NULL);
  l->cauda->proximo = novo;
  l->cauda = novo;
  l->tamanho++;

  return true;
}

bool insercaoOrdenada(int item, LISTA_DUP_ENCADEADA *l)
{
  NO* p = l->cabeca;
  NO* aux = NULL;
  NO* novo = criarNo(item, NULL, NULL);

  if (l->cabeca == NULL)
  {
    l->cabeca = novo;
    l->cauda = l->cabeca;
    l->tamanho++;

    return true;
  }
  else
  {
    while (p != NULL)
    {
      if (item < p->item)
      {
        if (aux == NULL)
        {
          novo->proximo = p;
          p->anterior = novo;
          l->cabeca = novo;
        } else
        {
          novo->proximo = p;
          p->anterior = novo;
          aux->proximo = novo;
        }
        l->tamanho++;
        return true;
      }
      else if (p->proximo == NULL)
      {
        novo->anterior = p;
        p->proximo = novo;
        l->cauda = novo;
        l->tamanho++;
        return true;
      }
      aux = p;
      p = p->proximo;
    }
  }

    return false;
}

bool removerCabeca(LISTA_DUP_ENCADEADA *l)
{
  if (l->cabeca != NULL)
  {
    NO* aux = l->cabeca;
    l->cabeca = l->cabeca->proximo;
    free(aux);
    l->tamanho--;

    return true;
  }

  return false;
}

bool removerCauda(LISTA_DUP_ENCADEADA *l)
{
  if (l->cauda != NULL)
  {
    NO* aux = l->cauda;
    l->cauda = l->cauda->anterior;
    free(aux);
    l->tamanho--;

    return true;
  }
  
  return false;
}

void limpar(LISTA_DUP_ENCADEADA *l)
{
  NO* atual = l->cabeca;
  while (atual)
  {
    NO* prox = atual->proximo;
    atual = prox;
    free(atual);
  }
  l->cabeca = NULL;
  l->tamanho = 0;
}

void imprimirLista(LISTA_DUP_ENCADEADA *l)
{
  if (l->cabeca != NULL)
  {
    printf("[");
    NO* p = l->cabeca;

    while (p != NULL)
    {
      printf("%d", p->item);
      if (p->proximo != NULL)
        printf(" ");
      p = p->proximo;
    }
    printf("]\n");
  }
}

int maximoArr(int* vetor)
{
  int max = vetor[0];

  for (int i = 0; i < 4; i++)
  {
    if (vetor[i] > max)
      max = vetor[i];
  }

  return max;
}

int main(void)
{
  LISTA_DUP_ENCADEADA entrada, auxiliar;
  inicializar(&entrada);
  inicializar(&auxiliar);

  int numeroTestes;
  scanf("%d", &numeroTestes);

  for (int i = 0; i < numeroTestes; i++)
  {
    int numItens, soma;
    scanf("%d", &numItens);
    
    for (int j = 0; j < numItens; j++)
    {
      int item;
      scanf("%d", &item);
      insercaoOrdenada(item, &entrada);
    }

    inserir(entrada.cabeca->item, &auxiliar);
    inserirNoFim(entrada.cauda->item, &auxiliar);

    soma = abs(auxiliar.cauda->item - auxiliar.cabeca->item);
    
    removerCauda(&entrada);
    removerCabeca(&entrada);

    printf("soma: %d\n", soma);
    while (entrada.tamanho >= 0)
    {
      imprimirLista(&entrada);
      int arr[4];

      arr[0] = abs(auxiliar.cabeca->item - entrada.cabeca->item);
      arr[1] = abs(auxiliar.cauda->item - entrada.cabeca->item);
      arr[2] = abs(auxiliar.cabeca->item - entrada.cauda->item);
      arr[3] = abs(auxiliar.cauda->item - entrada.cauda->item);
      
      int maximo = maximoArr(arr);
      if (maximo == 4)
      {
        printf("aux cabeca: %d entrada cabeca: %d\n", auxiliar.cabeca->item, entrada.cabeca->item);
      }
      //
      if (maximo == arr[0])
      {
        inserir(entrada.cabeca->item, &auxiliar);
        removerCabeca(&entrada);
      } 
      if (maximo == arr[1])
      {
        inserirNoFim(entrada.cabeca->item, &auxiliar);
        removerCabeca(&entrada);
      }
      if (maximo == arr[2])
      {
        inserir(entrada.cauda->item, &auxiliar);
        removerCauda(&entrada);
      }
      else
      {
        inserirNoFim(entrada.cauda->item, &auxiliar);
        removerCauda(&entrada);
      }

      soma += maximo;
      printf("soma: %d maximo: %d\n", soma, maximo);
    }

    printf("Case %d: %d\n", i+1, soma);
    if (entrada.tamanho == 0)
      break;
  }

  limpar(&entrada);

  return 0;
}