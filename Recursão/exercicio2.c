#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, soma = 0; //declaracao das vars
    printf("Insira os valores de a & b respectivamente: ");
    scanf("%d %d", &a, &b); //pedindo os valores
    scanf("%*c"); //limpando buffer de maneira manual (aprendido em LPI)
    if (a < 0 || b < 0)
        exit(-1);   //condicao se for menor que 0
    for (int i = 0; i < b; i++)
        soma += a;
    printf("A avaliacao eh: %d", soma);
    return 0;
}