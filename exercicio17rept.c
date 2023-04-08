#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i, j;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = (int *) malloc(n * sizeof(int));
    printf("Digite os elementos do vetor: ");
    if(vetor == NULL){
        printf("MEMORIA NAO ALOCADA");
        exit(-1);
    }

    for (i = 0; i < n; i++)
    {
        printf("[%d] ", i + 1);
        scanf("%d", &vetor[i]);
    }
    for (i = 0; i < n; i++)
    {
        int cont = 1;

        for (j = i + 1; j < n; j++)
        {

            if (vetor[i] == vetor[j])
            {
                cont++;
                vetor[j] = -1;
            }
        }
        if (vetor[i] != -1 && cont > 1)
        {
            printf("%d se repete %d vezes\n", vetor[i], cont);
        }
    }

    free(vetor);
    return 0;
}