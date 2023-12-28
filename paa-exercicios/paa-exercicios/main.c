//
//  main.c
//  paa-exercicios
//
//  Created by Rômulo Santana on 21/11/23.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#include "Structures.h"

#define MAX(a,b) ((a) > (b) ? (a) : (b))

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

int** criaMatrizQuadrada(int ordem)
{
    int** matriz;
    int i, j;
    int linhas = ordem;
    int colunas = ordem;
    
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
            scanf("%d", &matriz[i][j]);
        }
    }
    
    return matriz;
}

int* vetorRandom(int n, bool muda)
{
    int* vetor = (int*) malloc(n * sizeof(int));
    
    if (muda)
        srand(time(NULL));
    
    for (int i = 0; i < n; i++)
    {
        int randN = rand()%100;
        vetor[i] = randN;
    }
    
    return vetor;
}

int** matriz1e0(int n, bool muda)
{
    int** mat = (int**) malloc (n * sizeof(int*));

    for (int i = 0; i < n; i++)
        mat[i] = (int*) malloc (n * sizeof(int));

    if (muda)
        srand(time(NULL));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int randN = rand()%2;
            mat[i][j] = randN;
            
            if (i == j)
                mat[i][j] = 1;
        }
    }


    return mat;
}

void liberaVetor(int n, int* vetor)
{
    free(vetor);
}

void liberaMatriz(int n, int** m) 
{
    for (int i = 0; i < n; i++)
        free(m[i]);
    free(m);
}

int celebridade(int** matriz, int dimensao)
{
    int celeb = -1;
    
    for (int i = 0; i < dimensao; i++)
    {
        int conheceAlguem = 0;
        int todosConhecem = 1;
        
        for (int j = 0; j < dimensao; j++)
        {
            if (i != j)
            {
                if (matriz[i][j] == 1)
                    conheceAlguem = 1;
                else if (matriz[j][i] == 0)
                    todosConhecem = 0;
            }
        }
        
        if (!conheceAlguem && todosConhecem)
        {
            celeb = i;
            break;
        }
    }
    return celeb;
}

int celebridadeLinear(int n, int** conhece)
{
    int candidato = 0;
  
    for (int i = 1; i < n; i++)
    {
         if (conhece[candidato][i] == 1)
              candidato = i;
    }
  
    for (int j = 0; j < n; j++)
    {
         if (j != candidato && (conhece[candidato][j] != 0 || conhece[j][candidato] == 0))
              return -1;
    }

    return candidato;
}

void imprimeMatriz(int linhas, int colunas, int** matriz)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

void imprimeVetor(int n, int* vetor)
{
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

int* insertionSort(int n, int* vetor)
{
    printf("---insertion\n");

    int v, j;
    
    for (int i = 1; i < n; i++)
    {
        v = vetor[i];
        j = i - 1;
        
        while (j >= 0 && vetor[j] > v)
        {
            vetor[j+1] = vetor[j];
            j = j - 1;
        }
        vetor[j+1] = v;
    }
    
    return vetor;
}

int* selectionSort(int n, int* vetor)
{
    int min, aux;
    
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (vetor[j] < vetor[min])
                min = j;
        aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux;
    }
    
    return vetor;
}

int* bubbleSort(int n, int* vetor)
{
    int aux;
    
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (vetor[j+1] < vetor[j])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
    
    return vetor;
}

int buscaSequencial(int k, int n, int* vetor)
{
    int i = 0;
    
    while (vetor[i] != k)
        i = i + 1;
    if (i < n)
        return i;
    else
        return -1;
}

int** lePontos(int n)
{
    int** matriz = (int**) malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++)
        matriz[i] = (int*) malloc(2 * sizeof(int));
    
    for (int j = 0; j < n; j++)
        for (int k = 0; k < 2; k++)
            scanf("%d", &matriz[j][k]);
    
    return matriz;
}

int quadradoDistancia(int x1, int x2, int y1, int y2)
{
    int dQuadrado, subXq, subYq;
    
    subXq = pow((x1 - x2), 2);
    subYq = pow((y1 - y2), 2);
    dQuadrado = subXq + subYq;
    
    return dQuadrado;
}

void menorDistancia(int nPontos, int** pontos)
{
    float mDistancia = INT_MAX;
    float distanciaAux;
    int aux = 0;
    int* ptAtual = (int*) malloc(2 * sizeof(int));
    
    ptAtual = pontos[0];
    
    for (int i = 1; i < nPontos; i++)
    {
        distanciaAux = quadradoDistancia(ptAtual[0], pontos[i][0], ptAtual[1], pontos[i][1]);
        
        if (mDistancia > distanciaAux)
            mDistancia = distanciaAux;
        if ((i == nPontos - 1) && (aux < nPontos - 1))
        {
            i = aux + 1;
            ptAtual = pontos[aux + 1];
            aux++;
        }
    }
    
    mDistancia = sqrtf(mDistancia);
    
    printf("%.4f\n", mDistancia);
}

int busca(int k, int n, int** matriz)
{
    int j = n - 1;
    int z = 0;
    int alvo = matriz[z][j];
    
    for (int i = 0; i < n*2; i++)
    {
        if (alvo == k)
            return k;
        else if (alvo < k)
        {
            z++;
            if (z == n)
                break;
            alvo = matriz[z][j];
        }
        else if (alvo > k)
        {
            j--;
            if (j < 0)
                break;
            alvo = matriz[z][j];
        }
    }
    
    return 0;
}


int main(void) {
//    LISTA l;
//    int vetorUnicos[] = {11, 23, 39, 41, 15, 4};
//    int** matBusca = criaMatrizQuadrada(4);
//    imprimeMatriz(4, 4, matBusca);
//    int result = busca(-22, 4, matBusca);
//    printf("resultado da busca: %d\n", result);
//    liberaMatriz(4, matBusca);
//    int** mat = matriz1e0(5);
//    liberaMatriz(5, mat);
//    int* vet = vetorRandom(8, false);
//    imprimeVetor(8, vet);
//    int num = buscaSequencial(78, 8, vet);
//    printf("%d\n", num);
//    liberaVetor(8, vet);
//    int** pontos = lePontos(5);
//    imprimeMatriz(4, 2, pontos);
//    liberaMatriz(5, pontos);

    return 0;
}
