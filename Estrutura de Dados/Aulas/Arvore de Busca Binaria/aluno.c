
#include "aluno.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct aluno
{
    int matricula;
    char *nome;
    float cr;
};

Aluno *InicializaAluno(int matricula, char *nome, float cr)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    aluno->matricula = matricula;
    aluno->cr = cr;
    aluno->nome = strdup(nome);
    return aluno;
}

void ImprimeAluno(Aluno *aluno)
{
    printf(" Matricula: %d, nome: %s, CR: %.2f\n", aluno->matricula, aluno->nome, aluno->cr);
}

int RetornaMatricula(Aluno *aluno)
{
    return aluno->matricula;
}

char *RetornaNome(Aluno *aluno)
{
    return aluno->nome;
}

float RetornaCR(Aluno *aluno)
{
    return aluno->cr;
}

void DestroiAluno(Aluno *aluno)
{
    free(aluno->nome);
    free(aluno);
}
