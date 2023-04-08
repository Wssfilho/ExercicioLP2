#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    float *p1, *p2, *ps;
    ps = malloc(sizeof(float));
    if (ps == NULL)
    {
        printf("MEMORIA NAO ALOCADA");
        exit(-1);
    }
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    float *vetor = (float *)malloc(n * sizeof(float));
    printf("Digite os elementos do vetor: ");
    if (vetor == NULL)
    {
        printf("MEMORIA NAO ALOCADA");
        exit(-1);
    }
    for (i = 0; i < n; i++)
    {
        printf("[%d] ", i + 1);
        scanf("%f", &vetor[i]);
        p1 = vetor;
        p2 = vetor + 1;
    }
    while (p2 < &vetor[n])
    {
        *ps = *p2;
        *p2 = *p1;
        *p1 = *ps;
        p1 = p1 + 2;
        p2 = p2 + 2;
    }
    for (i = 0; i < n; i++)
    {
        printf("[%f] ", vetor[i]);
    }

    free(vetor);
    free(ps);

    return 0;
}