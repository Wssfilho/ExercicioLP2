#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str[100];
    char *ptr;
    int count = 0;

    printf("Digite uma string: ");
    gets(str);

    ptr = str;
    while (*ptr != '\0')
    {
        count++;
        ptr++;
    }

    printf("A string tem %d caracteres. \n", count);

    return 0;
}