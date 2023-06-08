#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *vectoralloc(const int n);
void values(int *, const int);
int inverter(int *, const int);
int main(void)
{
    srand(time(NULL));
    int *vector, n;
    //int* pointer;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    vector = vectoralloc(n);
    values(vector, n);
    inverter(vector, n);
    //n; remove the function above and place here;
    //pointer = &n;
    free(vector);
    return 0;
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
int inverter(int *array, const int n)
{
    int i, k, aux;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        k = rand() % n;
        aux = array[i];
        array[i] = array[k];
        array[k] = aux;
    }
    for (i = 0; i < n; i++)
        printf("[%d] O valor e: %d\n", i + 1, array[i]);
    //int *pointer;
    //pointer = array;
    //return *pointer;
    return 0;
}