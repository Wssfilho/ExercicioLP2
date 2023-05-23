#include <stdio.h>
#include <stdlib.h>
//existe algum padrão: Sim, eles seguem o mesmo if para a condição ==1 || ==2
//e eu usei uma variavel passada por referencia para contar o numero de interações
//a variavel aqui fica no comeco do laco for, no exercicio a fica no comeco da funcao
//para que em cada interação ela possa ser atualizada;
int fibonnaciint(int n, int *contador);
int main(void)
{
    int n, contador = 0;
    printf("insira valor de n: ");
    scanf("\n%d", &n);
    scanf("%*c");
    if (n < 0 || n > 10)
        exit(-1);
    printf("O numero de somas e: %d", fibonnaciint(n, &contador));
    return 0;
}
int fibonnaciint(int n, int *contador)
{
    int f1, f2, f;
    if (n == 1 || n == 2)
        return 1;
    f1 = f2 = 1;
    for (int i = 2; i < n; i++)
    {
        (*contador)++;
        f = f1 + f2;
        f2 = f1;
        f1 = f;
    }
    return f;
}
