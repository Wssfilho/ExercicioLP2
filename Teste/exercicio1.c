#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *binario(int); // declara uma funcao do tipo char que retorna um ponteiro

int main(void)
{
    int ent;
    printf("insira o numero que deseja transformar: ");
    scanf("%d", &ent);                     // entrada de dados
    char *num = binario(ent);              // um ponteiro recebe a funcao que e alocada dinamicamente
    printf("Essa e a conversao: %s", num); // imprime a variavel que recebeu a funcao
    free(num);                             // libera a variavel que recebeu a funcao
    return 0;
}
char *binario(int num) // recebe um inteiro
{
    char binario[100];
    int i = 0;      // enquanto i nao acabar
    while (num > 0) // enquanto o numeoro for maior que zero ele roda o laco
    {
        binario[i] = (num % 2) + '0';
        num = num / 2;
        i++;
    }
    binario[i] = '\0';
    strrev(binario);
    char *result = malloc(strlen(binario) + 1);
    strcpy(result, binario);
    return result;
    //Explicação passo a passo do que a função faz:
    /*A função recebe um número inteiro num como argumento.
    Ela define uma variável binario para armazenar a representação binária do número e uma variável i para rastrear o índice atual na cadeia de caracteres binario.
    Enquanto num for maior que 0, a função executa os seguintes passos:
    Calcula o resto da divisão de num por 2 e armazena o resultado na posição i da cadeia de caracteres binario.
    Divide num por 2 e atualiza seu valor.
    Incrementa i.
    Depois que todas as divisões são feitas, a função adiciona o caractere nulo ao final da cadeia de caracteres binario.
    A função inverte a cadeia de caracteres binario usando a função strrev.
    A função aloca memória para armazenar a cadeia de caracteres binária e copia o conteúdo da variável binario para essa memória.
    A função retorna o ponteiro para a memória alocada contendo a representação binária do número.*/
}