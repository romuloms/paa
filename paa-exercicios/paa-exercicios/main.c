//
//  main.c
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

#include "Structures.h"


void imprimirStatus(LISTA *l)
{
    printf("Tamanho da lista = %d\n", l->tamanho);
    exibirLista(l);
    printf("\n");
}

LISTA sivoDeEratostenes(ITEM n)
{
    LISTA l, resultL;
    inicializar(&l);
    inicializar(&resultL);
    
    double raiz = sqrt(n);
    int raizInt = floor(raiz);
    
    for (int p = 0; p <= n; p++)
        inserir(p, &l);
    
    for (int q = 2; q <= raizInt; q++)
    {
        if(l.itens[q] != 0)
        {
            int j = q * q;
            
            while (j <= n)
            {
                l.itens[j] = 0;
                j = j + q;
            }
        }
    }
    
    int i = 0;
    
    for (int r = 2; r <= n; r++)
    {
        if (l.itens[r] != 0)
        {
            resultL.itens[i] = l.itens[r];
            resultL.tamanho++;
            i = i + 1;
        }
    }
    
    return resultL;
}

void testeSieve(void)
{
    printf("=> Teste do Sivo de Eratostenes\n");
    int n;
    printf("Digite o número que quer descobrir todos os primos até ele: ");
    scanf("%d", &n);
    
    LISTA lista = sivoDeEratostenes(n);
    
    imprimirStatus(&lista);
}

char* calcularDigito(char *chave)
{
    int cont = 0, valAux = 0;
    bool resultado = false;
    
    if (strcmp(chave, "FIM") == 0)
        return "";

    for (int i = 0; chave[i] != '\0' ; i++)
    {
        if (chave[i] == '-')
        {
            cont += valAux;
            int ultimo = chave[++i] - '0';
            resultado = (cont % 10) == ultimo;
            break;
        }
        if (chave[i] != '.') 
        {
            int valInt = chave[i] - '0';
            if (valAux < valInt)
                valAux = valInt;
        }
        if (chave[i] == '.')
        {
            cont += valAux;
            valAux = 0;
        }
    }
    return resultado ? "VALIDO\n" : "INVALIDO\n";
}

void testeCalcularDigito(void)
{
    printf("=> Teste de Calcurar o digito do cpf\n");
    
    char chave[20];
    char* res = (char*)malloc(20 * sizeof(char));
    
    while (1)
    {
        if (strcmp(chave, "FIM") == 0)
            break;
        printf("digite uma entrada ou FIM para parar: \n");
        scanf("%s", chave);
        res = calcularDigito(chave);
        printf("%s", res);
    }
}

bool elementosUnicos(int* vetor, int tamanho)
{
    for (int i = 0; i <= tamanho - 2; i++)
    {
        for (int j = i + 1; j <= tamanho - 1; j++)
        {
            if (vetor[i] == vetor[j])
                return false;
        }
    }
    return true;
}

int valorMaximo(int* vetor, int tamanho)
{
    int maximo = vetor[0];
    
    for (int i = 1; i <= tamanho - 1; i++)
        if (vetor[i] > maximo)
            maximo = vetor[i];
    
    return maximo;
}

int** criaMatriz(void)
{
    int** matriz;
    int linhas, colunas, i, j;
    
    printf("Numero de linhas: ");
    scanf("%d", &linhas);
    printf("Numero de colunas: ");
    scanf("%d", &colunas);
    
    matriz = (int**) malloc(linhas * sizeof(int*));
    
    if (matriz == NULL)
    {
        printf("Falha de alocacao de memoria p/ linhas.");
        return 0;
    }
    
    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL)
        {
            printf("Falha de alocao de memoria p/ colunas.");
            return 0;
        }
    }
    
    printf("Elementos da matriz:\n");
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    
    return matriz;
}

int** multiplicacaoMatrizes(int** matA, int** matB, int dimensao)
{
    int** matC = (int**) malloc(dimensao * sizeof(int*));
    for (int z = 0; z < dimensao; z++)
        matC[z] = (int*) malloc(dimensao * sizeof(int));
    
    for (int i = 0; i <= dimensao - 1; i++)
    {
        for (int j = 0; j <= dimensao - 1; j++)
        {
            matC[i][j] = 0;
            for (int k = 0; k <= dimensao - 1; k++)
                matC[i][j] = matC[i][j] + (matA[i][k] * matB[k][j]);
        }
    }
    
    return matC;
}

void printMatrizQuadrada(int** matriz, int dimensao)
{
    for (int i = 0; i < dimensao; i++)
    {
        for (int j = 0; j < dimensao; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

int main(void) {
//    LISTA l;
//    testeSieve();
//    testeCalcularDigito();
//    int vetorUnicos[] = {11, 23, 39, 41, 15, 4};;
//    bool unico = elementosUnicos(vetorUnicos, 6);
//    printf("%s\n", unico ? "verdade" : "falso");
//    int max = valorMaximo(vetorUnicos, 6);
//    printf("%d\n", max);
    int** matrizA = criaMatriz();
    int** matrizB = criaMatriz();
    int** mult = multiplicacaoMatrizes(matrizA, matrizB, 3);
    
    printMatrizQuadrada(mult, 3);
    free(matrizA);
    free(matrizB);
    free(mult);
    
    return 0;
}
