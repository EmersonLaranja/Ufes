#include "aluno.h"
#define MEDIA 7
#define TAM_NOME 20

int main(int argc, char const *argv[])
{
  FILE *entrada = fopen(argv[1], "r");

  if (!entrada)
  {
    printf("File does not exist! Try again typing the filename too\n");
    return 0;
  }

  int tamVetor;
  fscanf(entrada, "%d", &tamVetor);

  int notaAuxiliar;
  char nomeAuxiliar[TAM_NOME];

  Aluno **vetorAlunos = (Aluno **)malloc(sizeof(Aluno *) * tamVetor);

  for (int i = 0; i < tamVetor; i++)
  {
    fscanf(entrada, "%d %s", &notaAuxiliar, nomeAuxiliar);
    vetorAlunos[i] = InicializaAluno(nomeAuxiliar, notaAuxiliar);
  }
  fclose(entrada);

  OrdenaNomeAlunos(vetorAlunos, tamVetor);

  FILE *saida = fopen("saida.csv", "w");

  for (int i = 0; i < tamVetor; i++)
  {
    if (RetornaNota(vetorAlunos[i]) >= MEDIA)
      ImprimeAluno(vetorAlunos[i]);
  }
  fclose(saida);

  for (int i = 0; i < tamVetor; i++)
  {
    LiberaAluno(vetorAlunos[i]);
  }
  free(vetorAlunos);

  return (0);
}