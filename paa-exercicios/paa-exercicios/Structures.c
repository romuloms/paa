//
//  eratosthenes.c
//  paa-exercicios
//
//  Created by Rômulo Santana on 21/11/23.
//

#include "Structures.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


void inicializar(LISTA *l)
{
    l->tamanho = 0;
}

bool inserir(ITEM item, LISTA *l)
{
    if (l->tamanho == MAX)
        return false;
    else
        l->itens[l->tamanho++] = item;
    
    return true;
}

void exibirItem(ITEM i)
{
    printf("%d", i);
}

void exibirLista(LISTA *l)
{
    printf("[");
    
    for (int i = 0; i < l->tamanho;)
    {
        exibirItem(l->itens[i++]);
        if(i < l->tamanho)
            printf(",");
    }
    printf("]");
}

bool inserirNaPos(ITEM item, int posicao, LISTA *l)
{
    if ((l->tamanho >= MAX) || (posicao < 0) || (posicao > l->tamanho))
        return false;

    for (int j = l->tamanho; j > posicao; j--)
        l->itens[j] = l->itens[j-1];

    l->itens[posicao] = item;
    l->tamanho++;
    return true;
}


