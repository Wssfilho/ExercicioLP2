#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    printf("Digite o número de linhas das matrizes: ");
    scanf("%d", &m);
    printf("Digite o número de colunas das matrizes: ");
    scanf("%d", &n);

    int **A = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        A[i] = (int *)malloc(n * sizeof(int));
    }
    
    int **B = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        B[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    printf("A + B:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j] + B[i][j]);
        }
        printf("\n");
    }

    printf("A - B:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j] - B[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        free(A[i]);
        free(B[i]);
    }
    free(A);
    free(B);

    return 0;
}