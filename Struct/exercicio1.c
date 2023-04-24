/*Escreva um programa que leia os dados de um aluno e os
imprima na tela. Considere os dados (nome, sobrenome, idade, telefone, sexo, email).
Utilize o operador de ponto para manipular a estrutura. */

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
    Aluno aluno1;
    printf("INSIRA O NOME: ");
    gets(aluno1.nome);
    printf("\nINSIRA A IDADE");
    scanf("%d", &aluno1.idade);
    printf("\nINSIRA A  TELEFONE");
    scanf("%d", &aluno1.telefone);
    fflush(stdin);
    printf("\nINSIRA O sexo: ");
    gets(aluno1.sexo);
    printf("\nINSIRA O EMAIL: ");
    gets(aluno1.email);
    system("clear || cls");
    printf("Seu nome e: %s\n", aluno1.nome);
    printf("Sua idade e: %d\n", aluno1.idade);
    printf("Seu telefone e: %d\n", aluno1.telefone);
    printf("Seu sexo e: %s\n", aluno1.sexo);
    printf("Seu email e: %s\n", aluno1.email);
}