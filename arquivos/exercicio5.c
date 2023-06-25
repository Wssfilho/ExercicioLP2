#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char descricao[100];
    int quantidade;
    float valor;
} Transacao;

int main(void)
{
    FILE *arquivo;
    Transacao transacao;
    int total_transacoes = 0;
    float saldo_caixa = 0.0;
    int max_quantidade = 0;
    char artigo_mais_vendido[100];
    float max_valor = 0.0;
    char artigo_mais_lucrativo[100];

    arquivo = fopen("transacoes.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
    }
    rewind(arquivo);
    while (fscanf(arquivo, "%*s %d, %[^,], %d, %f\n", &transacao.codigo, transacao.descricao, &transacao.quantidade, &transacao.valor) == 4)
    {
        total_transacoes++;
        saldo_caixa += transacao.valor;
        if (transacao.quantidade > max_quantidade)
        {
            max_quantidade = transacao.quantidade;
            strcpy(artigo_mais_vendido, transacao.descricao);
        }
        if (transacao.valor > max_valor)
        {
            max_valor = transacao.valor;
            strcpy(artigo_mais_lucrativo, transacao.descricao);
        }
    }

    fclose(arquivo);

    printf("Número total de transações: %d\n", total_transacoes);
    printf("Saldo em caixa: %.2f\n", saldo_caixa);
    printf("Artigo que vendeu mais unidades: %s\n", artigo_mais_vendido);
    printf("Artigo que proporcionou mais dinheiro à loja: %s\n", artigo_mais_lucrativo);

    return 0;
}