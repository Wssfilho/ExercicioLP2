#include <stdio.h>

typedef struct
{
    float Re;
    float Im;
} TNumComp;

int main()
{
    TNumComp num1, num2, soma, subtracao;

    printf("Digite a parte real e imaginária do primeiro número complexo: ");
    scanf("%f %f", &num1.Re, &num1.Im);

    printf("Digite a parte real e imaginária do segundo número complexo: ");
    scanf("%f %f", &num2.Re, &num2.Im);

    soma.Re = num1.Re + num2.Re;
    soma.Im = num1.Im + num2.Im;

    subtracao.Re = num1.Re - num2.Re;
    subtracao.Im = num1.Im - num2.Im;

    printf("Soma: %.2f + %.2fi\n", soma.Re, soma.Im);
    printf("Subtração: %.2f + %.2fi\n", subtracao.Re, subtracao.Im);

    return 0;
}