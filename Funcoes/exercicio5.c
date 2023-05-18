#include <stdio.h>
#include <stdlib.h>
int Potencialint(const int, const int);
int main(void)
{
    int base, expoente, resultado;
    printf("Insira o numero da base e do expoente: ");
    scanf("%d %d", &base, &expoente);
    resultado = Potencialint(base, expoente);
    printf("%d\n", resultado);
}
int Potencialint(const int base, const int expoente)
{
    int result = 1;
    for (int i = 0; i < expoente; i++)
    {
        result *= base;
    }
    return result;
}