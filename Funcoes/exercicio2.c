#include <stdio.h>
#include <string.h>
#include <math.h>

int BinarioToDecimal(char *binario)
{
    int decimal = 0;
    int tamanho = strlen(binario);
    for (int i = 0; i < tamanho; i++)
    {
        if (binario[tamanho - i - 1] == '1')
        {
            decimal += pow(2, i);
        }
    }
    return decimal;
}

int main()
{
    char binario[50];
    printf("Insira os numeros em decimal: ");
    scanf("%[^\n]s%*c", binario);
    printf("%d\n", BinarioToDecimal(binario));
    return 0;
}
