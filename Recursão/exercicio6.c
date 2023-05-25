#include <stdio.h>
#include <stdlib.h>

float seqgeo(float a, float r, float n);
int main(void)
{
    float a, r;
    float n;
    printf("Insira o valor de a, r e n: ");
    scanf("%f %f %f", &a, &r, &n);
    printf("O enesimo elemento eh: %.1f", seqgeo(a, r, n));
    return 0;
}
float seqgeo(const float a, const float r, float n)
{
    if (n == 0)
        return a;
    return r * seqgeo(a, r, n - 1);
}