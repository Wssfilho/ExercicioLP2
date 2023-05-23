#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int *cont);
int main(void)
{
    int n, cont = 0;
    printf("Insira o valor de n sendo menor que 10: ");
    scanf("\n%d", &n);
    if (n > 10 || n <= 0)
        exit(-1);
    printf("O numero de somatorias foi: %d", fibonacci(n, &cont));
    return 0;
}
int fibonacci(int n, int *cont)
{
    (*cont)++;
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n - 1, cont) + fibonacci(n - 2, cont);
}