#include <stdio.h>
#include <stdlib.h>
#define N 50
void busca(int val);
int main(void)
{
    int val;
    printf("Insira o numero que deseja converter: ");
    scanf("%d", &val);
    busca(val);
    return 0;
}
void busca(int n)
{
    if (n == 0)
        return;   // como eu falei em sala de aula, esse algoritimo ele suprime o zero que aparece primeiro
    busca(n / 2); // em outro algoritimio o returno seria 3 = 011, nesse sai 3 = 11;
    printf("%d", n % 2);
}