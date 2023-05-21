#include <stdio.h>
#include <stdlib.h>
float *alocar(const int n){
    float *vet;
    vet = (float *) malloc(n * sizeof(float));
    if(vet == NULL){
    printf("Nao foi alocado");
    exit(1);
    }
    return vet;
}
void output( int n, float *prova1, float *prova2){
    float media1 = 0, media2 = 0, mediaaluno = 0;
    
    for (int i = 0; i < n; i++)
    {
        printf("Insira a nota do aluno %d na prova 1: ", i + 1);
        scanf("%f", &prova1[i]); // Recebe a nota
        media1 += prova1[i];     // soma a nota à media

        printf("Insira a nota do aluno %d na prova 2: ", i + 1);
        scanf("%f", &prova2[i]);
        media2 += prova2[i];
    }

    media1 /= n;
    media2 /= n; // para saber a media da turma em cada prova

    for (int x = 0; x < n; x++)
    {
        mediaaluno = (prova1[x] + prova2[x]) / 2;                                                                         // saber a media do aluno nas duas provas
        printf("Aluno %d: Media = %.2f, Situacao = %s\n", x + 1, mediaaluno, mediaaluno >= 7 ? "Aprovado" : "Reprovado"); // saber se foi aprovado ou nao!
    }
    printf("Media da turma na prova 1: %.2f\n", media1);
    printf("Media da turma na prova 2: %.2f\n", media2);

}
int main()
{
    int n;
    float *prova1, *prova2;
    printf("insira o numero de alunos");
    scanf("%d", &n); // recebe o numero de alunos
    prova1 = alocar(n);
    prova2 = alocar(n);// alocacao dinamica para os vetores
    output(n, prova1, prova2);
    free(prova1);
    free(prova2); // limpeza de memoria
    return 0;
}