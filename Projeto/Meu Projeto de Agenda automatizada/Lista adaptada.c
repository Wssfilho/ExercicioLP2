#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

typedef struct data DATA;
struct data
{
    int dia;
    int mes;
    int ano;
};
typedef struct contato CONTATO;
struct contato
{
    char nome[30];
    char fone[30];
    DATA aniv;
};
void cabecalho();
void inputData();
void removeData();
void searchData();
void listData();
void aniversariantes();
void desenvolvimento();
void PesquisaPorInicial();

int main(void)
{
    int opcao;
    do
    {

        cabecalho();
        printf("1 - INSERIR\n");
        printf("2 - REMOVER\n");
        printf("3 - PESQUISAR NOME\n");
        printf("4 - LISTAR\n");
        printf("5 - LISTAR POR UMA INICIAL\n");
        printf("6 - IMPRIMIR ANIVERSARIANTES DO MES\n");
        printf("7 - SAIR\n\n");
        printf("Escolha uma das opcoes acima e tecle ENTER: ");
        scanf("%d", &opcao);
        switch (opcao)
        {

        case 1: // INSERIR
            inputData();
            break;
        case 2: // REMOVER
            removeData();
            break;
        case 3: // PESQUISAR
            searchData();
            break;
        case 4: // LISTAR
            listData();
            break;
        case 5: // LISTAR POR INICIAL
            desenvolvimento();
            break;
        case 6: // IMPRIMIR ANV MES
            aniversariantes();
            break;
        case 7: // SAIR
            printf("Obrigado por utliziar");
            getch();
            break;
        default: // DEFOUT
            printf("Opcao invalida!!!\n");
            getch();
            break;
        }

    } while (opcao != 7);
}
void cabecalho()
{
    system("cls || clear");
    printf("--------------------------------------\n");
    printf("AGENDA ELETRONICA DE WILSON SANTOS\n");
    printf("--------------------------------------\n\n");
}
void inputData()
{

    cabecalho();
    FILE *arquivo;
    CONTATO ctt;

    arquivo = fopen("agendinha.txt", "ab");
    if (arquivo == NULL)
    {
        printf("ARQUIVO NAO ABERTO!\n");
    }
    else
    {
        do
        {
            fflush(stdin);
            printf("Digite o nome: ");
            gets(ctt.nome);
            fflush(stdin);

            printf("Digite o telefone: ");
            gets(ctt.fone);
            fflush(stdin);

            printf("Digite o aniversario (dd/mm/aaaa): ");
            scanf("%d %d %d", &ctt.aniv.dia, &ctt.aniv.mes, &ctt.aniv.ano);
            fflush(stdin);

            fwrite(&ctt, sizeof(CONTATO), 1, arquivo);

            printf("Deseja continuar o cadastro(S/N)?\n");

        } while (getche() == 's');
        fclose(arquivo);
    }
}
void removeData()

{
    cabecalho();
    FILE *arquivo;
    CONTATO ctt;
    char nome[30];
    int achou = 0;
    char tanto[30];

    arquivo = fopen("agendinha.txt", "rb");
    if (arquivo == NULL)
    {
        printf("ARQUIVO NAO ABERTO!\n");
    }
    else
    {
        printf("Digite o nome que deseja remover: ");
        fflush(stdin);
        gets(nome);

        while (fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1)
        {
            if (strcmp(nome, ctt.nome) == 0)
            {
                achou = 1;
                printf("Nome: %s\n", ctt.nome);
                printf("Telefone: %s\n", ctt.fone);
                printf("Aniversario: %d/%d/%d\n", ctt.aniv.dia, ctt.aniv.mes, ctt.aniv.ano);
                printf("Deseja remover esse contato(S/N)?\n");
                strcpy(ctt.nome, tanto);
                if (getche() == 's')
                {
                    achou = 2;
                }
            }
        }

        if (achou == 0)
        {
            printf("Nao foi encontrado nenhum contato com esse nome!\n");
        }
        else if (achou == 1)
        {
            printf("Nao foi encontrado nenhum contato com esse nome!\n");
        }
        else
        {
            printf("Contato removido com sucesso!\n");
        }
        fclose(arquivo)
    }
}
void searchData()
{

    cabecalho();
    FILE *arquivo;
    CONTATO ctt;
    char nome[30];
    int achou = 0;

    arquivo = fopen("agendinha.txt", "rb");
    if (arquivo == NULL)
    {
        printf("ARQUIVO NAO ABERTO!\n");
    }
    else
    {
        printf("Digite o nome que deseja pesquisar: ");
        fflush(stdin);
        gets(nome);

        while (fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1)
        {
            if (strcmp(nome, ctt.nome) == 0)
            {
                achou = 1;
                printf("Nome: %s\n", ctt.nome);
                printf("Telefone: %s\n", ctt.fone);
                printf("Aniversario: %d/%d/%d\n", ctt.aniv.dia, ctt.aniv.mes, ctt.aniv.ano);
            }
        }
        if (achou == 0)
        {
            printf("Nao foi encontrado nenhum contato com esse nome!\n");
        }
        getch();
        fclose(arquivo);
    }
}
void listData()
{
    cabecalho();
    FILE *arquivo;
    CONTATO ctt;

    arquivo = fopen("agendinha.txt", "rb");
    if (arquivo == NULL)
    {
        printf("ARQUIVO NAO ABERTO!\n");
    }
    else
    {
        while (fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1)
        {
            printf("Nome: %s\n", ctt.nome);
            printf("Telefone: %s\n", ctt.fone);
            printf("Aniversario: %d/%d/%d\n\n", ctt.aniv.dia, ctt.aniv.mes, ctt.aniv.ano);
        }
        printf("FIM DA LISTA!\n");
        printf("PRESSIONE ENTER PARA RETORNAR AO MENU!\n");
        getch();
        fclose(arquivo);
    }
}
void aniversariantes()
{
    cabecalho();
    FILE *arquivo;
    CONTATO ctt;
    int mes;
    arquivo = fopen("agendinha.txt", "rb");
    printf("DIGITE O MES QUE DESEJA PESQUISAR\n");
    scanf("%d", &mes);
    if (arquivo == NULL)
    {
        printf("ABERTURA FOI INVALIDA");
        exit(-1);
    }
    else
    {
        while (fread(&ctt, sizeof(CONTATO), 1, arquivo) == 1)
        {
            /* code */
            printf("NOME: %s\n", ctt.nome);
            printf("FONE: %s\n", ctt.fone);
            printf("ANIVERSARIO: %d %d %d\n", ctt.aniv.dia, ctt.aniv.mes, ctt.aniv.ano);
        }
    }
    printf("FIM DA LISTA!\n");
    printf("PRESSIONE ENTER PARA RETORNAR AO MENU!\n");
    getch();
    fclose(arquivo);
}
void PesquisaPorInicial()
{
    FILE *arquivo;
    CONTATO ctt;
    char inicial;
    arquivo = fopen("agendinha.txt", "rb");
    printf("DIGITE A INICIAL QUE DESEJA PESQUISAR\n");
    scanf("%s", &inicial);
    if (arquivo == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO");
        exit(-1);
    }
    else
    {
        
    }
}
void desenvolvimento()
{
    cabecalho();
    printf("EM DESENVOLVIMENTO!\n");
    printf("PRESSIONE ENTER PARA RETORNAR AO MENU!\n");
    getch();
}