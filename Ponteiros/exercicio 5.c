#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 2;
    float *prova1 = malloc(n * (sizeof(float)));
    float *prova2 = malloc(n * sizeof(float));
    if (prova1 == NULL || prova2 == NULL)
    {
        printf("memoria nao alocada");
        exit(-1);
    }

    float media1 = 0, media2 = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Insira a nota do aluno %d na prova 1: ", i + 1);
        scanf("%f", &prova1[i]);
        media1 += prova1[i];

        printf("Insira a nota do aluno %d na prova 2: ", i + 1);
        scanf("%f", &prova2[i]);
        media2 += prova2[i];
    }

    media1 /= n;
    media2 /= n;

    for (int x = 0; x < n; x++)
    {
        float mediaaluno = (prova1[x] + prova2[x]) / 2;
        printf("Aluno %d: Media = %.2f, Situacao = %s\n", x + 1, mediaaluno, mediaaluno >= 7 ? "Aprovado" : "Reprovado");
    }
    printf("Media da turma na prova 1: %.2f\n", media1);
    printf("Media da turma na prova 2: %.2f\n", media2);

    free(prova1);
    free(prova2);
}