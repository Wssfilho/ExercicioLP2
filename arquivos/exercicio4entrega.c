#include <stdio.h>
#include <time.h>

typedef struct
{
    int codigo;
    char descricao[100]; // definicao de uma estrutura para armazenar as variaveis
    int quantidade;
    float valor;
} Transacao;
int main(void)
{

    FILE *arquivo;        // criacao de um ponteiro para arquivo
    Transacao transacao;  // definicao da estrutura transacao
    char continuar = 's'; // variavel qu controla o loop

    arquivo = fopen("transacoes.txt", "a"); // abertura de um arquivo com append
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n"); // caso o arquivo de error
        return 1;
    }

    while (continuar == 's' || continuar == 'S') // loop para pedir os dados
    {
        printf("Digite o código numérico do artigo vendido: ");
        scanf("%d", &transacao.codigo);
        printf("Digite a descrição do artigo vendido: ");
        scanf(" %[^\n]", transacao.descricao);
        printf("Digite a quantidade: ");
        scanf("%d", &transacao.quantidade);
        printf("Digite o valor da transação: ");
        scanf("%f", &transacao.valor);
        fprintf(arquivo, ", %d, %s, %d, %.2f\n",
                transacao.codigo, transacao.descricao,
                transacao.quantidade, transacao.valor); // gravacao dos dados num arquivo
        printf("Transação armazenada com sucesso.\n");
        printf("Deseja inserir outra transação? (s/n): ");
        scanf(" %c", &continuar);
    } // fim do arquivo

    fclose(arquivo); // fechamento do loop

    return 0;
}
