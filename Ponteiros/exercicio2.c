#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1, b = 2, c = 3;
    int *ptrna, *ptrb, *ptrc; //ponteiros para inteiros

    ptrna = &a;
    ptrb = &b; //os ponteiros aponta para o endereço das vars citadas
    ptrc = &c;

    printf("%d\n", *ptrna);
    printf("%d\n", *ptrb); //imprime o conteudo da variavel apontada por um ponteiro
    printf("%d\n", *ptrc);
    return 0;
}