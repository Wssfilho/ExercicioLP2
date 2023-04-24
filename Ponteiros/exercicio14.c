#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[100];
    char c;
    int count = 0;
    char *ptr;

    printf("Digite uma string: ");
    gets(str);

    printf("Digite um caractere: ");
    scanf("%c", &c);

    ptr = str;
    while (*ptr != '\0') {
        if (*ptr == c) {
            count++;
        }
        ptr++;
    }

    printf("O caractere '%c' aparece %d vezes na string.\n", c, count);

    return 0;
}