#include <stdio.h>
#include <stdlib.h>
//feito por wilson filho para estudos
int main(void)
{
    int x = 4, *ptrx, *pointer, a, b;
    ptrx = (int *) malloc(x * sizeof(int));
    if (ptrx == NULL)
    {
        printf("memoria nao alocada");
    }
    for (int i = 0; i < x; i++)
    {
        printf("insira os valores do vetor");
        scanf("%d", &ptrx[i]);
    }
    pointer = ptrx; // poiter aponta para a base do vetor
    a = *(pointer + 2); //anda o numero de casa
    printf("[%d]\n\n", *pointer);
    b = (*pointer + 3); //altera o valor do apontado somando 3;
    printf("%d\n", a);
    printf("%d\n", b);
    pointer += 2;  // move o ponteiro duas vezes pra frente
    *pointer += 4; // altera o conteudo do espaco avancado para espaco + 4; e altera o valor final
    printf("%d\n", *pointer);
    pointer -= 2;             // retorna o ponteiro pra base;
    printf("%d\n", *pointer); // imprime o ponteiro base
    *pointer *= 2; //multiplica por dois o valor do apontado
    printf("%d\n", *(pointer + 3)); // soma 3 ao conteudo sem alterar o valor (so imprime pointer +3)
    //estudar ponteiros na segunda
    for (int j = 0; j < x; j++)
    {
        printf("%d", ptrx[j]);
    }

    free(ptrx);
    return 0;
}