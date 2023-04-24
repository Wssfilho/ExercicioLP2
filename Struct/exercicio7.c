#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} Tponto;

int main(void)
{
    Tponto p1, p2, p3;
    float d12, d23, d31;
    printf("Innsira os valores ");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Innsira os valores ");
    scanf("%f %f", &p2.x, &p2.y);
    printf("Innsira os valores ");
    scanf("%f %f", &p3.x, &p3.y);
    d12 = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.x - p2.y) * (p1.x - p2.y));
    d23 = sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.x - p3.y) * (p2.x - p3.y));
    d31 = sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.x - p1.y) * (p3.x - p1.y));
    if (d12 > d23 && d12 > d31)
    {
        
    }

    return 0;
}