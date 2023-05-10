#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define N 100

void inicio();
void inserir();
void listar();
void remover();
typedef struct gastos
{
    int mes;
    char tipodeConta[N];

} Tgastos;

int main(void)
{
    int opcao;
    do
    {
        inicio();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
            system("clear || cls");
            printf("OBRIGADO POR ULTILIZAR\n");
            printf("VOLTE SEMPRE\n");
            break;
        case 1:
            inserir();
            break;
        case 2:
            listar();
            break;
        case 3:
            remover();
            break;
        default:
            printf("ESCOLHA APNEAS AS OPCEOS LISTADAS :) ");
            break;
        }
    } while (opcao != 0);
    return 0;
}
void inicio()
{
    printf("ESOCOLHA UMA DAS SEGUINTES OPCOES\n");
    printf("0. Sair\n");
    printf("1. Inserir\n");
    printf("2. Pesquisar\n");
    printf("3. Remover\n");
}
void inserir()
{
    FILE *arquivo;
    Tgastos ctt;
    arquivo = fopen("gastos.txt", "ab");
    if (arquivo == NULL)
    {
        printf("ARQUIVO NAO ABERTO :(");
        exit(-1);
    }
    else
    {
        do
        {
            printf("Digite o mes de forma numerica: ");
            scanf("%d", &ctt.mes);
            fflush(stdin);

            printf("Digite o tipo da conta: ");
            scanf("%s", ctt.tipodeConta);

            fwrite(&ctt, sizeof(Tgastos), 1, arquivo);

            printf("Deseja inserir mais alguma conta (s/n): ");
        } while (getche() == 's' || getche() == 'S');
        fclose(arquivo);
    }
}
void listar()
{
    system("clear || cls");
    FILE *arquivo;
    Tgastos ctt;

    arquivo = fopen("gastos.txt", "rb");
    if (arquivo == NULL)
    {
        printf("O ARQUIVO NAO FOI ABERTO :(");
        exit(-1);
    }
    else
    {
        while (fread(&ctt, sizeof(Tgastos), 1, arquivo))
        {
            printf("Mes: %d\n", ctt.mes);
            printf("Tipo de conta: %s\n", ctt.tipodeConta);
        }
        printf("FIM DA LISTA, PRECIONE ENTER PARA RETORNAR AO MENU");
        getch();
        system("clear || cls");
        fclose(arquivo);
    }
}
void remover()
{
    system("clear || cls");
    FILE *arquivo;
    FILE *temp;
    Tgastos ctt;
    char nome[N];
    int mes;
    int achou = 0;
    int tanto = ' ';
    char tanto2[N];
    arquivo = fopen("gastos.txt", "rb");
    temp = fopen("temp.txt", "wb");
    if (arquivo == NULL)
    {
        printf("ARQUIVO NAO ABERTO!\n");
        exit(-1);
    }
    else
    {
        printf("INSIRA O MES E O NOME DA CONTA QUE DESEJA REMOVER\n");
        fflush(stdin);
        scanf("%d", &mes);
        fflush(stdin);
        gets(nome);

        while (fread(&ctt, sizeof(Tgastos), 1, arquivo))
        {
            if (strcmp(nome, ctt.tipodeConta) == 0 && mes == ctt.mes)
            {
                achou = 1;
                printf("Mes: %d", ctt.mes);
                printf("Tipo de conta: %s", ctt.tipodeConta);
                printf("Deseja remover esse cadstro(S/N)?\n");
                strcpy(ctt.tipodeConta, tanto2);
                ctt.mes = tanto;
                if (getche() == 's')
                {
                    achou = 2;
                }
                else
                {
                    fwrite(&ctt, sizeof(Tgastos), 1, temp);
                }
            }
            else
            {
                fwrite(&ctt, sizeof(Tgastos), 1, temp);
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
            printf("cadastro removido com sucesso!\n");
        }
        fclose(arquivo);
        fclose(temp);
        remove("gastos.txt");
        rename("temp.txt", "gastos.txt");
    }
}