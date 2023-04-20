#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Escreva um programa para ler e imprimir os resultados de uma turma de n alunos em uma
disciplina (matrícula, nome, sobrenome, nota). O programa deverá informar o melhor estudante,
o pior estudante e a média da turma. Considere n um valor informado pelo usuário.
*/
typedef struct
{
    int matricula;
    char nome[50];
    int nota;

} Turma;
int main(void)
{
    int n, i;
    Turma *alunos;
    printf("INSIRA O NUMERO DE ALUNOS");
    scanf("%d", &n);
    fflush(stdin);
    alunos = malloc(n * sizeof(Turma));
    if (alunos == NULL)
    {
        printf("MEMORIA NAO ALOCADA\n");
        exit(-1);
    }
    for (i = 0; i < n; i++)
    {
        printf("Insira o nome do aluno [%d]\n", i);
        gets(alunos[i].nome);
        
    }
    for (i = 0; i < n; i++, alunos++)
    {
        printf("Insira o nome do aluno [%s]\n", alunos->nome);
    }

    free(alunos);
}