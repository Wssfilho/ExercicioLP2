#include <stdio.h>
#include <stdlib.h>

float **aloca_matriz(const int, const int);
void prn_oper(float **, float **, float **, const int, const int, const char);
void liberar_matriz(float **, const int);

int main(void)
{
    float **A, **B, **som, **sub;
    int i, j, m, n;

    // leitura do numero de linhas e colunas
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &m);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &n);

    // alocacao dinamica de matrizes;
    A = aloca_matriz(m, n);
    B = aloca_matriz(m, n);
    som = aloca_matriz(m, n);
    sub = aloca_matriz(m, n);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
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
    prn_oper(A, B, som, m, n, '+');
    printf("\nSubtracao\n");
    prn_oper(A, B, som, m, n, '-');
    // limpando memoria
    liberar_matriz(A, m);
    liberar_matriz(B, m);
    liberar_matriz(som, m);
    liberar_matriz(sub, m);

    return 0;
}
float **aloca_matriz(const int l, const int c)
{
    float **m;
    int i;

    m = (float **)malloc(l * sizeof(float *));
    if (m == NULL)
    {
        printf("ERRO, estouro de memoria");
        exit(-1);
    }
    for (i = 0; i < l; i++)
    {
        m[i] = (float *)malloc(c * sizeof(float));
        if (m[i] == NULL)
        {
            printf("Error, estouro de momoria!\n");
            exit(-1);
        }
    }
    return m;
}
void liberar_matriz(float **m, const int l)
{
    int i;
    for (i = 0; i < l; i++)
        free(m[i]);
    free(m);
}
void prn_oper(float **m1, float **m2, float **m3,
              const int l, const int c, const char oper)
{
    int i, j;

    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
            printf("%4.2f ", m1[i][j]);
        if (i == (l / 2))
            printf(" %c ", oper);
        else
            printf(" ");
        for (j = 0; j < c; j++)
            printf("%4.2f ", m2[i][j]);
        if (i == (l / 2))
            printf(" = ");
        else
            printf(" ");
        for (j = 0; j < c; j++)
            printf("%4.2f ", m3[i][j]);
        printf("\n");
    }
}