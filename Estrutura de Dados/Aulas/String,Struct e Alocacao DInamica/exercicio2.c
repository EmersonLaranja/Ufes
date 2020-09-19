#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
  char *nome;
  int matricula;
  float p1;
  float p2;
  float p3;
};

typedef struct aluno Aluno;

char *leNome(void)
{
  char str[91];
  scanf(" %90[^\n]", str);
  return strdup(str);
}

void ImprimeAluno(Aluno *aluno)
{
  printf("Nome:%s Matricula:%d P1:%.2f P2:%.2f P3:%.2f\n",
         aluno->nome, aluno->matricula, aluno->p1, aluno->p2, aluno->p3);
}

void imprime_aprovados(int n, Aluno **turma)
{
  float media = 0;
  for (int i = 0; i < n; i++)
  {
    media = (turma[i]->p1 + turma[i]->p2 + turma[i]->p3) / 3;
    if (media >= 5)
      ImprimeAluno(turma[i]);
  }
}
float media_turma(int n, Aluno **turma)
{
  float somaDasNotas = 0;
  float somatorioNotasDaTurma = 0;
  for (int i = 0; i < n; i++)
  {
    somaDasNotas = turma[i]->p1 + turma[i]->p2 + turma[i]->p3;
    somatorioNotasDaTurma += somaDasNotas;
  }
  return (somatorioNotasDaTurma / n);
}

void LiberaTurma(int n, Aluno **turma)
{
  for (int i = 0; i < n; i++)
  {
    free(turma[i]->nome);
    free(turma[i]);
  }
  free(turma);
}

int main()
{
  int n;
  float media;

  printf("Digite um numero de alunos: ");
  scanf("%d", &n);
  Aluno **turma = (Aluno **)malloc(n * sizeof(Aluno *));

  for (int i = 0; i < n; i++)
  {
    turma[i] = (Aluno *)malloc(sizeof(Aluno));
    printf("\nDigite o nome do aluno: ");
    turma[i]->nome = leNome();
    printf("Digite a matricula do aluno: ");
    scanf("%d", &turma[i]->matricula);
    printf("Digite as 3 notas do aluno (P1,P2,P3): ");
    scanf("%f %f %f", &turma[i]->p1, &turma[i]->p2, &turma[i]->p3);
  }

  printf("\nAlunos da Turma\n");
  for (int i = 0; i < n; i++)
  {
    ImprimeAluno(turma[i]);
  }

  printf("\nAlunos aprovados:\n");
  imprime_aprovados(n, turma);

  media = media_turma(n, turma);
  printf("Media da turma: %.2f\n", media);

  LiberaTurma(n, turma);
  return 0;
}