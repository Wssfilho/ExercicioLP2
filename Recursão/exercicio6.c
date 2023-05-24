#include <stdio.h>
#include <stdlib.h>

float seqgeo(float a, float r, int n);
int main(void)
{
    float a, r;
    int n;
    printf("Insira o valor de a, r e n: ");
    scanf("%f %f %d", &a, &r, &n);
    printf("O resultado final e: %.3f", seqgeo(a, r, n));
    return 0;
}
float seqgeo(float a, float r, int n)
{
    if (n == 0)
        return a;
    return r * seqgeo(a, r, n - 1);
}