#include <stdio.h>
#include <stdlib.h>
int somatorio(int n)
{
    if (n == 0)
        return 0;
    return n + somatorio(n - 1);
}
int main(void)
{
    int n;
    printf("Insira um numero ");
    scanf("%d", &n);
    printf("%d", somatorio(n));
}