/*Estruturas de Dados – 2019/2
Aula de Laboratório – 09/09/2019
Profa Patrícia Dockhorn Costa (email: edufes2019@gmail.com)
TAD - Lista
Instruções:
Implemente o TAD Lista que está especificado no arquivo lista.h. Gere um arquivo lista.c com
sua implementação. Teste a sua implementação com o programa proglista.c. Ambos os arquivos
lista.h e proglista.c estão disponíveis no site da disciplina.
Envie o arquivo lista.c para o email da disciplina (edufes2019@gmail.com) com o assunto:
ED20192:lab3:<nome>*/

/*
*********************************
* Programa testador do TAD Lista
*********************************
*/
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
  // criando a lista vazia
  TipoLista *lista;
  lista = InicializaLista();

  // criando alguns alunos apenas para testar (mais adequado seria carregar de um arquivo)
  TipoItem *maria = InicializaTipoItem("maria", 123, "rua da maria");
  TipoItem *sofia = InicializaTipoItem("sofia", 2345, "rua da sofia");
  TipoItem *jose = InicializaTipoItem("jose", 4523, "rua do jose");
  TipoItem *joao = InicializaTipoItem("joao", 34, "rua do joao");
  TipoItem *catarina = InicializaTipoItem("catarina", 987, "rua da catarina");

  //Insere os alunos na lista
  Insere(maria, lista);
  Insere(sofia, lista);
  Insere(jose, lista);
  Insere(joao, lista);
  Insere(catarina, lista);

  //Imprime a lista com todos os alunos
  // Imprime(lista);

  //Retira a maria da lista e imprime
  TipoItem *retirado = Retira(lista, 123);
  if (retirado != NULL)
  {

    Imprime(lista);
  }
  else
    printf("Não foi possivel retirar o aluno de matrícula 123\n");

  //Retira o Joao da lista e imprime
  retirado = Retira(lista, 34);
  if (retirado != NULL)
  {

    Imprime(lista);
  }
  else
    printf("Não foi possivel retirar o aluno de matrícula 34\n");

  //Tenta retirar com um número de matrícula inexistente
  retirado = Retira(lista, 555);
  if (retirado != NULL)
  {

    Imprime(lista);
  }
  else
    printf("Não foi possivel retirar o aluno de matrícula 555\n");

  free(retirado);
  lista = Libera(lista);
}