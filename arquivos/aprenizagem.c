#include <stdio.h>
#include <stdlib.h>
void header(void);
int main(void)
{
    int opcao = 0;
    do
    {
        header();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            break;
        case 2:
            break;
        }

    } while (opcao == 0);
}
void header(void)
{
    printf("1. Inserir\n");
    printf("2. Mostrar\n");
}