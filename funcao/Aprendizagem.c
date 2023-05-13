#include <stdio.h>
#include <stdlib.h>

void multiplicacao(int *, const int);

int main(void)
{
    int num, n;
    printf("Insira o numero que deseja multiplicar e o numero de multiplicacoes: ");
    scanf("%d %d", &num, &n);
    multiplicacao(&num, n);
    printf("A multiplicacao e: %d", num);
    return 0;
}
void multiplicacao(int *x, int n)
{
    *x = n * *x;
}