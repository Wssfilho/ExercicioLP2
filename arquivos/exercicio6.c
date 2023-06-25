#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int insc;
    char nome[400];
    char sexo;
    char cusrso[400];
} Vestibular;
void printartodos(Vestibular *cand)
{
    FILE *arq;
    system("clear || cls");
    if ((arq = fopen("candidato.txt", "r")) == NULL)
    {
        printf("Nao foi aberto em modo abertura");
        exit(-1);
    }
    while (fscanf(arq, "%d %s %c %s\n", &cand->insc, cand->nome, &cand->sexo, cand->cusrso) == 4)
    {
        printf("Nome: %s\nsexo: %c\ncurso: %s\n\n", cand->nome, cand->sexo, cand->cusrso);
    }
    fclose(arq);
}
void umcad(Vestibular *cand)
{
    int num;
    FILE *arq;
    system("clear || cls");
    if ((arq = fopen("candidato.txt", "r")) == NULL)
    {
        printf("Nao foi aberto em modo abertura");
        exit(-1);
    }
    printf("Insira o numero do cand que deseja mostrar");
    scanf("%d", &num);
    while (fscanf(arq, "%d %s %c %s\n", &cand->insc, cand->nome, &cand->sexo, cand->cusrso) == 4)
    {

        if (num == cand->insc)
        {
            printf("O candidato de numero %d:\n", num);
            printf("Nome: %s\nsexo: %c\ncurso: %s\n\n", cand->nome, cand->sexo, cand->cusrso);
        }
        else
        {
            printf("Nao ha ninguem com essa inscricao\n");
        }
    }
    fclose(arq);
}
void menu(int *opcao)
{
    printf("(1). Inserir candidato\n");
    printf("(2). Mostrar um candidato \n");
    printf("(3). Listar todos os candidatos\n");
    printf("(4). Sair do programa\n");
    printf("Escolha uma das opcoes: ");
    scanf("%d", opcao);
}
Vestibular *alocar(void)
{
    Vestibular *alunotemp;
    alunotemp = malloc(sizeof(Vestibular));
    if (alunotemp == NULL)
    {
        printf("Nao alocado!");
        exit(-1);
    }
    return alunotemp;
}
void inserir(Vestibular *aluno)
{
    fflush(stdin);
    printf("Insira o num de inscricao: ");
    scanf("%d", &aluno->insc);
    scanf("%*c");
    printf("Insira o nome: ");
    scanf("%[^\n]s", aluno->nome);
    scanf("%*c");
    printf("Insira o sexo: ");
    scanf("%c", &aluno->sexo);
    scanf("%*c");
    printf("Insira o curso: ");
    scanf("%[^\n]s", aluno->cusrso);
    scanf("%*c");
    FILE *arq;
    if ((arq = fopen("candidato.txt", "a")) == NULL)
    {
        printf("Arquivo nao foi aberto com append, abrindo com write");
        arq = fopen("cabdidato.txt", "w");
    }
    fprintf(arq, "%d %s %c %s\n", aluno->insc, aluno->nome, aluno->sexo, aluno->cusrso);
    fclose(arq);
}
int main(void)
{
    int opcao;
    Vestibular *aluno;
    aluno = alocar();
    do
    {
        menu(&opcao);
        switch (opcao)
        {
        case 1:
            inserir(aluno);
            break;
        case 2:
            umcad(aluno);
            break;
        case 3:
            printartodos(aluno);
            break;
        case 4:
            break;
        }
    } while (opcao != 4);
    free(aluno);
    return 0;
}