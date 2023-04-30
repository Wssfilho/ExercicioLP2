#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;

} Tdata;

typedef struct
{
    char nome[50];
    int telefone;
    Tdata dataNascimento;

} Tclientes;

int main(void)
{
    int numCliente, i;
    printf("INSIRA O NUMERO DE CLIENTES: \n");
    scanf("%d", &numCliente);
    Tclientes clientes[numCliente]; // o for pecorre isso;
    Tdata dataProcessamento;
    int maior = 0, menores = 0;

    printf("INSIRA A DATA ATUAL: DD/MM/AA");
    scanf("%d %d %d", &dataProcessamento.dia, &dataProcessamento.mes, &dataProcessamento.ano);
    fflush(stdin);
    for (i = 0; i < numCliente; i++)
    {
        fflush(stdin);
        printf("DIGITE O NOME DO CLIENTE: ");
        gets(clientes[i].nome);
        fflush(stdin);
        printf("INSIRA A DATA DE NASCIMENTO: %d (DD/MM/AA) ", i + 1);
        scanf("%d %d %d", &clientes[i].dataNascimento.dia, &clientes[i].dataNascimento.mes, &clientes[i].dataNascimento.ano);
        fflush(stdin);
        printf("INSIRA O TELEFONE: ");
        scanf("%d", &clientes[i].telefone);
    }
    for (i = 0; i < numCliente; i++)
    {
        if (dataProcessamento.ano - clientes[i].dataNascimento.ano > 21)
        {
            maior++;
        }
        else if (dataProcessamento.ano - clientes[i].dataNascimento.ano == 21 && dataProcessamento.mes > clientes[i].dataNascimento.mes)
        {
            maior++;
        }
        else if (dataProcessamento.ano - clientes[i].dataNascimento.ano == 21 && dataProcessamento.mes == clientes[i].dataNascimento.mes && dataProcessamento.dia >= clientes[i].dataNascimento.dia)
        {
            maior++;
        }
        else
        {
            menores++;
        }
    }
    printf("Numero de clientes maiores de idade: %d\n", maior);
    printf("O numero de clientes menores de idade: %d\n", menores);
    printf("Clientes que fazer aniversario no mes atual: \n");
    for (i = 0; i < numCliente; i++)
    {
        if (clientes[i].dataNascimento.mes == dataProcessamento.mes)
        {
            printf("%s %d", clientes[i].nome, clientes[i].telefone);
        }
    }
    return 0;
}