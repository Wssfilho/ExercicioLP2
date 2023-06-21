#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int matricula;
    float CR;
} Estudante;

void gravarDados(Estudante *estudantes, int n)
{
    FILE *arquivo = fopen("estudantes.dat", "wb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fwrite(estudantes, sizeof(Estudante), n, arquivo);
    fclose(arquivo);
}

void lerDados(Estudante *estudantes, int n)
{
    FILE *arquivo = fopen("estudantes.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    rewind(arquivo);
    fread(estudantes, sizeof(Estudante), n, arquivo);
    fclose(arquivo);
}

void listarAlunos(Estudante *estudantes, int n, float minCR, float maxCR)
{
    for (int i = 0; i < n; i++)
    {
        if (estudantes[i].CR >= minCR && estudantes[i].CR < maxCR)
        {
            printf("%s - %d - %.2f\n", estudantes[i].nome, estudantes[i].matricula, estudantes[i].CR);
        }
    }
}

void lerEstudantes(Estudante *estudantes, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Digite o nome do estudante %d: ", i + 1);
        scanf(" %[^\n]", estudantes[i].nome);
        printf("Digite a matrícula do estudante %d: ", i + 1);
        scanf("%d", &estudantes[i].matricula);
        printf("Digite o CR do estudante %d: ", i + 1);
        scanf("%f", &estudantes[i].CR);
    }
}

void menu(Estudante *estudantes, int n)
{
    int opcao;
    do
    {
        printf("\nMenu:\n");
        printf("1) Alunos com CR > 7\n");
        printf("2) Alunos com 5 < CR < 7\n");
        printf("3) Alunos com CR < 5\n");
        printf("4) Encerrar o programa.\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            listarAlunos(estudantes, n, 7.0, 10.0);
            break;
        case 2:
            listarAlunos(estudantes, n, 5.0, 7.0);
            break;
        case 3:
            listarAlunos(estudantes, n, 0.0, 5.0);
            break;
        case 4:
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (opcao != 4);
}

int main()
{
    int n;
    printf("Digite o número de estudantes: ");
    scanf("%d", &n);

    Estudante *estudantes = malloc(n * sizeof(Estudante));
    if (estudantes == NULL)
    {
        printf("Memoria nao alcoada");
        exit(-1);
    }

    lerEstudantes(estudantes, n);

    gravarDados(estudantes, n);

    lerDados(estudantes, n);

    menu(estudantes, n);

    free(estudantes);

    return 0;
}
