#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float x, y, z;
} Tponto;

int main(void)
{
    Tponto p;
    int A, B, C, D;
    printf("INSIRA AS COORDENADAS: ");
    scanf("%d %d %d %d", &A, &B, &C, &D);
    printf("INSIRA OS PONTOS X, Y, Z");
    scanf("%f %f %f", &p.x, &p.y, &p.z);
    if (A * p.x + B * p.y + C * p.z == D)
    {
        printf("PERTENCE AO PLANO A B C");
    }
    else
    {
        printf("NAO PERTENCE");
    }
    return 0;
}