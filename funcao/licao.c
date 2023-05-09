#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int multiplicacao(int n1, int n2);
int raiz(int x)
{
    int retorno_raiz;
    retorno_raiz = sqrt(x);
    return(retorno_raiz);
}
int main(void)
{
    int v1, v2, resultado, result_raiz;
    printf("Insirao primeiro valor: ");
    scanf("%d", &v1);
    printf("Insirao o segundo valor: ");
    scanf("%d", &v2);
    result_raiz = raiz(v1);
    // chamar a funcao e recebe o retorno
    resultado = multiplicacao(v1, v2);
    printf("Resultado: %d\n", resultado);
    printf("Resultado da raiz: %d\n", result_raiz);
    return 0;
}
int multiplicacao(int n1, int n2)
{
    int result;
    result = n1 * n2;
    return (result);
} // multiplica recebe n1 e n2 e retorna um inteiro
