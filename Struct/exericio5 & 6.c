#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Ponto;

int main()
{
    Ponto p;
    do
    {
        printf("Digite as coordenadas do ponto (x y): ");
        scanf("%d %d", &p.x, &p.y);
        if (p.x == 0 || p.y == 0)
        {
            printf("Ponto sobre os eixos\n");
        }
        else if (p.x > 0 && p.y > 0)
        {
            printf("O ponto pertence ao quadrante I\n");
        }
        else if (p.x < 0 && p.y > 0)
        {
            printf("O ponto pertence ao quadrante II\n");
        }
        else if (p.x < 0 && p.y < 0)
        {
            printf("O ponto pertence ao quadrante III\n");
        }
        else if (p.x > 0 && p.y < 0)
        {
            printf("O ponto pertence ao quadrante IV\n");
        }
    } while (p.x != 0 || p.y != 0);
    return 0;
}