#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a estrutura Transacao para armazenar as informações sobre cada transação
typedef struct
{
    char data_hora[20];
    int codigo;
    char descricao[100];
    int quantidade;
    float valor;
} Transacao;
// Função para obter a data e hora atual do computador
void obter_data_hora(char *data_hora)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(data_hora, "%d-%02d-%02d %02d:%02d:%02d",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    // uso a função sprintf para formatar a data e hora atual em uma string no formato “AAAA-MM-DD HH:MM:SS.
}

// Função para ler as informações do usuário
void ler_transacao(Transacao *transacao)
{
    printf("Digite o codigo numerico do artigo vendido: ");
    scanf("%d", &transacao->codigo);
    fflush(stdin);
    printf("Digite a descricao do artigo vendido: ");
    scanf("%[^\n]s", transacao->descricao);
    fflush(stdin);
    printf("Digite a quantidade: ");
    scanf("%d", &transacao->quantidade);
    printf("Digite o valor da transacao: ");
    scanf("%f", &transacao->valor);
}

// Função para armazenar a transação no arquivo
void armazenar_transacao(Transacao *transacao)
{
    FILE *arquivo;
    // Abre o arquivo no modo de anexação ("a") para adicionar novas transações ao final do arquivo
    arquivo = fopen("transacoes.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    // Armazena a transação em uma linha do arquivo, separando os campos por vírgulas
    fprintf(arquivo, "%s, %d, %s, %d, %.2f\n", transacao->data_hora, transacao->codigo, transacao->descricao, transacao->quantidade, transacao->valor);
    fclose(arquivo);
}

int main(void)
{
    Transacao transacao;
    char continuar;

    // Loop para ler várias transações do usuário
    do
    {
        // pega a data e hora atual
        obter_data_hora(transacao.data_hora);
        // Lê as informações sobre a transação do usuário
        ler_transacao(&transacao);
        // Armazena a transação no arquivo
        armazenar_transacao(&transacao);
        // Pergunta ao usuário se ele deseja inserir outra transação
        printf("Deseja inserir outra transacao? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    return 0;
}
