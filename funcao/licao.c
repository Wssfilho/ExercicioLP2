#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int multiplicacao(int n1, int n2);
int main(void)
{
    int v1, v2, resultado;
    printf("Insirao primeiro valor: ");
    scanf("%d", &v1);
    printf("Insirao o segundo valor: ");
    scanf("%d", &v2);

    // chamar a funcao e recebe o retorno
    resultado = multiplicacao(v1, v2);
    printf("Resultado: %d\n", resultado);
    return 0;
}
int multiplicacao(int n1, int n2)
{
    int result;
    result = n1 * n2;
    return (result);
} // multiplica recebe n1 e n2 e retorna um inteiro
