#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float x, y;
} TPonto;

int main(void)
{
    TPonto P1, P2, P3;
    float A, B, C;

    printf("Digite a coordenada x do ponto 1: ");
    scanf("%f", &P1.x);
    printf("Digite a coordenada y do ponto 1: ");
    scanf("%f", &P1.y);

    printf("Digite a coordenada x do ponto 2: ");
    scanf("%f", &P2.x);
    printf("Digite a coordenada y do ponto 2: ");
    scanf("%f", &P2.y);

    printf("Digite a coordenada x do ponto 3: ");
    scanf("%f", &P3.x);
    printf("Digite a coordenada y do ponto 3: ");
    scanf("%f", &P3.y);

    A = sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y));
    B = sqrt((P3.x - P2.x) * (P3.x - P2.x) + (P3.y - P2.y) * (P3.y - P2.y));
    C = sqrt((P1.x - P3.x) * (P1.x - P3.x) + (P1.y - P3.y) * (P1.y - P3.y));

    printf("\nA = %.2f, B = %.2f, C = %.2f\n", A, B, C);

    if (A > B && A > C)
    {
        if (A * A == (B * B) + (C * C))
            printf("É um triângulo retângulo!");
        else
            printf("Não é um triângulo retângulo!!");
    }
    else if (B > A && B > C)
    {
        if (B * B == (A * A) + (C * C))
            printf("É um triângulo retângulo!");
        else
            printf("Não é um triângulo retângulo!!");
    }
    else if (C > B && C > A)
    {
        if (C * C == (B * B) + (A * A))
            printf("É um triângulo retângulo!");
        else
            printf("Não é um triângulo retângulo!!");
    }
    return 0;
}