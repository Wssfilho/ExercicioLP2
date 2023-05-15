#include <stdio.h>

int perfeito(int num)
{
    int soma = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            soma += i;
        }
    }
    return soma == num;
}

int main(void)
{
    printf("Números perfeitos entre 1 e 100:\n");
    for (int i = 1; i <= 100; i++)
    {
        if (perfeito(i))
        {
            printf("%d = 1", i);
            for (int j = 2; j <= i / 2; j++)
            {
                if (i % j == 0)
                {
                    printf(" + %d", j);
                }
            }
            printf("\n");
        }
    }
    return 0;
}