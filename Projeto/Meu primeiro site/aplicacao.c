#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[40];
    int idade;
} Tpessoa;
Tpessoa *allocar(void);
void menu(int *);
void inserir(Tpessoa *);
void gravar(Tpessoa *);
void mostrar(Tpessoa *);
int main(void)
{
    int opcao;
    Tpessoa *dado = allocar();
    do
    {
        menu(&opcao);
        switch (opcao)
        {
        case 1:
            inserir(dado);
            gravar(dado);
            break;
        case 2:
            mostrar(dado);
            break;
        default:
            break;
        }
    } while (opcao != 0);
    free(dado);
    return 0;
}
void mostrar(Tpessoa *dado)
{
    FILE *arq;
    if((arq = fopen("dados.txt", "r")) == NULL)
    {
        printf("O arquivo nao foi aberto");
        exit(-1);
    }
    while (fscanf(arq, "%s %d", dado->nome, &dado->idade) != EOF)
    {
        printf("Nome: %s\n", dado->nome);
        printf("Idade: %d\n\n", dado->idade);
    }
    
}
void menu(int *opcao)
{
    printf("0. Sair\n");
    printf("1. Inserir\n");
    printf("2. Mostrar\n");
    printf("Escolha uma das opcoes acima: ");
    scanf("%d", opcao);
}
Tpessoa *allocar(void)
{
    Tpessoa *temp;
    temp = malloc(sizeof(Tpessoa));
    if (temp == NULL)
    {
        printf("Nao foi alocado");
        exit(-1);
    }
    return temp;
}
void inserir(Tpessoa *dados)
{
    fflush(stdin);
    printf("Insira seu nome: ");
    scanf("%[^\n]s", dados->nome);
    fflush(stdin);
    printf("Insira sua idade: ");
    scanf("%d", &dados->idade);
}
void gravar(Tpessoa *dado)
{
    FILE *arq;
    if ((arq = fopen("dados.txt", "a+")) == NULL)
    {
        system("clear || cls");
        printf("Nao foi aberto o arquivo! Saindo");
        exit(-1);
    }
    fprintf(arq, "%s %d\n", dado->nome, dado->idade);
    fclose(arq);
}