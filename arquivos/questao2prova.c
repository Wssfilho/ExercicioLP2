#include <stdio.h>

int main()
{
    FILE *fp;
    int n, i;
    int num;

    fp = fopen("dados.dat", "r+b");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fread(&n, sizeof(int), 1, fp);

    for (i = 0; i < n; i++)
    {
        fread(&num, sizeof(int), 1, fp);
        printf("%d ", num);
        num *= 2;
        fseek(fp, -sizeof(int), SEEK_CUR);
        fwrite(&num, sizeof(int), 1, fp);
    }

    fclose(fp);

    return 0;
}