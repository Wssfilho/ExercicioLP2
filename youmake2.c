#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, *p = NULL;
    p = &x; //o certo seria inicializar o poneiro!
    x = 10;
    *p = x;
    printf("%d", *p);
    return 0;
}