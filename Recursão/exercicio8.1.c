#include <stdio.h>
#include <stdlib.h>
void busca(int n); // declaracao da funcao que recebe um inteiro e nao retorna nada
int main(void)
{
    int val;
    printf("Insira o numero que deseja converter: "); // entradad de dados
    scanf("%d", &val);
    busca(val); // chamadas a funcao
    return 0;
}
void busca(int n)
{
    //if (n >= 2)       // como eu falei em sala de aula, esse algoritimo ele suprime o zero que aparece primeiro
    //    busca(n / 2); // no algoritimo abaixo o returno seria 3 = 011, nesse sai 3 = 11;
    //printf("%d", n % 2);

    
    if (n > 0)
       busca(n / 2);
    printf("%d", n % 2); 
}