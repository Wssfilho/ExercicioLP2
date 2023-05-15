#include <stdio.h>
#include <stdlib.h>

int *aloc_vet(const int); //funcao para alocar um vetor
void libera_vet(const int *v)
{
    free(v);
}
int main(void)
{
    int *v, n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    v = aloc_vet(n);
    libera_vet(v);
    return 0;
}
int *aloc_vet(const int n)
{
    int *v;
    v = (int *)malloc(n * sizeof(int));
    if (v == NULL)
    {
        printf("Erro, estouro");
        exit(-1);
    }
    return v;
}