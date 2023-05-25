#include <stdio.h>
#include <stdlib.h>
void reducao(int n);
int main(void)
{
    int n;
    printf("Insira um numero: ");
    scanf("%d", &n);
    reducao(n);
}
void reducao(int n)
{
    if(n >= 1)
        reducao(n - 1);
    printf("\n %d", n);
}