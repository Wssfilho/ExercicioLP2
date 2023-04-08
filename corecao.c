#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("tamanho do vetor");
    int n;
    int vetor[n];
    scanf("%d", &vetor[n]);
    for (int i = 0; i < n; i++)
    {
        printf("insira um valor");
        scanf("%d", &vetor[i]);
    }
    for(int j = 0; j < n; j++){
        printf("%d", vetor[j]);
    }
}