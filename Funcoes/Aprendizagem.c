#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    float x, y;
} TpontoPlano;

float calculopontos(TpontoPlano *estrutura);

int main(void)
{
    TpontoPlano a;
    float ponto;
    ponto = calculopontos(&a);
    printf("Os pontos que o jogador recebe e: %.1f", ponto);
    return 0;
}
float calculopontos(TpontoPlano *estrutura)
{
    float pontos = 0;
    printf("Insira os pontos x e y respectivamente: ");
    scanf("%f %f", &estrutura->x, &estrutura->y);
    float d = sqrt((estrutura->x * estrutura->x) + (estrutura->y * estrutura->y));
    if (d == 0)
        pontos = 20;
    else if (d < 10)
        pontos = 10;
    else if (d > 10 && d <= 25)
        pontos = 5;
    else if (d > 25 && d <= 50)
        pontos = 2;
    else
        pontos -= 1;
    return pontos;
}
