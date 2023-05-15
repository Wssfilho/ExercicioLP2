#include <stdlib.h>
#include <stdlib.h>
float **alocarr(const int llinha, const int ccoluna)
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
