/*Escreva um programa que receba como entrada duas matrizes e imprima na tela o produto delas. Seu programa deve funcionar para matrizes de quaisquer dimensão com alocação dinamica e ponteiros.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int linMatr, colMatr, i, j, k;
    float **A, **B, **C;

    printf("Digite o numero de linhas das matrizes: ");
    scanf("%d", &linMatr);
    printf("Digite o numero de colunas das matrizes: ");
    scanf("%d", &colMatr);

    A = (float **)malloc(linMatr * sizeof(float *));
    B = (float **)malloc(linMatr * sizeof(float *));
    C = (float **)malloc(linMatr * sizeof(float *));
    if ((A == NULL) || (B == NULL) || (C == NULL))
    {
        printf("Erro: Memoria insuficiente!!!\n");
        system("PAUSE");
        return -1;
    }
    for (i = 0; i < linMatr; i++)
    {
        A[i] = malloc(colMatr * sizeof(float));
        B[i] = malloc(colMatr * sizeof(float));
        C[i] = malloc(colMatr * sizeof(float));
    }

    for (i = 0; i < linMatr; i++)
    {
        for (j = 0; j < colMatr; j++)
        {
            printf("Digite o elemento [%d][%d] de A: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    for (i = 0; i < linMatr; i++)
    {
        for (j = 0; j < colMatr; j++)
        {
            printf("Digite o elemento [%d][%d] de B: ", i, j);
            scanf("%f", &B[i][j]);
        }
    }

    printf("A * B:\n");
    for (i = 0; i < linMatr; i++)
    {
        for (j = 0; j < colMatr; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < colMatr; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }

    // limpeza da alocacao:
    for (i = 0; i < linMatr; i++)
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
