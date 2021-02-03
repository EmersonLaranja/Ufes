#include "aluno.h"
#define MEDIA 7
//

int ComparaNomes(const void *a, const void *b)
{
  return strcmp(((Aluno *)a)->nome, ((Aluno *)b)->nome);
}

int main(int argc, char const *argv[])
{
  FILE *entrada = fopen(argv[1], "r");

  if (!entrada)
  {
    printf("File does not exist! Try again typing the filename too\n");
    return 0;
  }

  char *nomeAuxiliar;
  int tamVetor, notaAuxiliar;
  fscanf(entrada, "%d", &tamVetor);

  Aluno vetorAlunos[tamVetor];

  for (int i = tamVetor - 1; i >= 0; i--)
  {
    fscanf(entrada, "%d %s", &vetorAlunos[i].nota, vetorAlunos[i].nome);
  }

  fclose(entrada);

  FILE *saida = fopen("saida.csv", "w");

  qsort(vetorAlunos, tamVetor, sizeof(Aluno), ComparaNomes);

  for (int i = 0; i < tamVetor; i++)
  {
    if (vetorAlunos[i].nota >= MEDIA)
      printf("%s: %d\n", vetorAlunos[i].nome, vetorAlunos[i].nota);
  }

  fclose(saida);
  return (0);
}