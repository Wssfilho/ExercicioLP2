#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// exercicio 12 e 13 (foram cocatenados)
typedef struct
{
    char nome[30];
    int matricula;
    float cr;
} Estudante;
Estudante *alloc(int *n);                   // funcao para alocar estrutura;
void inserir(Estudante *, const int);       // funcao para receber os dados do usuario;
void gravar(Estudante *turma, const int n); // funcao para gravar os dados gerados no arquivo;
void menu(int *);
int main(void)
{
    Estudante *turma;
    int n, opcao;
    menu(&opcao);
    switch (opcao)
    {
    case 1:
        turma = alloc(&n);
        inserir(turma, n);
        gravar(turma, n);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        system("clear || cls");
        printf("Obrigado por utilizar");
        exit(-1);
        break;
    default:
        break;
    }
    return 0;
}
void menu(int *opcao)
{
    printf("-----Bem vindo ao Cadastrealunos-----\n\n");
    printf("1. Inserir");
    printf("2. Listar alunos com CR < 7\n");
    printf("3. Listar alunos com 5 < CR < 7\n");
    printf("4. Listar alunos com 5 < CR\n");
    printf("5. Encerrar programa: \n");
    printf("Escolha uma das opcaoes: ");
    scanf("%d", opcao);
}
void inserir(Estudante *turma, const int n)
{
    // Lendo os dados dos estudantes
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Nome do estudante %d: ", i + 1);
        gets(turma[i].nome);
        fflush(stdin);
        printf("Matrícula do estudante %d: ", i + 1);
        scanf("%d", &turma[i].matricula);
        printf("CR do estudante %d: ", i + 1);
        scanf("%f", &turma[i].cr);
        fflush(stdin);
    }
}
Estudante *alloc(int *n)
{
    // alocando dinamicamente a memoria;
    printf("insira o numero de alunos ou o tamanho da turma: ");
    scanf("%d", n);
    while (*n < 0)
    {
        printf("Insira numeros positivos");
        scanf("%d", n);
    }
    Estudante *turma;
    turma = malloc(*n * sizeof(Estudante));
    if (turma == NULL)
    {
        printf("A memoria nao foi alocada, verifique!");
        exit(-1);
    }
    return turma;
}
void gravar(Estudante *turma, const int n)
{

    FILE *arq;
    arq = fopen("turma.dat", "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo, abrindo como escrita.\n");
        arq = fopen("turma.dat", "wb");
    }
    fwrite(turma, sizeof(Estudante), n, arq);
    printf("Arquivo gravado com sucesso!");
    fclose(arq);
}