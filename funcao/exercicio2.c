#include <stdio.h>

int inverter_numero(int num)
{
    int inverso = 0;
    while (num > 0)
    {
        inverso = inverso * 10 + num % 10;
        num /= 10;
    }
    return inverso;
}

int main(void)
{
    int num = 1975;
    printf("%d\n", inverter_numero(num));
    return 0;
}