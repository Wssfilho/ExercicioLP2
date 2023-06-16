#include <stdio.h>
#include <stdlib.h>
void readArq(void)
{
    int maior, menor, contador = 0, valor, soma = 0;
    float media;
    FILE *arq;
    if ((arq = fopen("bd.txt", "r")) == NULL)
    {
        printf("O arquivo nao pode ser aberto!");
        exit(1);
    }
    fscanf(arq, "%d", &valor);
    maior = valor;
    menor = valor;
    while (!feof(arq))
    {
        if (valor > maior)
        {
            maior = valor;
        }
        if (valor < menor)
        {
            menor = valor;
        }
        soma += valor;
        contador++;
        fscanf(arq, "%d", &valor);
    }

    fclose(arq);
    media = (float)soma / contador;
    printf("O valor maior %.1d\n", maior);
    printf("O valor menor %.1d\n", menor);
    printf("O valor media %.2f\n", media);
}
int main(void)
{
    readArq();  
    return 0;
}
