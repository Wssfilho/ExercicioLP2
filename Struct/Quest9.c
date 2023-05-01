#include <stdio.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
    float z;
} TPonto;

typedef struct
{
    TPonto centro;
    float raio;
} TEsfera;

int main()
{
    TEsfera esfera;
    TPonto ponto;
    float distancia;
    printf("Digite as coordenadas do centro da esfera (x y z): ");
    scanf("%f %f %f", &esfera.centro.x, &esfera.centro.y, &esfera.centro.z);

    printf("Digite o raio da esfera: ");
    scanf("%f", &esfera.raio);

    printf("Digite as coordenadas do ponto (x y z): ");
    scanf("%f %f %f", &ponto.x, &ponto.y, &ponto.z);

    distancia = sqrt ((ponto.x - esfera.centro.x) * (ponto.x - esfera.centro.x) + (ponto.y - esfera.centro.y) * (ponto.y - esfera.centro.y) + (ponto.z - esfera.centro.z) * (ponto.z - esfera.centro.z));

    if (distancia < esfera.raio)
    {
        printf("O ponto é interno à esfera.\n");
    }
    else
    {
        printf("O ponto é externo à esfera.\n");
    }

    return 0;
}

