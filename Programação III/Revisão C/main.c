#include "aluno.h"
#define TAM 50

static void LiberaVetorAlunos(Aluno **vetor, int tamanhoVetor)
{
  for (int i = 0; i < tamanhoVetor; i++)
  {
    LiberaAluno(vetor[i]);
  }
}

int ComparaNomes(const void *a, const void *b)
{
  int r = strcmp(RetornaNome((Aluno *)a), RetornaNome((Aluno *)b));

  if (r == 0)
    return 0;
  else
  {
    if (r < 0)
      return -1;
    else
      return 1;
  }
}

int main(int argc, char const *argv[])
{
  FILE *entrada = fopen(argv[1], "r");

  if (!entrada)
  {
    printf("File does not exist! Try again typing the filename too\n");
    return 0;
  }

  Aluno *vetorAlunos[TAM];
  char nomeAuxiliar[TAM];
  float notaAuxiliar;
  int i = 0;

  while (fscanf(entrada, "%s %f", nomeAuxiliar, &notaAuxiliar) != EOF)
  {

    vetorAlunos[i] = InicializaAluno(nomeAuxiliar, notaAuxiliar);
    i++;
  }
  fclose(entrada);

  FILE *saida = fopen("saida.csv", "w");

  qsort(vetorAlunos, i, sizeof(Aluno **), ComparaNomes);

  for (int j = 0; j < i; j++)
  {
    float nota = RetornaNota(vetorAlunos[j]);

    if (nota < 7)
    {
      fprintf(saida, "%s,%.2f,Prova Final\n", RetornaNome(vetorAlunos[j]), nota);
    }
    else
    {
      fprintf(saida, "%s,%.2f,Aprovado\n", RetornaNome(vetorAlunos[j]), nota);
    }
  }

  LiberaVetorAlunos(vetorAlunos, i);
  return 0;
}
