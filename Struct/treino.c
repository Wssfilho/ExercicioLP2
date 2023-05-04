#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
typedef struct
{
    int idade;
    float nota1, nota2, nota3;
} Tdata;

typedef struct
{
    char nome[100];
    Tdata data;
} Taluno;

int main(void)
{
    int num;
    printf("Insira o numero de alunos: \n");
    scanf("%d", &num);
    fflush(stdin);

    Taluno *turma;
    float somaaluno;
    turma = (Taluno *)malloc(num * sizeof(Taluno));
    for (int i = 0; i < num; i++)
    {
        fflush(stdin);
        printf("insira o nome do aluno: \n");
        gets(turma[i].nome);
        fflush(stdin);
        printf("Insira a primeira nota do aluno: %s\n", turma[i].nome);
        scanf("%f", &turma[i].data.nota1);
        printf("Insira a segunda nota: \n");
        scanf("%f", &turma[i].data.nota2);
        printf("Insira a terceira nota: \n");
        scanf("%f", &turma[i].data.nota3);
        fflush(stdin);
        somaaluno += turma[i].data.nota1 + turma[i].data.nota2 + turma[i].data.nota3;
    }
    float media = somaaluno / num;
    int maior = 0;
    int menor = 0;
    for (int i = 0; i < num; i++)
    {
        if (turma[i].data.nota1 > turma[i -  1].data.nota1 && turma[i].data.nota2 > turma[i - 1].data.nota2 && turma[i].data.nota3 > turma[i - 1].data.nota3)
        {
            
            maior = i;

        }
        else
        {
            menor = i;
        }
    }
    //system("clear || cls");
    printf("O aluno com nota mais alta nas prova: %s\n", turma[maior].nome);
    printf("o aluno com nota menor: %s\n", turma[menor].nome);
    printf("A media da turma foi: %.2f\n", media);
    free(turma);
    return 0;
}