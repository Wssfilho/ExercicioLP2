#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[255];
    char telefone[13];
} Taluno;

int main(void)
{
    Taluno aluno;
    FILE *arq;
    if ((arq = fopen("bancodealunos.txt", "w")) == NULL)
    {
        printf("O arquivo nao foi escrito");
        exit(-1);
    }
    while (1)
    {
        printf("Insira o nome do aluno: ");
        gets(aluno.nome);
        if (strcmp(aluno.nome, "") == 0)
            break;
        printf("Insira o telefone: ");
        gets(aluno.telefone);
        fprintf(arq, "%s %s", aluno.nome, aluno.telefone);
    }
    fclose(arq);
}