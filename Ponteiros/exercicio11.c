#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    printf("Insira a dimensão da matriz quadrada: ");
    scanf("%d", &n);

    float **matriz = malloc(n * sizeof(float *));
    if (matriz == NULL)
    {
        printf("MEMORIA NAO ALOCADA");
        exit(-1);
    }
    for (i = 0; i < n; i++)
    {
        matriz[i] = malloc(n * sizeof(float));
        if (matriz[i] == NULL)
        {
            printf("MEMORIA NAO ALOCADA, SAINDO");
            exit(-1);
        }
    }

    printf("Insira os elementos da matriz:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("DIGITE O ELEMENTO [%d][%d]", i + 1, j + 1);
            scanf("%f", &matriz[i][j]);
        }
    }

    float maior1 = matriz[0][0];
    float maior2 = matriz[0][0];
    int negativos = 0;
    float produto = 1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matriz[i][j] > maior1)
            {
                maior2 = maior1;
                maior1 = matriz[i][j];
            }
            else if (matriz[i][j] > maior2)
            {
                maior2 = matriz[i][j];
            }

            if (matriz[i][j] < 0)
            {
                negativos++;
            }

            produto *= matriz[i][j];
        }
    }

    printf("Os dois maiores elementos da matriz sao: %.1f e %.1f\n", maior1, maior2);
    printf("A quantidade de elementos negativos e: %d\n", negativos);
    printf("O produto de todos os elementos da matriz e: %.2f\n", produto);

    for (i = 0; i < n; i++)
    {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
