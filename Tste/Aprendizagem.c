#include <stdio.h>
#include <stdlib.h>

// Define a estrutura Taluno com os membros nome, idade e matricula
typedef struct
{
    char nome[50];
    int idade;
    int matricula;
} Taluno;

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

int main()
{
    int n;
    // Pede ao usuário o número de alunos
    printf("Digite o número de alunos: ");
    scanf("%d", &n);

    // Aloca dinamicamente o array de alunos
    Taluno *alunos;
    alunos = alocar(n);

    // Preenche os dados dos alunos
    preencher(alunos, n);
    // Mostra os dados dos alunos
    mostrar(alunos, n);
    //mostar o aluno mais novo
    comp(alunos, n);
    // Libera a memória alocada
    free(alunos);

    return 0;
}
