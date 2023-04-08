#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;    // x é zero
    x = 4;     // x recebe 4
    (*p)++;    // y = 1
    --x;       // x = 3
    (*p) += x; // apontado por *p é 4 = y
    printf("o valor de x é %d e o de y é %d", x, y);
    return 0;
}