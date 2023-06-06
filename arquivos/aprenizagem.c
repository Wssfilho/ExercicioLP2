#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

void inserir(FILE *arquivo) {
    Pessoa *p = (Pessoa*) malloc(sizeof(Pessoa));
    printf("Digite o nome: ");
    scanf("%s", p->nome);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    fprintf(arquivo, "%s %d\n", p->nome, p->idade);
    free(p);
}

void mostrar(FILE *arquivo) {
    system("clear || cls");
    Pessoa p;
    rewind(arquivo);
    while(fscanf(arquivo, "%s %d\n", p.nome, &p.idade) != EOF) {
        printf("Nome: %s\n", p.nome);
        printf("Idade: %d\n", p.idade);
    }
}

int main() {
    FILE *arquivo = fopen("pessoas.txt", "a+");
    int opcao;
    do {
        printf("1 - Inserir\n");
        printf("2 - Mostrar\n");
        printf("3 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                inserir(arquivo);
                break;
            case 2:
                mostrar(arquivo);
                sleep(5);
                system("clear || cls");
                break;
            case 3:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 3);
    fclose(arquivo);
    return 0;
}
