#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Escreva um programa para ler e imprimir os resultados de uma turma de n alunos em uma
disciplina (matrícula, nome, sobrenome, nota). O programa deverá informar o melhor estudante,
o pior estudante e a média da turma. Considere n um valor informado pelo usuário.
*/
typedef struct
{
    char nome[50];
    int matricula;
    float nota;

} aluno;
int main(void)
{
    int n, i, melhor = 0, pior = 0, rel = 0;
    float media = 0.0;
    aluno *turma;
    printf("INSIRA O NUMERO DE ALUNOS ");
    scanf("%d", &n);
    fflush(stdin);
    turma = malloc(n * sizeof(aluno));
    if (turma == NULL)
    {
        printf("MEMORIA NAO ALOCADA\n");
        exit(-1);
    }
    for (i = 0; i < n; i++)
    {

        system("clear || cls");
        fflush(stdin);
        printf("Insira o nome do aluno [%d]: ", i + 1);
        gets(turma[i].nome);
        printf("Insira a matricula de %s\n", turma[i].nome);
        scanf("%d", &turma[i].matricula);
        printf("Insira a nota\n");
        scanf("%f", &turma[i].nota);
        media += turma[i].nota;
        if (turma[i].nota > turma[melhor].nota)
        {
            melhor = i;
        }
        if (turma[i].nota < turma[pior].nota)
        {
            pior = i;
        }
        }
    media /= n;
    printf("\nMelhor aluno: %s (Matricula: %d, Nota: %.2f)\n", turma[melhor].nome, turma[melhor].matricula, turma[melhor].nota);
    printf("Pior aluno: %s (Matricula: %d, Nota: %.2f)\n", turma[pior].nome, turma[pior].matricula, turma[pior].nota);
    printf("Media da turma: %.2f\n", media);
    free(turma);
}