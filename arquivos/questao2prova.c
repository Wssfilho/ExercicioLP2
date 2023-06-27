#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    int n, i;
    int *vetor;

    arquivo = fopen("dados.dor", "r+b");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fread(&n, sizeof(int), 1, arquivo);
    vetor = (int *) malloc(n * sizeof(int));
    fread(vetor, sizeof(int), n, arquivo);

    printf("Elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    fseek(arquivo, sizeof(int), SEEK_SET);
    for (i = 0; i < n; i++) {
        vetor[i] *= 2;
        fwrite(&vetor[i], sizeof(int), 1, arquivo);
    }

    free(vetor);
    fclose(arquivo);
    return 0;
}
