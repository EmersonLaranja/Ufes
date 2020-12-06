#include "abb.h"

int main()
{
  /* Cria alunos para teste */
  Aluno *amelie = InicializaAluno(1, "Amelie", 9.2);
  Aluno *emerson = InicializaAluno(2, "Emerson", 9.5);
  Aluno *maria = InicializaAluno(3, "Maria", 9.9);
  Aluno *julia = InicializaAluno(4, "Julia", 7.1);
  Aluno *diego = InicializaAluno(5, "Diego", 5.9);
  Aluno *gabriela = InicializaAluno(6, "Gabriela", 5.74);
  Aluno *wendel = InicializaAluno(7, "Wendel", 7);
  Aluno *beatriz = InicializaAluno(8, "Beatriz", 8.8);

  // criando a arvore
  Arv *arv = abb_cria();

  arv = abb_insere(arv, amelie);
  arv = abb_insere(arv, emerson);
  arv = abb_insere(arv, maria);
  arv = abb_insere(arv, julia);
  arv = abb_insere(arv, diego);
  arv = abb_insere(arv, gabriela);
  arv = abb_insere(arv, wendel);
  arv = abb_insere(arv, beatriz);

  abb_imprime(arv);

  printf("\nBusca 1:\n");
  /* Faz a busca e imprime a partir das chaves */
  Arv *busca = abb_busca(arv, 3); //maria
  abb_imprime(busca);

  printf("\nBusca 2:\n");
  busca = abb_busca(arv, 2); //emerson
  abb_imprime(busca);

  printf("\nBusca 3:\n");
  busca = abb_busca(arv, 457); //valor que nao tem na arvore
  abb_imprime(busca);

  arv = abb_retira(arv, 7); //retira a wendel
  arv = abb_retira(arv, 1); //retira a amelie
  arv = abb_retira(arv, 6); //retira a gabriela
  printf("\narv modificada:\n");
  abb_imprime(arv);

  printf("\narv modificada 2:\n");
  arv = abb_retira(arv, 999); //tenta retirar valor fora da arvore (nao altera a arvore)
  abb_imprime(arv);
  printf("\n");

  /* Libera a memoria alocada */
  abb_libera(arv);
  abb_libera(busca);
  DestroiAluno(amelie);
  DestroiAluno(emerson);
  DestroiAluno(maria);
  DestroiAluno(julia);
  DestroiAluno(diego);
  DestroiAluno(wendel);
  DestroiAluno(gabriela);
  DestroiAluno(beatriz);
}