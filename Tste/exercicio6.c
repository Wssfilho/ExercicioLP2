#include <stdio.h>

int multiplo(int num1, int num2)
{
    return num2 % num1 == 0;
}

int main(void)
{
    int n;
    printf("Digite o número de duplas: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num1, num2;
        printf("Digite a primeira dupla: ");
        scanf("%d %d", &num1, &num2);
        if (multiplo(num1, num2))
        {
            printf("%d eh múltiplo de %d\n", num2, num1);
        }
        else
        {
            printf("%d nao é múltiplo de %d\n", num2, num1);
        }
    }
    return 0;
}