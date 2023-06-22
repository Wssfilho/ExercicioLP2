#include <stdio.h>
#include <stdlib.h>

// Escreva um programa que leia os elementos de um vetor de floats via teclado e escreva esses
// elementos em um arquivo de acesso aleatrio. A quantidade de elementos do vetor n tambm
// ser informada pelo usurio, coloque o valor de n na primeira linha do arquivo.

float *alloc(int);
void pedirn(int *n)
{
    printf("Insira a quantidade de elementos: ");
    scanf("%d", n);
}
void inserir(float *, const int);
void gravar(const float *const, const int n);
void mostrar();
int main(void)
{
    int n, op;
    float *vector;
    do
    {
        printf("1. Inserir\n");
        printf("2. Monstrar\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            pedirn(&n);
            vector = alloc(n);
            inserir(vector, n);
            gravar(vector, n);    
            break;
        case 2:
            mostrar();
            break;
        default:
            break;
        }

    } while (op != 3);

    free(vector);
    return 0;
}
void inserir(float *vector, const int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Insira os elementos: [%d]", i + 1);
        scanf("%f", &vector[i]);
    }
}
void mostrar()
{
    fflush(stdin);
    float media = 0.0;
    float *vector;
    int i, k;
    FILE *arq;
    if ((arq = fopen("vector.dat", "rb")) == NULL)
    {
        printf("Problemas na abertura do arquivo");
        exit(-1);
    }
    fread(&k, sizeof(int), 1, arq);
    vector = alloc(k);
    printf("O valor de n e: %d\n", k);
    fread(vector, sizeof(float), k, arq);
    printf("Os elementos gravados sao\n");
    for (i = 0; i < k; i++)
    {
        media += vector[i] / k;
        printf("[%d] %2.f\n", i + 1, vector[i]);
    }
    printf("a media e: %.2f\n\n", media);
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
float *alloc(int n)
{
    float *vectortemp;
    vectortemp = (float *)malloc(n * sizeof(float));
    if (vectortemp == NULL)
    {
        printf("Memoria nao alocada");
        exit(-1);
    }
    return vectortemp;
}