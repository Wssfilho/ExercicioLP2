#include <stdio.h>
#include <stdlib.h>

// Escreva um programa que leia os elementos de um vetor de floats via teclado e escreva esses
// elementos em um arquivo de acesso aleatrio. A quantidade de elementos do vetor n tambm
// ser informada pelo usurio, coloque o valor de n na primeira linha do arquivo.

float *allocinsere(int *);
void gravar(const float *const, const int n);
void mostrar(float *, int);
int main(void)
{
    int n;
    float *vector;
    vector = allocinsere(&n);
    gravar(vector, n);
    mostrar(vector, n);
    free(vector);
    return 0;
}
void mostrar(float *vector, int n)
{
    float media = 0.0;
    int i, k;
    FILE *arq;
    if ((arq = fopen("vector.dat", "rb")) == NULL)
    {
        printf("Problemas na abertura do arquivo");
        exit(-1);
    }
    fread(&k, sizeof(int), 1, arq);
    printf("O valor de n e: %d\n", k);
    fread(vector, sizeof(float), n, arq);
    for (i = 0; i < k; i++)
    {
        media += vector[i] / k;
    }
    printf("a media e: %.2f", media);
}
void gravar(const float *const vector, const int n)
{
    FILE *arq;
    if ((arq = fopen("vector.dat", "wb")) == NULL)
    {
        printf("O arquivo nao foi aberto, verifique!");
        exit(-1);
    }
    fwrite(&n, sizeof(int), 1, arq);
    fwrite(vector, sizeof(float), n, arq);
    printf("Arquivo gravado com sucesso\n\n");
    fclose(arq);
}
float *allocinsere(int *n)
{
    printf("Insira a quantidade de elementos: ");
    scanf("%d", n);
    float *vectortemp;
    vectortemp = (float *)malloc(*n * sizeof(float));
    if (vectortemp == NULL)
    {
        printf("Memoria nao alocada");
        exit(-1);
    }
    for (int i = 0; i < *n; i++)
    {
        printf("Insira os elementos do vetor na posicao %d: ", i + 1);
        scanf("%f", &vectortemp[i]);
    }
    return vectortemp;
}