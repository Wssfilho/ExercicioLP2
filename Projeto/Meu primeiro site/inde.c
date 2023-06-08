#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int *vectoralloc(const int n);
void values(int *, const int);
void inverter(const int *const, int *, const int);
void arq(const int *const, const int);
void menu(const int * const, const int * const, const int n);
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
    menu(vector, newarray, n);
    free(newarray);
    free(vector);
    return 0;
}
void arq(const int *const vector, const int n)
{
    FILE *vectorarq;
    if ((vectorarq = fopen("vectorbd.txt", "a+")) == NULL)
    {
        printf("WARNING: O arquivo nao foi aberto ou criado!");
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        fprintf(vectorarq, "%d", vector[i]);
    }
    fprintf(vectorarq, "\n");
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
void inverter(const int *const array, int *swap, const int n)
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
void menu(const int * const vector, const int * const newarray, const int n)
{
    int option;
    printf("Qual vetor vc quer colocar no arquivo? (0. Original) (1. trocado): ");
    scanf("%d", &option);
    while (option != 0 && option != 1)
    {
        printf("Escolha somente 0 ou 1");
        scanf("%d", &option);
    }
    if (option == 0)
        arq(vector, n);
    else
        arq(newarray, n);
    sleep(3);
    system("clear || cls");
    printf("Gravado!");
}