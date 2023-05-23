#include <stdio.h>
#include <stdlib.h>
//look at the comments in the notebook
int fibonnaci(int n);
int main(void)
{
    int n, m;
    printf("Insira os termos n & m respectivamente: ");
    scanf("%d %d", &n, &m);
    if (n > m)
        exit(-1);
    for(int i = n; i <= m; i++)
        printf("%d", fibonnaci(i));
    printf("\n");
    return 0;
}
int fibonnaci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fibonnaci(n - 1) + fibonnaci(n - 2);
}
/*int fib(int n)
{
    if (n == 1 || n == 2) 
        return 1;
    return fib(n - 1) + fib(n - 2);
}*/