#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    time_t tempo;
    int cod;
    char descricao[500];
    int quant;
    float valor;
} Transacao;

int main(void)
{
    Transacao dados;
    int opcao;
    FILE *arq;

    if ((arq = fopen("contas.dat", "ab")) == NULL)
    {
        printf("Arquivo nao aberto de forma 'append', abrindo como escrita\n");
        arq = fopen("contas.dat", "wb");
    }
    do
    {
        dados.tempo = time(NULL);
        printf("Insira o codigo da transacao: ");
        scanf("%d%*c", &dados.cod);
        printf("Insira a descricaoo: ");
        scanf("%[^\n]s%*c", dados.descricao);
        printf("Insira a quantidade do produto: ");
        scanf("%d", &dados.quant);
        printf("Insira o valor do produto");
        scanf("%f", &dados.valor);
        fwrite(&dados, sizeof(Transacao), 1, arq);
        printf("0. para sair e 1. para cadastrar novamente");
        scanf("%d", &opcao);
    } while (opcao != 0);
}