#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void gravar(void)
{
    FILE *fp; //criacao de um ponteiro para file
    char str[100]; // variavel com uma cadeia de caracteres
    fp = fopen("temp.dat", "wb"); //criacao do arquivo
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1); //verificar se o arquivo nao é nulo
    }
    printf("Digite uma cadeia de caracteres: "); //recebimento da cadeia de caracteres do usuario
    fgets(str, 100, stdin);
    fwrite(str, sizeof(char), strlen(str), fp); //escrita no arquivo com str para contar os caracteres e nao escrever no arquivo alem do tamanho necessario
    fclose(fp);
}
void mostrar(void)
{
    char ch;
    FILE *fp;
    fp = fopen("temp.dat", "rb"); //abertura do arquivo
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n"); //fechamento do arquivo
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF) //enquanto o char estiver recebendo o char do arquivo e nao for o final ele vai ficar mostrando
    {
        printf("%c", ch); 
        sleep(1); //funcao sleep para ele mostrar uma variavel por vez
    }
    fclose(fp);
}
int main(void)
{
    gravar(); //chamadas a funcao
    mostrar();
    return 0;
}
