#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void gravar(void)
{
    FILE *fp;
    char str[100];
    fp = fopen("temp.dat", "w");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    printf("Digite uma cadeia de caracteres: ");
    fgets(str, 100, stdin);
    fprintf(fp, "%s", str);
    fclose(fp);
}
void mostrar(void)
{
    char ch;
    FILE *fp;
    fp = fopen("temp.dat", "r");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
        sleep(1);
    }
    fclose(fp);
}
int main(void)
{
    gravar();
    mostrar();
    return 0;
}
