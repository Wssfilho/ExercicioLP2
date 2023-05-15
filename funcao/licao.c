#include <stdio.h>
#include <stdlib.h>
float **alocar(const int, const int);
void comparar(float **, float **, float **, const int, const int, const char);
void liberar(float **, const int);
int main(void)
{
    float **A, **B, **som, **sub;
    int i, j, l, c;
    // leitura do numero de linhas e colunas
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &l);
    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &c);

    // alocacao dinamica de matrizes;
    A = alocar(l, c);
    B = alocar(l, c);
    som = alocar(l, c);
    sub = alocar(l, c);

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
float **alocar(const int llinha, const int ccoluna)
{
    float **m;
    int i;

    m = (float **)malloc(llinha * sizeof(float *));
    if (m == NULL)
    {
        printf("ERRO, estouro de memoria");
        exit(-1);
    }
    for (i = 0; i < llinha; i++)
    {
        m[i] = (float *)malloc(ccoluna * sizeof(float));
        if (m[i] == NULL)
        {
            printf("Error, estouro de momoria!\n");
            exit(-1);
        }
    }
    return m;
}
void liberar(float **m, const int l)
{
    int i;
    for (i = 0; i < l; i++)
        free(m[i]);
    free(m);
}
void comparar(float **m1, float **m2, float **m3, const int l, const int c, const char oper)
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