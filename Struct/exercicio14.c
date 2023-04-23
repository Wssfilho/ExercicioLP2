#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item
{
    char nome[255];
    char telefone[13];
    struct item *ptr;
} Titem;

int main()
{
    Titem *raiz = NULL, *ultimo;
    char nome[255], telefone[13];

    printf("Entrada de Dados\n");
    printf("Digite o nome (0 para finalizar): ");
    fgets(nome, 255, stdin);
    nome[strcspn(nome, "\n")] = 0; //porque estou usando fgets

    while (nome[0] != '0')
    {
        if (raiz == NULL)
        {
            raiz = malloc(sizeof(Titem));
            ultimo = raiz;
        }
        else
        {
            ultimo->ptr = malloc(sizeof(Titem));
            ultimo = ultimo->ptr;
        }
        if (ultimo == NULL)
        {
            printf("Erro: Memoria insuficiente.\n");
            return -1;
        }
        ultimo->ptr = NULL;
        strcpy(ultimo->nome, nome);
        printf("Digite o telefone: ");
        fgets(telefone, 13, stdin);
        telefone[strcspn(telefone, "\n")] = 0;
        strcpy(ultimo->telefone, telefone);
        printf("Digite o nome (0 para finalizar): ");
        fgets(nome, 255, stdin);
        nome[strcspn(nome, "\n")] = 0;
    }

    if (raiz != NULL)
    {
        printf("\nSaida de dados\n");
        while (raiz != NULL)
        {
            ultimo = raiz;
            printf("Nome: %s Telefone: %s\n", ultimo->nome, ultimo->telefone);
            raiz = ultimo->ptr;
            free(ultimo);
        }
    }

    return 0;
}