#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int numerador;
    int denominador;
} Tracional;

int main(void)
{
    Tracional fracao[5]; // pega a fracao
    int i;               // laco
    Tracional maior;     // maior
    double valorFracao[5];

    for (i = 0; i < 5; i++)
    {
        printf("DIGITE O NUMERADOR DA FRACAO %d: ", i + 1);
        scanf("%d", &fracao[i].numerador);
        printf("DIGITE O DENOMINADOR DA FRACAO %d: ", i + 1);
        scanf("%d", &fracao[i].denominador);

        valorFracao[i] = (double)fracao[i].numerador / fracao[i].denominador;
    }
    maior = fracao[0];

    for (i = 1; i < 5; i++)
    {
        if (valorFracao[i] > valorFracao[i - 1])
        {
            maior = fracao[i];
        }
    }
    printf("A MAIOR FRACAO E: %d/%d\n", maior.numerador, maior.denominador);
    return 0;
}