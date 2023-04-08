#include <stdio.h>
#include <stdlib.h>

int main()
{
    char key, choice;
    int num, count;
    long int date;
    float yield;
    double price;

    //a)
    printf("Endereço de key: %p\n", &key);
    printf("Endereço de choice: %p\n", &choice);
    printf("Endereço de num: %p\n", &num);
    printf("Endereço de count: %p\n", &count);
    printf("Endereço de date: %p\n", &date);
    printf("Endereço de yield: %p\n", &yield);
    printf("Endereço de price: %p\n", &price);
    //b) 
    //c
    printf("\nTamanho de char: %d bytes\n", sizeof(char));
    printf("Tamanho de int: %d bytes\n", sizeof(int));
    printf("Tamanho de long int: %li bytes\n", sizeof(long int));
    printf("Tamanho de float: %f bytes\n", sizeof(float));
    printf("Tamanho de double: %lf bytes\n", sizeof(double));

}