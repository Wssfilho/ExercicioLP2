#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *val;
    int n;
    int max;
    int min;
    float media;
} TSeq;

int main()
{
    TSeq seq;
    int i, soma = 0;

    printf("Digite a quantidade de elementos da sequência: ");
    scanf("%d", &seq.n); //nos colocamos o elemento dentro da struct pois strcut é uma sequencia

    seq.val = (int *)malloc(seq.n * sizeof(int));
    if (seq.val == NULL)
    {
        printf("NAO FOI ALOCAD0");
        exit(-1);
    }

    printf("Digite os valores da sequência: ");
    for (i = 0; i < seq.n; i++)
    {
        scanf("%d", &seq.val[i]);
        soma += seq.val[i];
        if (i == 0)
        {
            seq.max = seq.val[i];
            seq.min = seq.val[i];
        }
        else
        {
            if (seq.val[i] > seq.max)
                seq.max = seq.val[i];
            if (seq.val[i] < seq.min)
                seq.min = seq.val[i];
        }
    }

    seq.media = (float)soma / seq.n;

    printf("Máximo: %d\n", seq.max);
    printf("Mínimo: %d\n", seq.min);
    printf("Média: %.2f\n", seq.media);

    free(seq.val);

    return 0;
}