#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

#define TAM 10
/*TipoItem Pessoa (tipo opaco). Contem campos:
  - nome (string)
  - idade (int)
  - endereco (string)
  */
struct pessoa
{
  char *nome;
  int idade;
  char *endereco;
};

/*Tipo que define a Pilha (tipo opaco)
  Atencao: Esta pilha pode conter ate 10 Pessoas
*/
struct pilha
{
  Pessoa *pessoas[TAM];
  int topo;
};

/*Inicializa a Pilha
* inputs: nenhum
* output: P (a pilha criada)
* pre-condicao: nenhuma
* pos-condicao: P está definida e vazia
*/
Pilha *cria_pilha()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->topo = 0;
}

/*Insere uma pessoa no topo da pilha (se houver espaco)
* inputs: P (uma pilha) e E (uma pessoa)
* output: nenhum
* pre-condicao: P nao vazia e com espaco para o elemento.
* pos-condicao: Ao final da função, a pilha tem E como o elemento
do topo
*/
void push(Pessoa *pessoa, Pilha *pilha)
{
  if (!pilha || pilha->topo >= TAM)
  {
    printf("Pilha invalida ou cheia\n");
    return;
  }
  pilha->pessoas[pilha->topo] = pessoa;
  pilha->topo++;
}

/*Retira uma Pessoa do topo da Pilha (se pilha não vazia)
* inputs: a Pilha
* output: a pessoa retirada do topo da pilha
* pre-condicao: Pilha não é nula e não é vazia
* pos-condicao: pilha não contém o elemento retirado do topo
*/
Pessoa *pop(Pilha *pilha)
{
  if (!pilha || pilha->topo <= 0)
  {
    printf("Pilha invalida ou vazia\n");
    return NULL;
  }
  Pessoa *pessoa = pilha->pessoas[pilha->topo - 1];
  pilha->topo--;
  return pessoa;
}

/*Imprime as pessoas da pilha
 * inputs: a pilha
 * output: nenhum
 * pre-condicao: pilha P não vazia
 * pos-condicao: Pilha permanece inalterada
 */
void imprime_pilha(Pilha *pilha)
{
  if (pilha)
  {
    for (int i = pilha->topo - 1; i >= 0; i--)
    {
      printf("Nome:%s Idade:%d Endereco:%s\n", pilha->pessoas[i]->nome, pilha->pessoas[i]->idade, pilha->pessoas[i]->endereco);
    }
  }
}

/*Libera a memoria ocupada pela pilha
* inputs: a Pilha
* output: NULL
* pre-condicao: Pilha não é nula
* pos-condicao: Toda memoria eh liberada
*/
Pilha *destroi_pilha(Pilha *pilha)
{
  if (pilha)
  {
    for (int i = pilha->topo - 1; i >= 0; i--)
    {
      if (pilha->pessoas[i]->nome)
        free(pilha->pessoas[i]->nome);

      if (pilha->pessoas[i]->endereco)
        free(pilha->pessoas[i]->endereco);

      if (pilha->pessoas[i])
        free(pilha->pessoas[i]);
    }

    free(pilha);
  }
  return NULL;
}

/*Inicializa um TipoItem Pessoa
* inputs: o nome, a idade e o endereco da pessoa
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, idade e endereco validos
* pos-condicao: tipo item criado, com os campos nome, idade e endereco copiados
*/
Pessoa *inicializaPessoa(char *nome, int idade, char *endereco)
{
  Pessoa *pessoa = (Pessoa *)malloc(sizeof(Pessoa));
  pessoa->nome = strdup(nome);
  pessoa->idade = idade;
  pessoa->endereco = strdup(endereco);
  return pessoa;
}
