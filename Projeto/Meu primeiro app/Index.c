#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
void mostraraniversario(Tpessoa estrutura[], const int n);
void error(int *opacao);
//void returno(int *opcao);
int main(void)
{
    Tpessoa *dados; // estrutura alocada dinamicamente.
    int opcao, cont = 0;
    do
    {

        cabecalho();
        int n;
        scanf("%d", &opcao);
        system("clear || cls");
        switch (opcao)
        {
        case 1:
            system("clear || cls");
            printf("insira a quantidade de Alunos: ");
            scanf("%d", &n);
            if (n < 0)
            {
                error(&opcao);
                break;
            }
            dados = alocacao(n);
            lerpessoa(n, dados);
            sleep(2);
            cont++;
            break;
        case 2:
            if (cont == 0)
            {
                error(&opcao);
            }
            else
            {
                mostrarpessoa(n, dados);
            }
            break;
        case 3:
            if (cont == 0)
            {
                error(&opcao);
            }
            else
            {
                mostraraniversario(dados, n);
            }
            break;
        default:
            // printf("Entrou do defout");
            break;
        }

    } while (opcao > 0);
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
    printf("\n");
    printf("3. Procurar aniversariantes: ");
}
Tpessoa *alocacao(const int n)
{
    Tpessoa *dado = (Tpessoa *)malloc(n * sizeof(Tpessoa));
    if (dado == NULL)
    {
        printf("Memoria nao alocadas");
        exit(-1);
    }
    return dado;
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
    for (int i = 0; i < n; i++)
    {
        printf("\n--Dados do Aluno--\n");
        printf("Nome: %s\n", vetor[i].nome);
        printf("Data de nascimento: %d/%d/%d\n", vetor[i].datnasc.dia, vetor[i].datnasc.mes, vetor[i].datnasc.ano);
    }
}
void mostraraniversario(Tpessoa estrutura[], const int n)
{
    int achou = 0;
    Tdata aniv;
    printf("Insira a data de aniversario: ");
    scanf("%d %d %d", &aniv.dia, &aniv.mes, &aniv.ano);
    for (int i = 0; i < n; i++)
    {
        if (aniv.mes == estrutura[i].datnasc.mes && aniv.dia == estrutura[i].datnasc.dia && aniv.ano == estrutura[i].datnasc.ano)
        {
            printf("Essas pessoa faz aniversario nesse mes: %s\n", estrutura[i].nome);
            achou++;
        }
    }
    if (achou == 0)
        printf("Nao ha ninguem cadastrado com essa data\n");
}
void error(int *opcao)
{
    printf("\nNao ha ninguem cadastrado ou numero invalido!\n");
    sleep(1);
    printf("Retornando.");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    system("clear || cls"); // achar uma maneira de colocar o time;
    opcao++;
}
