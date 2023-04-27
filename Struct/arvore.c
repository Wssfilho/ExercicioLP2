
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILHOS 10

typedef struct pessoa
{
    char nome[20];
    struct pessoa *pai;
    struct pessoa *mae;
} Pessoa;

int main(void)
{
    int num_filhos;
    printf("INSIRA O NUMERO DE FILHOS: \n");
    scanf("%d", &num_filhos);
    fflush(stdin);
    Pessoa *filhos;
    filhos = malloc(num_filhos * sizeof(Pessoa));
    if (filhos == NULL)
    {
        printf("MEMORIA NAO ALOCADA\n");
        exit(-1);
    }
    for (int i = 0; i < num_filhos; i++)
    {

        printf("Insira o nome do filho %i: ", i + 1);
        gets(filhos[i].nome);
        Pessoa *pai;
        pai = malloc(sizeof(Pessoa));
        if (pai == NULL)
        {
            printf("MEMORIA NAO ALOCADA\n");
            exit(-1);
        }
        printf("Insira o nome do pai: ");
        gets(pai->nome);
        filhos[i].pai = pai;
        Pessoa *mae;
        mae = malloc(sizeof(Pessoa));
        if (mae == NULL)
        {
            printf("MEMORIA NAO ALOCADA\n");
            exit(-1);
        }
        printf("Insira o nome da mae: ");
        gets(mae->nome);
        filhos[i].mae = mae;
    }
    for (int i = 0; i < num_filhos; i++)
    {
        printf("\t\t\t-------Filho:%s -------\n", filhos[i].nome);
        printf("\t\t\tMae: %s -------- Pai: %s\n", filhos[i].mae->nome, filhos[i].pai->nome);
        printf("\n");
    }
    for (int i = 0; i < num_filhos; i++)
    {
        free(filhos[i].mae);
        free(filhos[i].pai);
    }
    free(filhos);
    return 0;
}