#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int v[5] = {1, 2, 3, 4, 5}, i;
    int *Ptrv;

    Ptrv = v;
    printf("%d\n", *Ptrv);
    Ptrv += 4;
    printf("%d\n", *Ptrv);
    for (i = 0; i < 4; i++)
    {
        Ptrv--;
        printf("%d\n", *Ptrv);
    }
    system("PAUSE");
    return 0;
}