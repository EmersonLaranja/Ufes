#include "aluno.h"
#define MEDIA 7
#define TAM_NOME 20

Aluno **InicializaVetorAlunos(int tam)
{
  Aluno **vetor = (Aluno **)malloc(sizeof(Aluno *) * tam);
  return vetor;
};

void LeArquivoEPreencheAluno(FILE *entrada, Aluno **vetor, int tam)
{
  int notaAuxiliar;
  char nomeAuxiliar[TAM_NOME];
  for (int i = 0; i < tam; i++)
  {
    fscanf(entrada, "%d %s", &notaAuxiliar, nomeAuxiliar);
    vetor[i] = InicializaAluno(nomeAuxiliar, notaAuxiliar);
  }
};

void ImprimeVetor(Aluno **vetor, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    if (RetornaNota(vetor[i]) >= MEDIA)
      ImprimeAluno(vetor[i]);
  }
};

void LiberaVetor(Aluno **vetor, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    LiberaAluno(vetor[i]);
  }
  free(vetor);
};

int main(int argc, char const *argv[])
{
  FILE *entrada = fopen(argv[1], "r");

  if (!entrada)
  {
    printf("File does not exist! Try again typing the filename too\n");
    return 0;
  }

  int tamVetor;
  fscanf(entrada, "%d", &tamVetor); //Le tamanho do vetor passado na primeira linha

  Aluno **vetorAlunos = InicializaVetorAlunos(tamVetor); //Aloca o vetor

  LeArquivoEPreencheAluno(entrada, vetorAlunos, tamVetor); //Preenche o vetor

  fclose(entrada);

  OrdenaNomeAlunos(vetorAlunos, tamVetor);

  FILE *saida = fopen("saida.csv", "w");

  ImprimeVetor(vetorAlunos, tamVetor); //Imprime o vetor

  fclose(saida);

  LiberaVetor(vetorAlunos, tamVetor); //libera o vetor

  return (0);
}