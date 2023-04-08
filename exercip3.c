#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 1, b = 2, c = 3;
    int *ptrna, *ptrb, *ptrc;

    ptrna = &a;

    printf("%d\n", *ptrna);
    ptrb = &b;
    printf("%d\n", *ptrb);
    ptrc = &c;

    printf("%d\n", *ptrc);
    return 0;
}