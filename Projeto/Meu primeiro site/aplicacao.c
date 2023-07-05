#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nome[40];
    int idade;
    //monte mais alguns espacos
    //pode vir: tipos de dados, como dinheiro, mercadoria; 
} Tpessoa;
Tpessoa *allocar(void);
void menu(int *);
void inserir(Tpessoa *);
void gravar(Tpessoa *);
void mostrar(Tpessoa *);
void mostrarani(Tpessoa *);
void menumain(void);
int main(void) // inicio do programa principal
{
    menumain();
    return 0;
}
void menumain()
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
        case 3:
            mostrarani(dado);
            break;
        default:
            break;
        }
    } while (opcao != 0);
    free(dado);
}
void mostrarani(Tpessoa *dado)
{
    system("clear ||cls");
    fflush(stdin);
    char nometemp[40];
    printf("Insira o nome da pessoa que quer buscar: ");
    gets(nometemp); //teste feito com gets
    FILE *arquivo;
    if ((arquivo = fopen("dados.txt", "r")) == NULL)
    {
        printf("O arquivo nao pode ser aberto");
        exit(-1);
    }
    fflush(stdin);
    int opcao = 0;
    while (fscanf(arquivo, "%s", dado->nome) != EOF)
    {
        if (strcmp(nometemp, dado->nome) == 0) //funcao de compara strings
        {
            opcao++;
            switch (opcao)
            {
            case 1:
                printf("O nome encontrado foi: %s\n", dado->nome);
                break;
            case 2:
                printf("Nao ha ninguem cadastrado no sistema\n");
                break;
            }
        }
    }
    fclose(arquivo);
}
void mostrar(Tpessoa *dado)
{
    system("clear ||cls");
    FILE *arq;
    if ((arq = fopen("dados.txt", "r")) == NULL)
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
    printf("0. Sair\n\n");
    printf("1. Inserir\n\n");
    printf("2. Mostrar\n\n");
    printf("3. Listar por nome\n\n");
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
    system("clear ||cls");
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