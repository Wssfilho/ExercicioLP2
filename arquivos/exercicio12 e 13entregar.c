#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//nesse exercicio foram feitos o 12 & o 13 juntos!
typedef struct
{
    char nome[30];
    int matricula; //declaracao da estrutura e dos campos
    float cr;
} Estudante;

void inserir(Estudante *turma, int n); //declaracao das funcoes com seus respectivos parâmetros
void gravar(Estudante *turma, int n);
void mostrar(float minCR, float maxCR);
void menu(void);
void executarPrograma(void);

int main(void)
{
    executarPrograma(); //funcao principal
    return 0;
}

void executarPrograma(void)
{
    int opcaoInicial;
    printf("1. Inserir novos alunos\n");
    printf("2. Acessar alunos cadastrados\n");
    printf("Escolha uma opcao: "); //menu
    scanf("%d", &opcaoInicial);

    if (opcaoInicial == 1)
    {
        //se a opacao for igual a 1, ele insere novos alunos alocados dinamicamnete
        int n;
        printf("Insira o numero de alunos: ");
        scanf("%d", &n);

        Estudante *turma = malloc(n * sizeof(Estudante)); //alocacao dinamica
        if (turma == NULL)
        {
            printf("Erro ao alocar memoria!\n");
            exit(1);
        }

        inserir(turma, n); //chamadas as funcoes de inserir os dados
        gravar(turma, n); //chamada a funcao de gravar os dados no arquivo

        free(turma); //liberacao de memoria
    }

    int opcao;
    do
    {
        menu(); //menu
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            mostrar(7.0f, 10.0f); //execulta o caso em que mostra oq a questao 13 pedia
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
            printf("Opcao invalida!\n");
        }
    } while (opcao != 4);
}

void inserir(Estudante *turma, int n) //funcao inserir que recebe um ponteiro a estrutura e um inteiro
{
    for (int i = 0; i < n; i++)
    {
        printf("Nome do estudante %d: ", i + 1);
        scanf(" %29[^\n]", turma[i].nome); //for para cadastro dos alunos e colocar na estrutura
        printf("Matricula do estudante %d: ", i + 1);
        scanf("%d", &turma[i].matricula);
        printf("CR do estudante %d: ", i + 1);
        scanf("%f", &turma[i].cr);
    }
}

void gravar(Estudante *turma, int n) //funcao que recebe um ponteiro a estrutura e um numero
{
    FILE *arq = fopen("turma.dat", "ab"); //abertura do arquivo como append
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n"); //caso nao possa ser aberto
        exit(1);
    }

    fwrite(turma, sizeof(Estudante), n, arq); //escrevendo no arquivo

    fclose(arq); //fechando o arquivo
}

void mostrar(float minCR, float maxCR) //recebe o maximo e o minimo do Cr (Pedidos na questao 13)
{
    FILE *arq = fopen("turma.dat", "rb"); //abertura do aquivo como leitura
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo!\n"); //caso o arquivo nao seja aberto
        exit(1);
    }
    rewind(arq); //mover o ponteiro para o comeco do arquivo
    Estudante estudante; //declarando uma estrutura
    while (fread(&estudante, sizeof(Estudante), 1, arq) == 1) //laco para enquanto tiver dados
    {
        if (estudante.cr >= minCR && estudante.cr <= maxCR) //compara os cr e mostra na tela oq o usuario pedir
        {
            printf("%s - %d - %.2f\n", estudante.nome, estudante.matricula, estudante.cr); //mostrar na tela
        }
    }

    fclose(arq); //fechar o arquivo
}

void menu(void) //menu
{
    printf("\n----- Menu -----\n\n");
    printf("1. Alunos com CR > 7\n");
    printf("2. Alunos com 5 < CR < 7\n");
    printf("3. Alunos com CR < 5\n");
    printf("4. Encerrar o programa\n");
    printf("\nEscolha uma opcao: ");
}