#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int i, j, linMatr, colMatr;
    float **A, **B;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &linMatr);
    printf("Digite o numero de coluna da matriz");
    scanf("%d", &colMatr);

    A = malloc(linMatr * sizeof(float *)); // porque e matriz float *
    B = malloc(linMatr * sizeof(float *));
    if ((A == NULL) || (B == NULL))
    {
        printf("Erro: Memoria insuficiente!!!\n");
        system("PAUSE");
        return -1;
    }
    for (i = 0; i < linMatr; i++)
    {
        A[i] = malloc(colMatr * sizeof(float));
    }
    for (i = 0; i < linMatr; i++)
    {
        B[i] = malloc(colMatr * sizeof(float));
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
            printf("digite o elemento [%d][%d] de B: ", i, j);
            scanf("%f", &B[i][j]);
        }
    }

    printf("A + B:\n");
    for (i = 0; i < linMatr; i++)
    {
        for (j = 0; j < colMatr; j++)
        {
            printf("%f ", A[i][j] + B[i][j]);
        }
        printf("\n");
    }

    printf("A - B:\n");
    for (i = 0; i < linMatr; i++)
    {
        for (j = 0; j < colMatr; j++)
        {
            printf("%f ", A[i][j] - B[i][j]);
        }
        printf("\n");
    }

    // limpeza da alocacao:
    for (i = 0; i < linMatr; i++)
    {
        free(A[i]);
    }
    free(A);
    for (i = 0; i < linMatr; i++)
    {
        free(B[i]);
    }
    free(B);

    return 0;
}