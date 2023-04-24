#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, j, troca = 1, temp;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = (int *)malloc(n * sizeof(int));
    printf("Digite os elementos do vetor: ");
    if (vetor == NULL)
    {
        printf("MEMORIA NAO ALOCADA");
        exit(-1);
    }
    for (i = 0; i < n; i++)
    {
        printf("[%d] ", i + 1);
        scanf("%d", &vetor[i]);
    }
    for (i = 0; i < n && troca; i++)
    {
        troca = 0;
        for (j = i + 1; j < n; j++)
        {
            if (vetor[i] > vetor[j])
            {
                temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
                troca = 1;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        j = 0;
        while (vetor[i] == vetor[i + 1])
        {
            j++;
            i++;
        }
        if (j == 0)
        {
            printf("%d nao se repete", vetor[i]);
        }
        if (j != 0)
        {
            printf("%d se repete %d", vetor[i], j + 1);
        }
    }

    return 0;
}