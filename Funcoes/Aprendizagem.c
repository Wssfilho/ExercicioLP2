#include <stdio.h>
#include <stdlib.h>

// Define a estrutura Taluno com os membros nome, idade e matricula
typedef struct
{
    char nome[50];
    int idade;
    int matricula;
} Taluno;
//funcoes utilizadas
void numeroaluno(int *n);
void opcoes(void);
Taluno *alocar(const int n);
void mostrar(Taluno *alunos, const int n);
void preencher(Taluno *alunos, const int n);
void comp(Taluno *alunos, const int n);
int main(void)
{
    int opcao = 0;
    int n;
    Taluno *alunos;
    numeroaluno(&n);
    // Pede ao usuário o número de alunos
    alunos = alocar(n);
    system("clear || cls");
    do
    {
        opcoes();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            // Preenche os dados dos alunos
            preencher(alunos, n);
            break;
        case 2:
            // Mostra os dados dos alunos
            mostrar(alunos, n);
            break;
        case 3:
            // mostar o aluno mais novo
            comp(alunos, n);
            break;
        }

    } while (opcao);
    // Libera a memória alocada
    free(alunos);

    return 0;
}

//

void numeroaluno(int *n)
{
    opcoes();
    printf("Digite o número de alunos: ");
    scanf("%d", n);
}
// funcao menu
void opcoes(void)
{
    printf("------ ESCOLHA UMA DAS OPCOES------\n\n");
    printf("0. *Sair do sistema* \n");
    printf("1. Inserir aluno: \n");
    printf("2. Mostrar aluno: \n");
    printf("3. Comparar alunos e imprimir o mais novo: \n");
}
// Função para alocar dinamicamente um array de Taluno de tamanho n
Taluno *alocar(const int n)
{
    Taluno *alunos = malloc(n * sizeof(Taluno));
    if (alunos == NULL)
    {
        printf("Erro de memoria: ");
        exit(-1);
    }
    return alunos;
}
// Função para preencher os dados dos alunos
void preencher(Taluno *alunos, const int n)
{
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Digite o nome do aluno %d: ", i + 1);
        scanf("%[^\n]s%*c", alunos[i].nome);
        printf("Digite a idade do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].idade);
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
    }
}
// Função para mostrar os dados dos alunos
void mostrar(Taluno *alunos, const int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Aluno %d\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Matricula: %d\n", alunos[i].matricula);
    }
}
void comp(Taluno *alunos, const int n)
{
    int aluno_novo = 0;
    for (int i = 1; i < n; i++)
    {
        if (alunos[i].idade < alunos[aluno_novo].idade)
        {
            aluno_novo++;
        }
    }
    printf("O aluno mais novo e: %s", alunos[aluno_novo].nome);
}
