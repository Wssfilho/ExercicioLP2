#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMAN 10
#define TEXTO_VERMELHO "\x1b[31;1m"
#define COLOR_RESET "\033[0m"
#define ANSI_COLOR_GREEN "\e[0;32m"
#define ANSI_COLOR_GRAY "\e[0;37m"
#define ANSI_COLOR_YELLOW "\e[0;33m"
#define ANSI_COLOR_BLUE "\e[0;34m"
#define ANSI_COLOR_MAGENTA "\e[0;35m"
#define ANSI_COLOR_CYAN "\e[0;36m"
//construido por Wilson Filho
// cores ansi em c
 //preciso continuar par encher meu formulario
void menu();
void cabecalho();
void sair();
void inserir();
int contador = 0;

struct dados
{
    char nome[100];
    int DDD; // CRIANDO O REGISTRO
    int telefone;
    char remedio[100];
} agenda[TAMAN];  // LOCAL PARA ACESSAR O REGISTRO
struct dados aux; // VARIÁVEL DO REGISTRO
// 1. Fazer o menu;
// 2. fazer as opcoes do menu;
int main()
{

    int opcao = 1, cont;
    do
    {
        menu();
        scanf("%d", &opcao);
        while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4)
        {
            printf("Insira um numero correto\n");
            scanf("%d", &opcao);
        }
        switch (opcao)
        {
        case 0:
            sair();
            break;
        }
        if (opcao == 1)
        {
            cabecalho();
            inserir();
            printf("" COLOR_RESET);
            scanf("%d", &opcao);
            if (opcao == 0)
            {
                system("clear || cls");
                printf(ANSI_COLOR_MAGENTA "\t\t\t\t\tObrigado por utilizar, volte sempre! TESTE: \n" COLOR_RESET);
                break;
            }
        }
        
        if (opcao == 2)
        { // Listar
            if (contador == 0)
            {
                printf("NAO HA NINGUEM CADASTRADO! \n");
                printf("retornar ao menu? Digite 5 ou 0 pra sair! \n");
                scanf("%d", &opcao);
            }
            for (int k = 0; k < contador; k++)
            {
                printf("Nome do paciente: %s \n", agenda[k].nome);
                printf("DDD + Telefone: ( %d ) %d \n", agenda[k].DDD, agenda[k].telefone);
            }
        }
        if (opcao == 3)
        { // buscar por nome
            if (contador == 0)
            {
                printf("NAO HA CONTATOS PARA SEREM BUSCADOS");
                opcao = 5;
                break;
            }
            printf("\nInforme o nome do contato a ser buscado: \n");
            scanf("%s", aux.nome);
            fflush(stdin);
            for (cont = 0; cont < contador; cont++)
            {
                if (strcmp(aux.nome, agenda[cont].nome) == 0)
                {
                    printf("\nNome: %s\n", agenda[cont].nome);
                    printf("DDD + telefone: %d %d\n", agenda[cont].DDD, agenda[cont].telefone);
                    break;
                }
            }
        }
        if (opcao == 4)
        {
            if (contador == 0)
            {
                sair();
                break;
            }
            printf("Digite o nome do cliente que deseja excluir: \n");
            scanf("%s", aux.nome);
            fflush(stdin);
            // printf("%s", aux.nome);
            for (int z = 0; z < contador; z++)
            {
                if (strcmp(agenda[z].nome, aux.nome) == 0)
                {
                    for (int y = z; y < contador - 1; y++)
                    {
                        agenda[y] = agenda[y + 1];
                    }
                }
                contador--;
            }
            printf("CONTATO EXCLUIDO! \n");
            printf("Retornar ao menu? Digite 5, se quiser sair digite 0: \n");
            scanf("%d", &opcao);
        }

        } while (opcao == 5);
}

void sair()
{
    system("clear || cls");
    printf(ANSI_COLOR_GREEN "\t\t\t\t\tObrigado por utilizar! Estamos em desemvolvimento :)\n\n" COLOR_RESET);
}
void cabecalho()
{
    system("clear || cls");
    printf(ANSI_COLOR_YELLOW "\t\t\t\t\t ----------------\n");
    printf("\t\t\t\t\t| Insira os dados!|\n");
    printf("\t\t\t\t\t ----------------\n\n");
}
void menu()
{
    system("clear || cls");
    printf("\t\t\t\t\t ----------------\n");
    printf("\t\t\t\t\t| Seja bem vindo!|\n");
    printf("\t\t\t\t\t ----------------\n\n");
    printf("\t\t\t\t\t1. Insira o nome do paciente: \n");
    printf("\t\t\t\t\t2. Consultar clientes cadastrados: \n");
    printf("\t\t\t\t\t3. Pesquisar nomes : \n");
    printf("\t\t\t\t\t4. Excluir nomes da lista : \n");
    printf("\t\t\t\t\t0. Para retornar ao menu: \n");
}
void inserir()
{
    fflush(stdin);
    printf("Insira o nome do paciente: \n");
    scanf("%s", agenda[contador].nome);
    fflush(stdin);
    printf("Insira o DDD do Telefone: \n");
    scanf("%d", &agenda[contador].DDD);
    fflush(stdin);
    printf("Insira o telefone do paciente: \n");
    scanf("%d", &agenda[contador].telefone);
    fflush(stdin);
    contador++;
    printf("Retornar ao menu? Digite 5, se quiser sair digite 0: \n");
}
