/*15. Escreva um programa que receba uma cadeia de caracteres e informe:
a) a quantidade de vogais,
b) a quantidade de d ́ıgitos,
c) e a quantidade de caracteres em branco (espa ̧cos, tabula ̧c ̃ao e nova linha).
Utilize aritm ́etica de ponteiros para acessar os elementos da cadeia de caracteres.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Biblioteca para manipular caracteres

#define N 200

int main(void)
{
    char nome[N], *ptrnome = NULL;
    int vogais = 0;
    int i, tamanho = 0, nRes = 0;

    printf("Digite uma cadeia de caracteres qualquer: ");
    gets(nome);

    ptrnome = nome; // ptrnome recebe a primeira posiçao de nome

    while (*ptrnome != '\0')
    { // contador vai incrementando mais um, para o ponteiro se mover pelos caract da str.
        tamanho++;
        ptrnome++;
    }

    ptrnome = nome;

    for (i = 0; i < tamanho; i++)
    { // conta as vogais
        if (tolower(*ptrnome) == 'a' || tolower(*ptrnome) == 'e' || tolower(*ptrnome) == 'i' || tolower(*ptrnome) == 'o' || tolower(*ptrnome) == 'u')
        {
            vogais++;
        }

        ptrnome++;
    }

    ptrnome = nome;

    while (*ptrnome != '\0')
    { // conta a quantidade de tabulaçaõ, espaço em branco e quebra de linha
        ptrnome++;
        if (*ptrnome == ' ' || *ptrnome == '\t' || *ptrnome == '\n')
        {
            ++nRes;
        }
    }

    printf("A quantide de vogais e [%i]\n", vogais);
    printf("A quantide de digitos e [%i]\n", tamanho);
    printf("A quantide de brancos e [%i]\n", nRes);

    return 0;
}