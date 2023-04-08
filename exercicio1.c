#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n, *ptrn;
    printf("insira um numero");
    scanf("%f", &n); //recebe um float

    ptrn = &n; //ptrn aponta para o endereco do n
    printf(" Direta %f\n", n); //imprime n
    printf("ednereço da var apontada %p\n", ptrn); //imprim o endereco
    printf("Indireta %f\n", *ptrn); //imprime o conteudo

    return 0;
}