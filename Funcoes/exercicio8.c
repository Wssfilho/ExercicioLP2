#include <stdio.h>
#include <stdlib.h>
int eh_primo(int n) //funcao para determinar se um numero e primo
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++) //condicao para achar o numero primo
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(void) //comeco da funcao principal
{
    for (int i = 1; i <= 1000; i++)
    {
        if (eh_primo(i)) //chamada da funcao em que vai verificar todos os numeros entre 1 e 1000, evia parametro em i pra funcao e retorna sim ou nao, sim sim, imprime, se nao, nao imprime;
            printf("%d\n", i);
    }
    return 0;
}