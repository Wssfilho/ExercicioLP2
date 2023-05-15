#include <stdio.h>
#include <stdlib.h>
#include "Alocar.h"
int main(void)
{
    float **A, **B, **som, **sub;
    int i, j, l, c, z;
    // leitura do numero de linhas e colunas
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &l);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &c);

    // alocacao dinamica de matrizes;
    A = alocarr(l, c);
    B = alocarr(l, c);
    som = alocarr(l, c);
    sub = alocarr(l, c);

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Digite o elemento [%d][%d] de A: ", i + 1, j + 1);
            scanf("%f", &A[i][j]);
            printf("Digite o elemento [%d][%d] de B: ", i + 1, j + 1);
            scanf("%f", &B[i][j]);
            som[i][j] = A[i][j] + B[i][j];
            sub[i][j] = A[i][j] - B[i][j];
        }
    }
    // resultados
    printf("\nSOMA\n");
    comparar(A, B, som, l, c, '+');
    printf("\nSubtracao\n");
    comparar(A, B, som, l, c, '-');
    // limpando memoria
    liberar(A, l);
    liberar(B, l);
    liberar(som, l);
    liberar(sub, l);

    return 0;
}
