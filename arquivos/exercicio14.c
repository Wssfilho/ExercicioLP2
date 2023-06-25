#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int numeroConta;
    char titular[50];
    float saldo;
} Conta;
void printartodos(FILE *arquivo)
{
    system("clear || cls");
    Conta contas;
    fseek(arquivo, 0, SEEK_SET);
    while (fread(&contas, sizeof(Conta), 1, arquivo) == 1)
    {

        printf("Nome: %s\n", contas.titular);
        printf("Saldo: %f\n", contas.saldo);
    }
}
void inserirConta(FILE *arquivo)
{
    Conta conta;
    printf("Insira o nome do titular: ");
    scanf("%s", conta.titular);
    printf("Insira o saldo: ");
    scanf("%f", &conta.saldo);
    fseek(arquivo, 0, SEEK_END);
    conta.numeroConta = ftell(arquivo) / sizeof(Conta);
    fwrite(&conta, sizeof(Conta), 1, arquivo);
}

void atualizarSaldo(FILE *arquivo)
{
    int numConta;
    float valor;
    Conta conta;
    printf("Insira o número da conta: ");
    scanf("%d", &numConta);
    fseek(arquivo, numConta * sizeof(Conta), SEEK_SET);
    if (fread(&conta, sizeof(Conta), 1, arquivo) != 1)
    {
        printf("Número de conta inválido!\n");
        return;
    }
    printf("Insira o valor a ser adicionado/subtraído: ");
    scanf("%f", &valor);
    conta.saldo += valor;
    fseek(arquivo, -sizeof(Conta), SEEK_CUR);
    fwrite(&conta, sizeof(Conta), 1, arquivo);
}

void listarDevedores(FILE *arquivo)
{
    Conta conta;
    printf("Clientes devedores:\n");
    fseek(arquivo, 0, SEEK_SET);
    while (fread(&conta, sizeof(Conta), 1, arquivo) == 1)
    {
        if (conta.saldo < 0)
        {
            printf("%s\n", conta.titular);
        }
    }
}

void listarCredores(FILE *arquivo)
{
    Conta conta;
    printf("Clientes credores:\n");
    fseek(arquivo, 0, SEEK_SET);
    while (fread(&conta, sizeof(Conta), 1, arquivo) == 1)
    {
        if (conta.saldo > 0)
        {
            printf("%s\n", conta.titular);
        }
    }
}

int main()
{
    FILE *arquivo = fopen("contas.bin", "r+b");

    if (arquivo == NULL)
    {
        arquivo = fopen("contas.bin", "w+b");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir/criar arquivo!\n");
            return -1;
        }
    }

    int opcao;

    do
    {
        printf("\n1) Inserir conta\n2) Atualizar saldo\n3) Listar clientes devedores\n4) Listar clientes credores\n5) Encerrar programa\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printartodos(arquivo);
            // inserirConta(arquivo);
            break;
        case 2:
            atualizarSaldo(arquivo);
            break;
        case 3:
            listarDevedores(arquivo);
            break;
        case 4:
            listarCredores(arquivo);
            break;
        case 5:
            break;
        default:
            printf("Opção inválida!\n");
        }

        fflush(arquivo);

    } while (opcao != 5);

    fclose(arquivo);

    return 0;
}
