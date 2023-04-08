#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    printf("Insira a dimensão da matriz quadrada: Linha = Coluna:  ");
    scanf("%d", &n); // pede o tamanho da matriz sendo ela quadrada, como é quadrada, usei a mesma variavel para a coluna e linha

    float **matriz;
    matriz = (float **)malloc(n * sizeof(float *)); // alocacao dinamica para matriz
    if (matriz == NULL)
    {
        printf("MEMORIA NAO ALOCADA"); // verifica a alocacao
        exit(-1);
    }
    for (i = 0; i < n; i++)
    {
        matriz[i] = malloc(n * sizeof(float)); // faz alocacao das colunas da matriz
        if (matriz[i] == NULL)
        {
            printf("MEMORIA NAO ALOCADA, SAINDO"); // verifica se as colunas foram alocadas corretamente
            exit(-1);
        }
    }

    printf("Insira os elementos da matriz:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("DIGITE O ELEMENTO [%d][%d]", i + 1, j + 1);
            scanf("%f", &matriz[i][j]); // preencher os elemetos
        }
    }

    float maior1 = matriz[0][0];
    float maior2 = matriz[0][0];
    int negativos = 0; // declaracao de variaveis
    float produto = 1.0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matriz[i][j] > maior1)
            {
                maior2 = maior1; // verifica o maior
                maior1 = matriz[i][j];
            }
            else if (matriz[i][j] > maior2)
            {
                maior2 = matriz[i][j]; // verifica o maior 2
            }

            if (matriz[i][j] < 0)
            {
                negativos++; // conta os numeros negativos
            }

            produto *= matriz[i][j]; // faz a multiplocacao
        }
    }

    printf("Os dois maiores elementos da matriz sao: %.1f e %.1f\n", maior1, maior2);
    printf("A quantidade de elementos negativos e: %d\n", negativos); // impressao dos resultados
    printf("O produto de todos os elementos da matriz e: %.2f\n", produto);

    for (i = 0; i < n; i++)
    {
        free(matriz[i]); // limpeza de memoria
    }
    free(matriz);

    return 0;
}
