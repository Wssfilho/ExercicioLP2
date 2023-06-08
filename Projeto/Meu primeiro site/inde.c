#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *vectoralloc(const int n);
void values(int *, const int);
void inverter(int *, int *, const int);
void arq(const int *const, const int);
int main(void)
{
    srand(time(NULL));
    int *vector, *newarray, n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    vector = vectoralloc(n);
    newarray = vectoralloc(n);
    values(vector, n);
    inverter(vector, newarray, n);
    arq(vector, n);
    free(newarray);
    free(vector);
    return 0;
}
void arq(const int *const vector, const int n)
{
    FILE *vectorarq;
    if ((vectorarq = fopen("vectorbd.txt", "w")) == NULL)
    {
        printf("WARNING: O arquivo nao foi aberto ou criado!");
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(vectorarq, "%d", vector[i]);
    }
    fclose(vectorarq);
}
int *vectoralloc(const int n)
{
    int *vector = (int *)malloc(n * sizeof(int));
    if (vector == NULL)
        exit(-1);
    return vector;
}
void values(int *vector, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Insira os valores do campo [%d]", i + 1);
        scanf("%d", &vector[i]);
    }
}
void inverter(int *array, int *swap, const int n)
{
    for (int num = 0; num < n; num++)
        swap[num] = array[num];
    
    int i, k, aux;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        k = rand() % n;
        aux = swap[i];
        swap[i] = swap[k];
        swap[k] = aux;
    }
    for (i = 0; i < n; i++)
        printf("[%d] O valor e: %d\n", i + 1, swap[i]);
}