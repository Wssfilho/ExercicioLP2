#include <stdio.h>
#include <stdlib.h>
void seq(int n);
int main(void)
{
    int n;
    printf("Insira um numero: ");
    scanf("%d", &n);
    seq(n);
}
void seq(int n)
{
    if (n < 1)
    {
        return;
    }
    else
        seq(n - 1);
    printf("\n %d", n);
}