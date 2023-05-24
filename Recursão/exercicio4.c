#include <stdio.h>
#include <stdlib.h>

int funcint(int n);
int main(void)
{
    int n;
    printf("Insira o valor de n: ");
    scanf("%d", &n);
    printf("a soma dos valores e: %d",funcint(n));
}
int funcint(int n)
{
    int soma = 0;
    for(int i = 1; i <=n; i++)
        soma+= i;
    return soma;
    
}