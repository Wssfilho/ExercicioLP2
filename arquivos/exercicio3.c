#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nome[100];
    int matricula;
    char sexo;
    int idade;
    char email[20];

} TAluno;
int main(void)
{
    TAluno aluno;
    int opcao = 1;
    FILE *fp;
    if ((fp = fopen("aluno.txt", "w")) == NULL)
    {
        printf("O arquivo nao foi aberto");
        exit(-1);
    }
    do
    {
        printf("Insira o nome: ");
        scanf("%[^\n]s%*c", aluno.nome);
        printf("Insira a matricula: ");
        scanf("%d", &aluno.matricula);
        scanf("%*c");
        printf("Insira o sexo: ");
        scanf("%c", &aluno.sexo);
        scanf("%*c");
        printf("Insira a idade: ");
        scanf("%d", &aluno.idade);
        scanf("%*c");
        printf("Insira o email: ");
        scanf("%[^\n]s", aluno.email);
        scanf("%*c");
        fprintf(fp, "%s %10d %5c %5d %10s\n", aluno.nome, aluno.matricula, aluno.sexo, aluno.idade, aluno.email);
        printf("cadastrar novamente? 0. nao, 1. sim");
        scanf("%d", &opcao);
        scanf("%*c");
    } while (opcao != 0);
    fclose(fp);
    return 0;
}