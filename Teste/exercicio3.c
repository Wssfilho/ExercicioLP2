#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float calchip(const float, const float);

int main(void)
{
    float oposto, adjecente;
    printf("Insira os dois catetos: ");
    scanf("%f %f", &oposto, &adjecente);
    printf("O calculo do cumprimento hipotenusa e: %.2f", calchip(oposto, adjecente));
}
float calchip(const float oposto, const float adjacente)
{
    return sqrt((oposto * oposto) + (adjacente * adjacente));
}