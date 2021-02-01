#include "arv.h"

int main()
{
  Aluno *al1, *al2, *al3, *al4, *al5, *al6;

  al1 = InicializaAluno(1, "Emerson", 9);
  al2 = InicializaAluno(2, "Gabriel", 5);
  al3 = InicializaAluno(3, "Joao", 4);
  al4 = InicializaAluno(4, "Lucas", 9);
  al5 = InicializaAluno(5, "Diego", 10);
  al6 = InicializaAluno(6, "Felipe", 2);

  printf("Imprimindo alunos validos:\n");
  ImprimeAluno(al1);
  ImprimeAluno(al2);
  ImprimeAluno(al3);
  ImprimeAluno(al4);
  ImprimeAluno(al5);
  ImprimeAluno(al6);

  Arv *a = arv_cria(al1,
                    arv_cria(al2,
                             arv_criavazia(),
                             arv_cria(al3, arv_criavazia(),
                                      arv_criavazia())),
                    arv_cria(al4,
                             arv_cria(al5, arv_criavazia(),
                                      arv_criavazia()),
                             arv_cria(al6, arv_criavazia(),
                                      arv_criavazia())));

  printf("\nImprimindo arvore:\n");
  arv_imprime(a);

  int pertence = arv_pertence(a, RetornaNome(al2));
  printf("\n\nAluno al2 pertence?: %d\n", pertence);

  pertence = arv_pertence(a, RetornaNome(al6));
  printf("Aluno al6 pertence?: %d\n", pertence);

  Arv *pai = arv_pai(a, al2);
  printf("Pai do al3 no: %s\n", RetornaNome(RetornaAlunoArvore(pai)));

  int f = folhas(a);
  printf("Numero de folhas da arvore: %d\n", f);

  int i = ocorrencias(a, al5);
  printf("Numero de ocorrencias de f: %d\n", i);

  arv_libera(a);

  DestroiAluno(al1);
  DestroiAluno(al2);
  DestroiAluno(al3);
  DestroiAluno(al4);
  DestroiAluno(al5);
  DestroiAluno(al6);

  return 0;
}