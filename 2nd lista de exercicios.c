#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    float *vetor1 = NULL;
    int n, i, par, impar;

    printf("Insira o tamanho do vetor");
    scanf("%d", &n);
    float vetorPar[n], vetorImp[n];
    vetor1 = (float *)malloc(n * (sizeof(float)));
    if (vetor1 == NULL)
    {
        printf("MEMORIA NAO ALOCADA");
        exit(-1);
    }

    for (i = 0; i < n; i++)
    {
        printf("Insira os valores: ");
        scanf("%f", &vetor1[i]);
    }
    for (par = 0; par < n; par += 2)
    {
        vetorPar[par] = vetor1[par];
    }
    for (impar = 1; impar < n; impar += 2)
    {
        vetorImp[impar] = vetor1[impar];
    }
    for (i = 0; i < n; i += 2)
    {
        printf("Os valores pares sao: ");
        printf("{%.1f}\n", vetorPar[i]);
    }
    printf("\n");
    for (int contador = 1; contador < n; contador += 2)
    {
        printf("Os valores impar sao: ");
        printf("[%.1f]\n", vetorImp[contador]);
    }
    free(vetor1);

    return 0;
}