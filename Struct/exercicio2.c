//depois eu comento
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
    char nome[50];
    int idade;
    int telefone;
    char sexo[20];
    char email[20];
} Aluno;
int main(void)
{
    Aluno aluno1, *ptrn_aluno1;
    ptrn_aluno1 = &aluno1;
    printf("INSIRA O NOME: ");
    gets(ptrn_aluno1->nome);
    printf("\nINSIRA A IDADE");
    scanf("%d", &(ptrn_aluno1->idade)); //receber dados com scanf
    printf("\nINSIRA A  TELEFONE");
    scanf("%d", &(ptrn_aluno1->telefone));
    fflush(stdin); //precisei limpar porque estou usando scanf dps uso gets
    printf("\nINSIRA O sexo: ");
    gets(ptrn_aluno1->sexo);
    printf("\nINSIRA O EMAIL: ");
    gets(ptrn_aluno1->email);
    system("clear || cls");
    printf("Seu nome e: %s\n", ptrn_aluno1->nome);
    printf("Sua idade e: %d\n", ptrn_aluno1->idade);
    printf("Seu telefone e: %d\n", ptrn_aluno1->telefone);
    printf("Seu sexo e: %s\n", ptrn_aluno1->sexo);
    printf("Seu email e: %s\n", ptrn_aluno1->email);

}