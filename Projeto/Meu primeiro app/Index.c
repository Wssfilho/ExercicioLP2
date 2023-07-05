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
void mostrarpessoa(FILE *arq, Tpessoa *);
Tpessoa *alocacao(void);
void inserir(Tpessoa *a, FILE *arquivo);
// void mostraraniversario(Tpessoa estrutura[], const int n);
void error(int *opacao);
// void returno(int *opcao);
int main(void)
{
    FILE *arquivo = fopen("arquivo.txt", "a+");
    if (arquivo == NULL)
        exit(-1);
    Tpessoa *dados; // estrutura alocada dinamicamente.
    int opcao, cont = 0;
    do
    {
        cabecalho();
        scanf("%d", &opcao);
        system("clear || cls");
        switch (opcao)
        {
        case 1:
            system("clear || cls");
            dados = alocacao();
            inserir(dados, arquivo);
            sleep(2);
            cont++;
            break;
        case 2:
            mostrarpessoa(arquivo, dados);
            break;
        case 3:
        /*
            if (cont == 0)
            {
                error(&opcao);
            }
            else
            {
                mostraraniversario(dados, n);
            }
            break;
        */
        default:
            // printf("Entrou do defout");
            break;
        }

    } while (opcao > 0);
    fclose(arquivo);
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
Tpessoa *alocacao(void)
{
    Tpessoa *dado = (Tpessoa *)malloc(sizeof(Tpessoa));
    if (dado == NULL)
    {
        printf("Memoria nao alocadas");
        exit(-1);
    }
    return dado;
}
void inserir(Tpessoa *a, FILE *arquivo)
{
    fflush(stdin);
    printf("Digite o nome: ");
    gets(a->nome);
    fflush(stdin);
    printf("Digite a idade: ");
    scanf("%d %d %d", &a->datnasc.dia, &a->datnasc.mes, &a->datnasc.ano);
    fprintf(arquivo, "%s %d %d %d\n", a->nome, a->datnasc.dia, a->datnasc.mes, a->datnasc.ano);
}
void mostrarpessoa(FILE *arq, Tpessoa *vetor)
{
    rewind(arq);
    printf("\n--Dados do Aluno--\n");
    while (fscanf(arq, "%s %d %d %d\n", vetor->nome, &vetor->datnasc.dia, &vetor->datnasc.mes, &vetor->datnasc.ano) != EOF)
    {
        printf("Nome: %s\n", vetor->nome);
        printf("Idade: %d %d %d\n", vetor->datnasc.dia, vetor->datnasc.mes, vetor->datnasc.ano);
    }
    fclose(arq);
}
/*void mostraraniversario(Tpessoa estrutura[], const int n)
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
*/
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
