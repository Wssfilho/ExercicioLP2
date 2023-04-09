
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *vetor;
    int *maior, *menor;
    float media = 0;

    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &n);

    vetor = malloc(n * sizeof(int));
    if(vetor == NULL){
        printf("MEMORIA NAO ALOCADA");
        exit(-1);
    }

    for (i = 0; i < n; i++)
    {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
        media += vetor[i];
    }
    
    media /= n;
    maior = menor = &vetor[0];

    for (i = 1; i < n; i++)
    {
        if (*maior < vetor[i])
            maior = &vetor[i];
        if (*menor > vetor[i])
            menor = &vetor[i];
    }

    printf("Média dos elementos do vetor: %.2f\n", media);
    printf("Maior elemento do vetor: %d\n", *maior);
    printf("Menor elemento do vetor: %d\n", *menor);

    free(vetor);

    return 0;
}
