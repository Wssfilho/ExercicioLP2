#include <stdio.h>
#include <stdlib.h>

typedef struct carro
{
    char nome[10];
    float tempo;
    struct carro *proximo;
} Tcarro;

int main()
{
    Tcarro *raiz = NULL, *ultimo;
    char nome[10];

    printf("Entrada de Dados\n");
    printf("Digite o nome da equipe (0 para finalizar):");
    gets(nome);

    while (nome[0] != '0')
    {
        if (raiz == NULL)
        {
            raiz = malloc(sizeof(Tcarro));
            ultimo = raiz;
        }
        else
        {
            ultimo->proximo = malloc(sizeof(Tcarro));
            ultimo = ultimo->proximo;
        }
        if (ultimo == NULL)
        {
            printf("Erro: Memoria insufuciente.\n");
            return -1;
        }
        ultimo->proximo = NULL;
        strcpy(ultimo->nome, nome);
        printf("Digite o tempo de chegada: ");
        scanf("%f", &(ultimo->tempo));
        fflush(stdin);
        printf("Digite o nome da equipe (0 para finalizar):");
        gets(nome);
    }

    if (raiz != NULL)
    {
        printf("\nSaida de dados\n");
        while (raiz != NULL)
        {
            ultimo = raiz;
            printf("Equipe: %10s Tempo: %3.1f\n",
                   ultimo->nome,
                   ultimo->tempo);
            raiz = ultimo->proximo;
            free(ultimo);
        }
    }

    system("PAUSE");
    return 0;
}
