#include "arv.h"

struct arvore
{
  char operador;
  int operando;
  Arvore *esq;
  Arvore *dir;
};

Arvore *ArvoreCriaVazia(void)
{
  return NULL;
};

Arvore *ArvoreCria(int operando, char operador, Arvore *sae, Arvore *sad)
{
  Arvore *p = (Arvore *)malloc(sizeof(Arvore));
  //pensei em usar union para ter alocado operador ou operando, mas o fim de semestre não permitiu
  p->operador = '\0';
  p->operando = -1;
  p->esq = sae;
  p->dir = sad;
  return p;
};

Arvore *ArvoreLibera(Arvore *a)
{

  if (!ArvoreVazia(a))
  {
    ArvoreLibera(a->esq);
    ArvoreLibera(a->dir);
    free(a);
  }

  return NULL;
};

int ArvoreVazia(Arvore *a)
{
  return a == NULL ? 1 : 0;
};

static int EhNumero(char c)
{
  if (c >= '0' && c <= '9')
  {
    return 1;
  };
  return 0;
};

static int EhOperador(char c)
{
  return c == '+' ||
         c == '-' ||
         c == '/' ||
         c == '*';
};

Arvore *MontaArvore(Arvore *arvore, char *expressao, Pilha *caminhos, int posicao)
{

  while (expressao[posicao] != '\n')
  {

    if (EhNumero(expressao[posicao]))
    {
      int i = 1;
      char vetorAuxiliar[30];
      vetorAuxiliar[0] = expressao[posicao];
      posicao++;

      while (expressao[posicao] != ')')
      {
        vetorAuxiliar[i] = expressao[posicao];
        i++;
        posicao++;
      }
      vetorAuxiliar[i] = '\n';
      sscanf(vetorAuxiliar, "%d", &arvore->operando);
      printf("%d", arvore->operando);
    }

    if (EhOperador(expressao[posicao]))
    {
      //defina o valor do no atual com o operador
      arvore->operador = expressao[posicao];
      printf("%c", expressao[posicao]);
      posicao++;
    }

    if (expressao[posicao] == '(')
    {
      //se for null, cria um nó à esquerda
      if (arvore->operador == '\0' || arvore->operando == -1)
      {
        arvore->esq = ArvoreCria(-1, 0, NULL, NULL);
        Push(caminhos, arvore->esq);
        //vai para o nó filho criado
        posicao++;
        MontaArvore(arvore->esq, expressao, caminhos, posicao);
      }
      //diferentemente, cria um nó à direita
      else
      {
        arvore->dir = ArvoreCria(-1, 0, NULL, NULL);
        Push(caminhos, arvore->dir);
        //vai para o nó filho criado
        posicao++;
        MontaArvore(arvore->dir, expressao, caminhos, posicao);
      }

      printf("%c", expressao[posicao]);
    }

    if (expressao[posicao] == ')')
    {
      //retira o elemento do topo da pilha
      Pop(caminhos);
      //se a pilha ficar vazia, quebre o laço
      if (RetornaValorTopo(caminhos) == 0)
        break;

      printf("%c", expressao[posicao]);
      //volta para o nó raiz
      //! acho que aqui tem que rolar um posicao++, depura pra ver
      posicao++;
      return arvore;
    }
  }
  return arvore;
};

float CalculaArvore(Arvore *arvore){};