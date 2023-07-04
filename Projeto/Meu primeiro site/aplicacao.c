#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[40];
    int idade;
} Tpessoa;
Tpessoa *allocar();
void menu(int *);
int main(void)
{
    int opcao;
    Tpessoa *dado;
    dado = allocar();
    switch(opcao)
    {
        
    }
}
Tpessoa *allocar()
{
    Tpessoa *temp;
    temp = malloc(sizeof(Tpessoa));
    if (temp == NULL)
        printf("Nao foi alocado");
        exit(-1);
    return temp;
}