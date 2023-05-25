#include <stdio.h>
#include <stdlib.h>
float potencia(float base, int expoente) // declaracao da funcao
{
    if (expoente == 0) // condicao de parada da recursao
    {
        return 1;
    }
    else if (expoente < 0) // condicao caso o expoente seja negativo
    {
        return 1 / potencia(base, -expoente);
    }
    else //condicao caso o expoente for postivo, para ser efetuado os calculos corretos sem margem de error
    {
        return base * potencia(base, expoente - 1);
    }
}
int main(void)
{
    float base; // declaracao de variaveis
    int expoente;
    printf("Insira o numero (base) e posteriormente o numero (expoente) ");
    scanf("%f %d", &base, &expoente);                                                        // coleta de dados
    printf("%.1f elevado a %d eh igual a %.1f\n", base, expoente, potencia(base, expoente)); // chamada a funcao no printf
    return 0;
}
