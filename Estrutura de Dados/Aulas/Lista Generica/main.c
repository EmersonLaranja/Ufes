#include "listaDeAlunos.h"

int main(int argc, char const *argv[])
{
  ListaGenerica *lista = CriaLista();

  Aluno *aluno1 = InicializaAluno(1, "Diego", 5.88);
  lista = InsereLista(lista, aluno1);

  Aluno *aluno2 = InicializaAluno(2, "Diogo", 8.55);
  lista = InsereLista(lista, aluno2);

  Aluno *aluno3 = InicializaAluno(3, "Dimitri", 9.9);
  lista = InsereLista(lista, aluno3);

  Aluno *aluno4 = InicializaAluno(4, "Dias", 6.74);
  lista = InsereLista(lista, aluno4);

  Aluno *aluno5 = InicializaAluno(5, "Ribamar", 10.0);
  lista = InsereLista(lista, aluno5);

  ImprimeListaAlunos(lista);

  lista = RetiraAluno(lista, 4);

  printf("\n------------------------------------------------\n\n");

  ImprimeListaAlunos(lista);

  if (!PertenceAluno(lista, 20))
  {
    printf("\nAluno esta na lista!\n");
  }
  else
  {
    printf("Aluno nao esta na lista!\n");
  }

  printf("\nA media da turma eh: %.2f\n", CalculaMediaTurma(lista));

  LiberaLista(lista);

  DestroiAluno(aluno1);
  DestroiAluno(aluno2);
  DestroiAluno(aluno3);
  DestroiAluno(aluno4);
  DestroiAluno(aluno5);

  return 0;
}