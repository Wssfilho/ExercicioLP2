#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef struct
{
    int dia;
    int mes;
    int ano;

} Tdata;
typedef struct
{
    char nome[N];
    Tdata datnasc;

} Tpessoa;
void cabecalho(void);
void lerpessoa(const int n, Tpessoa *);
void mostrarpessoa(const int n, const Tpessoa *);
Tpessoa *alocacao(const int n);
int main(void)
{
    Tpessoa *dados;
    int opcao;
    do
    {
        cabecalho();
        int n;
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("insira a quantidade de Alunos: ");
            scanf("%d", &n);
            dados = alocacao(n);
            lerpessoa(n, dados);
            printf("Deseja voltar ao menu? sim 1, nao 0 ");
            scanf("%d", &opcao);
            break;
        case 2:
            mostrarpessoa(n, dados);
            break;
        default:
            system("clear || cls");
            break;
        }

    } while (opcao != 0);
    free(dados);
    return 0;
}
void cabecalho(void)
{
    printf("---- BEM VINDO AO SYSTEMA ----");
    printf("\nEscolha uma das opcoes: \n");
    printf("0. Sair");
    printf("\n");
    printf("1. Inserir");
    printf("\n");
    printf("2. Mostrar");
}
Tpessoa *alocacao(const int n)
{
    Tpessoa *dados;
    dados = (Tpessoa *)malloc(n * sizeof(Tpessoa));
    if (dados == NULL)
    {
        printf("Memoria nao alocadas");
        exit(-1);
    }
    return dados;
}
void lerpessoa(const int n, Tpessoa *vetor)
{
    for (int i = 0; i < n; i++)
    {
        printf("Insira o nome do aluno %d: ", i + 1);
        scanf("%*c");
        scanf("%[^\n]s%*c", vetor[i].nome);
        printf("Insira a data de nascimento dd/mm/aa (sem pontos e caracteres): ");
        scanf("%d %d %d", &vetor[i].datnasc.dia, &vetor[i].datnasc.mes, &vetor[i].datnasc.ano);
    }
}
void mostrarpessoa(const int n, const Tpessoa *vetor)
{
    system("clear || cls");
    for (int i = 0; i < n; i++)
    {
        printf("\n--Dados do Aluno--\n");
        printf("Nome: %s\n", vetor[i].nome);
        printf("Data de nascimento: %d/%d/%d\n", vetor[i].datnasc.dia, vetor[i].datnasc.mes, vetor[i].datnasc.ano);
    }
}
