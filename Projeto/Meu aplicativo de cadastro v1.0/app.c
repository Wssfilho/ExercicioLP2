#include <stdio.h>
#include <stdlib.h>
//ou bem tu faz um codigo ingles ou portugues!
typedef struct
{
    char nome[30];
    int idade;
    float nota;

} Tdado;
void menu(void);
void choose(int *);
Tdado *allc(void);
void inserir(Tdado *);
//void colcarq(Tdado *);
//******MAIN********
int main(void)
{
    menu();
    return 0;
}
//******MAIN********
void inserir(Tdado *dado)
{
    scanf("%*c");
    printf("Insira o nome:");
    scanf("%[^\n]s", dado->nome);
    scanf("%*c");
    printf("Insira sua idade: ");
    scanf("%d", &dado->idade);
    printf("Insira sua nota: ");
    scanf("%f", &dado->nota);
}
void choose(int *opcao)
{
    Tdado *dado;
    dado = allc(); //allocacao dinamica
    do
    {
        switch (*opcao)
        {
        case 1:
            inserir(dado);
            break;
        default:
            break;
        }
        menu();
    } while (opcao != 0);
    
    free(dado);
}
Tdado *allc(void)
{
    Tdado *temp;
    temp = (Tdado *) malloc(sizeof(Tdado));
    if(temp == NULL)
    {
        printf("A alocacao foi mal sucedida");
        exit(-1);
    }
    return temp;
}
void menu(void)
{
    int opcao;
    printf("----Sistema de cadastro 1.0----\n\n");
    printf("1. Inserir\n");
    printf("2. Mostrar\n");
    // printf()
    // printf()
    // printf()
    // printf()
    printf("Escolha uma das opcoes: ");
    scanf("%d", &opcao);
    while(opcao > 5 || opcao < 0)
    {
        printf("Escolha a opcao correta: ");
        scanf("%d", &opcao);
    }
    choose(&opcao);
    
}