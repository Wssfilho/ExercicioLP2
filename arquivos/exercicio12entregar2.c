
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nome[30];
    int matricula;
    float cr;
} Estudante;

void inserir(Estudante *turma, int n);
void gravar(Estudante *turma, int n);
void mostrar(float minCR, float maxCR);
void menu(void);
void executarPrograma(void);

int main(void)
{
    executarPrograma();
    return 0;
}

void executarPrograma(void)
{
    int opcaoInicial;
    printf("1. Inserir novos alunos\n");
    printf("2. Acessar alunos cadastrados\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcaoInicial);

    if (opcaoInicial == 1)
    {
        int n;
        printf("Insira o número de alunos: ");
        scanf("%d", &n);

        Estudante *turma = malloc(n * sizeof(Estudante));
        if (turma == NULL)
        {
            printf("Erro ao alocar memória!\n");
            exit(1);
        }

        inserir(turma, n);
        gravar(turma, n);

        free(turma);
    }

    int opcao;
    do
    {
        menu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            mostrar(7.0f, 10.0f);
            break;
        case 2:
            mostrar(5.0f, 7.0f);
            break;
        case 3:
            mostrar(0.0f, 5.0f);
            break;
        case 4:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 4);
}

void inserir(Estudante *turma, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nome do estudante %d: ", i + 1);
        scanf(" %29[^\n]", turma[i].nome);
        printf("Matrícula do estudante %d: ", i + 1);
        scanf("%d", &turma[i].matricula);
        printf("CR do estudante %d: ", i + 1);
        scanf("%f", &turma[i].cr);
    }
}

void gravar(Estudante *turma, int n)
{
    FILE *arq = fopen("turma.dat", "ab");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    fwrite(turma, sizeof(Estudante), n, arq);

    fclose(arq);
}

void mostrar(float minCR, float maxCR)
{
    FILE *arq = fopen("turma.dat", "rb");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    Estudante estudante;
    while (fread(&estudante, sizeof(Estudante), 1, arq) == 1)
    {
        if (estudante.cr >= minCR && estudante.cr <= maxCR)
        {
            printf("%s - %d - %.2f\n", estudante.nome, estudante.matricula, estudante.cr);
        }
    }

    fclose(arq);
}

void menu(void)
{
    printf("\n----- Menu -----\n\n");
    printf("1. Alunos com CR > 7\n");
    printf("2. Alunos com 5 < CR < 7\n");
    printf("3. Alunos com CR < 5\n");
    printf("4. Encerrar o programa\n");
    printf("\nEscolha uma opção: ");
}