#include <stdio.h>
#include <stdlib.h>
#define n 10

int main(void)
{

    float kms[n] = {240.5, 300.0, 189.6, 310.6, 280.7, 216.9, 199.4, 160.3, 177.4, 192.3};
    float Lts[n] = {10.3, 15.6, 8.7, 14, 16.3, 15.7, 14.9, 10.7, 8.3, 8.4};
    float kpl[n];
    float *pKpL = kpl;
    float *pKms = kms;
    float *pLts = Lts;
    for (int i = 0; i < n; i++)
    {
        *(pKpL + i) = *(pKms + i) / *(pLts + i);
        printf("KpL[%d] = %.2f\n", i, *(pKpL + i));
    }
    return 0;
}