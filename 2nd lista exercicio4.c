#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n;
    printf("insira o tamanho do vetor");
    scanf("%d", &n);
    float vetor[n];
    float *ptrv;
    ptrv = vetor;

    for (i = 0; i < n; i++)
    {
        printf("insira os elementos do votor");
        scanf("%f", &vetor[i]);
    }
    for (int j = 0; j < n; j += 2)
    {
        printf("[%.2f]", *(ptrv + j));

    }
    return 0;
}