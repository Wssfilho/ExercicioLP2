#include <stdio.h>

typedef struct
{
    float Re;
    float Im;
} TNumComp;

int main()
{
    TNumComp num1, num2, soma, subtracao;
    TNumComp *pnum1 = &num1, *pnum2 = &num2, *psoma = &soma, *psubtracao = &subtracao;

    printf("Digite a parte real e imaginária do primeiro número complexo: ");
    scanf("%f %f", &pnum1->Re, &pnum1->Im);

    printf("Digite a parte real e imaginária do segundo número complexo: ");
    scanf("%f %f", &pnum2->Re, &pnum2->Im);

    psoma->Re = pnum1->Re + pnum2->Re;
    psoma->Im = pnum1->Im + pnum2->Im;

    psubtracao->Re = pnum1->Re - pnum2->Re;
    psubtracao->Im = pnum1->Im - pnum2->Im;

    printf("Soma: %.2f + %.2fi\n", psoma->Re, psoma->Im);
    printf("Subtração: %.2f + %.2fi\n", psubtracao->Re, psubtracao->Im);

    return 0;
}