#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nome[100];
    int idade;
} Tpessoa;
Tpessoa *alocacao(void);
void inserir(Tpessoa *);
void menu(int *opcao);
void mostrar(Tpessoa *vector);

int main(void)
{
    Tpessoa *dados;
    int opcao = 0;
    do
    {
        menu(&opcao);
        switch (opcao)
        {
        case 1:
            system("clear || cls");
            dados = alocacao();
            inserir(dados);
            printf("0 pra sair e 1 pra cadastrar novamente");
            scanf("%d", &opcao);
            while (opcao != 0 && opcao != 1)
            {
                printf("Digite 0 ou 1");
                scanf("%d", &opcao);
            }
            break;
        case 2:
            mostrar(dados);
            printf("1. Voltar ao menu? 0. Sair");
            scanf("%d", &opcao);
            while (opcao != 0 || opcao != 1)
            {
                printf("Digite 0 ou 1");
                scanf("%d", &opcao);
            }
            break;
        default:
            printf("Esolha uma das opcoes: ");
            scanf("%d", &opcao);
            break;
        }
    } while (opcao != 0);
}
void mostrar(Tpessoa *vector)
{
    system("clear || cls");
    FILE *arquivo;
    if ((arquivo = fopen("bd.txt", "r")) == NULL)
        exit(-1);
    rewind(arquivo);
    while (fscanf(arquivo, "%s %d\n", vector->nome, &vector->idade) != EOF)
    {
        printf("Nome: %s\n", vector->nome);
        printf("Idade: %d\n", vector->idade);
    }
    fclose(arquivo);
}
void inserir(Tpessoa *dados)
{
    FILE *arquivo;
    if ((arquivo = fopen("bd.txt", "a+")) == NULL)
        exit(-1);
    fflush(stdin);
    printf("Insira seu nome: ");
    scanf("%[^\n]s", dados->nome);
    scanf("%*c");
    printf("Insira sua idade: ");
    scanf("%d", &dados->idade);
    fprintf(arquivo, "%s\n %d\n", dados->nome, dados->idade);
    fclose(arquivo);
}
Tpessoa *alocacao(void)
{
    Tpessoa *temp;
    temp = (Tpessoa *)malloc(sizeof(Tpessoa));
    if (temp == NULL)
    {
        printf("Memoria nao alocada, procure o desenvolvedor: ");
        exit(-1);
    }
    return temp;
}
void menu(int *opcao)
{
    printf("BEM VINDO\n");
    printf("0. SAIR\n");
    printf("1. INSERIR\n");
    printf("2. MOSTAR\n");
    scanf("%d", opcao);
}