#include <stdio.h>
#include <math.h>

typedef struct
{
    float x;
    float y; //struct para definir os pontos
    float z;
} TPonto;

typedef struct
{
    TPonto centro; //struct para definir o raio e chamar a estrutura acima
    float raio;
} TEsfera;

int main()
{
    TEsfera esfera; //deckaração de variaveis do tipo estrutura
    TPonto ponto;
    float distancia;
    printf("Digite as coordenadas do centro da esfera (x y z): "); //entrada de dados
    scanf("%f %f %f", &esfera.centro.x, &esfera.centro.y, &esfera.centro.z); //entrada de dados

    printf("Digite o raio da esfera: "); //entrada de dados
    scanf("%f", &esfera.raio);

    printf("Digite as coordenadas do ponto (x y z): ");
    scanf("%f %f %f", &ponto.x, &ponto.y, &ponto.z); //entrada de dados

    distancia = sqrt ((ponto.x - esfera.centro.x) * (ponto.x - esfera.centro.x) + (ponto.y - esfera.centro.y) * (ponto.y - esfera.centro.y) + (ponto.z - esfera.centro.z) * (ponto.z - esfera.centro.z));
    //distancia recebe a funcao sqrt (utilizei metodos matematicos para nao precisar usar a funcao pow)
    if (distancia < esfera.raio)
    {
        printf("O ponto é interno à esfera.\n");
    }
    else //if e else para dizer ao usuario se o ponto é externo ou interno
    {
        printf("O ponto é externo à esfera.\n");
    }
    //fim
    return 0;
}

