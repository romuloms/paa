//
//  main.c
//  paa-exercicios
//
//  Created by Rômulo Santana on 21/11/23.
//

#include <stdio.h>

#include "eratosthenes.h"


void imprimirStatus(LISTA *l)
{
    printf("Tamanho da lista = %d\n", l->tamanho);
    exibirLista(l);
    printf("\n");
}

void testSieve(void)
{
    printf("=> Teste do Sivo de Eratostenes\n");
    int n;
    printf("Digite o número que quer descobrir todos os primos até ele: ");
    scanf("%d", &n);
    
    LISTA lista = sivoDeEratostenes(n);
    
    imprimirStatus(&lista);
}

int main(void) {
//    LISTA l;
    testSieve();
    
    return 0;
}
