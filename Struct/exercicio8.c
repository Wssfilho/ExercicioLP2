#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float x, y, z;
    //criacao da estrutura com os pontos
} Tponto; 

int main(void)
{
    Tponto p; //declarando variavel do tipo estrutura
    int A, B, C, D; //declarando variaveis
    printf("INSIRA AS COORDENADAS: "); //entrada de dados
    scanf("%d %d %d %d", &A, &B, &C, &D); //entrada de dados

    printf("INSIRA OS PONTOS X, Y, Z");
    scanf("%f %f %f", &p.x, &p.y, &p.z);

    if (A * p.x + B * p.y + C * p.z == D)
    {
        printf("PERTENCE AO PLANO A B C"); //if e else dos calculos que a questao pede e ja da a equacao
    }
    else
    {
        printf("NAO PERTENCE");
    }
    return 0;
}