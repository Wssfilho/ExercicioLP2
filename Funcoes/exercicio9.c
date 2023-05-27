#include <stdio.h>
#include <stdlib.h>

// Função para verificar se um número é primo
int eh_primo(int n)
{
    // Números menores ou iguais a 1 não são primos
    if (n <= 1)
        return 0;
    // Verifica se n é divisível por qualquer número menor que sua raiz quadrada
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    // Se nenhum divisor foi encontrado, n é primo
    return 1;
}

int main(void)
{
    int n;
    // Solicita ao usuário que insira o limite
    printf("Insira o tamanho da impressao de numeros primos: ");
    scanf("%d", &n);
    // Verifica cada número de 1 a n
    for (int i = 1; i <= n; i++)
    {
        // Se eh_primo retornar verdadeiro, imprime o número
        if (eh_primo(i))
            printf("%d\n", i);
    }
    return 0;
}