#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade;
    char cpf[12];
    float salario;
} Trabalhador;

void le_trabalhador(Trabalhador *t)
{
    printf("Nome: ");
    scanf("%s", t->nome);
    printf("Idade: ");
    scanf("%d", &t->idade);
    printf("CPF: ");
    scanf("%s", t->cpf);
    printf("Salário: ");
    scanf("%f", &t->salario);
}

void grava_trabalhador(Trabalhador t, char *nomeArquivo)
{
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }
    fprintf(arquivo, "%s\n%d\n%s\n%.2f\n", t.nome, t.idade, t.cpf, t.salario);
    fclose(arquivo);
}

int main()
{
    int n;
    printf("Quantos trabalhadores deseja cadastrar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        Trabalhador t;
        le_trabalhador(&t);
        if (t.idade >= 50)
        {
            grava_trabalhador(t, "seniors.txt");
        }
        else
        {
            grava_trabalhador(t, "juniors.txt");
        }
    }

    return 0;
}
