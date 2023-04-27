#include <stdio.h>
#include <stdlib.h>
//TERMINAR
typedef struct
{
    char nome[30];
    int ganhos;
    int empate;
    int perdas;
    int cartAm;
    int cartVer;
    int golAf;
    int golCont;
    float saldo;
    int pontos;

} Torneio;
int main(void)
{
    Torneio *equipe;
    int n;
    printf("DIGITE A QUANTIDADE DE EQUIPES");
    scanf("%d", &n);
    fflush(stdin);
    equipe = malloc(n * sizeof(Torneio));
    if (equipe == NULL)
    {
        exit(-1);
    }

    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("DIGITE O NOME da equipe %d: \n", i + 1);
        gets(equipe[i].nome);
        fflush(stdin);
        printf("DIGITE O NUMERO DE JOGOS GANHOS: \n");
        scanf("%d", &equipe[i].ganhos);
        printf("DIGITE O NUMERO DE JOGOS empatados: \n");
        scanf("%d", &equipe[i].empate);
        printf("DIGITE O NUMERO DE JOGOS perdidos: \n");
        scanf("%d", &equipe[i].perdas);
        printf("DIGITE O NUMERO DE CARTAO AMARELO: \n");
        scanf("%d", &equipe[i].cartAm);
        printf("DIGITE O NUMERO DE CARTAO VERMELHO: \n");
        scanf("%d", &equipe[i].cartVer);
        printf("DIGITE O NUMERO DE GOLS A FAVOR: \n");
        scanf("%d", &equipe[i].golAf);
        printf("DIGITE O NUMERO DE GOLS RECEBIDOS: \n");
        scanf("%d", &equipe[i].golCont);
        equipe[i].pontos = (equipe[i].ganhos * 3) + (equipe[i].empate * 1);
        equipe[i].saldo = equipe[i].golAf - equipe[i].golCont;
    }
    int maiorPontos = 0;
    int maiorGols = 0;
    int menosGolsRecebidos = 0;

    for (int i = 0; i < n; i++)
    {
        if (equipe[i].pontos > equipe[maiorPontos].pontos)
        {
            maiorPontos = i;
        }
        if (equipe[i].golAf > equipe[maiorGols].golAf)
        {
            maiorGols = i;
        }
        if (equipe[i].golCont < equipe[menosGolsRecebidos].golCont)
        {
            menosGolsRecebidos = i;
        }
    }
    printf("Equipe com mais pontos foi %s\n", equipe[maiorPontos].nome);
    printf("Equipe com melhor ataque foi %s\n", equipe[maiorGols].nome);
    printf("Equipe com melhor defesa foi %s\n", equipe[menosGolsRecebidos].nome);



    free(equipe);
    return 0;
}