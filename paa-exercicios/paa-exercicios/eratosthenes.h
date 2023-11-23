//
//  eratosthenes.h
//  paa-exercicios
//
//  Created by Rômulo Santana on 21/11/23.
//

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#ifndef eratosthenes_h
#define eratosthenes_h

#define MAX 1000

typedef int ITEM;

typedef struct {
    ITEM itens[MAX];
    int tamanho;
} LISTA;

void inicializar(LISTA *l);

bool inserir(ITEM item, LISTA *l);

void exibirItem(ITEM i);

void exibirLista(LISTA *l);

bool inserirNaPos(ITEM item, int posicao, LISTA *l);

LISTA sivoDeEratostenes(ITEM n);

#endif /* eratosthenes_h */
