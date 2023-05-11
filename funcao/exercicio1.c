#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *binario(int);

int main(void)
{
    int ent;
    printf("insira o numero que deseja transformar: ");
    scanf("%d", &ent);
    char *num = binario(ent);
    printf("Essa e a conversao: %s", num);
    free(num);
    return 0;
}
char *binario(int num)
{
    char binario[100];
    int i = 0;
    while (num > 0)
    {
        binario[i] = (num % 2) + '0';
        num = num / 2;
        i++;
    }
    binario[i] = '\0';
    strrev(binario);
    char *result = malloc(strlen(binario) + 1);
    strcpy(result, binario);
    return result;
}