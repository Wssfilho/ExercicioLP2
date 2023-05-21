#include <stdio.h>
#include <stdlib.h>
int *alocarvetor(const int n)
{
    int *v;
    v = (int *)malloc(n * sizeof(int));
    if(v == NULL){
        printf("A memoria nao foi alocada");
    }
    return v;
}
int main(void)
{
    int n, i, j;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor; 
    vetor = alocarvetor(n);

    printf("Digite os elementos do vetor: ");

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
        else
            printf("Nao se repete");
    }

    free(vetor);
    return 0;
}