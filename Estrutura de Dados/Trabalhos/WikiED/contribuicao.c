#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "contribuicao.h"

struct contribuicao
{
  Editor *editor;
  char *texto;
  int foiRetirada;
};

Contribuicao *InicializaContribuicao(Editor *editor, char *texto)
{
  Contribuicao *contribuicao = (Contribuicao *)malloc(sizeof(Contribuicao));
  contribuicao->editor = editor;
  contribuicao->texto = strdup(texto);
  contribuicao->foiRetirada = 0;
  return editor;
};

Editor *RetornaEditorContribuicao(Contribuicao *contribuicao)
{
  return contribuicao->editor;
};

int ContribuicaoFoiRetirada(Contribuicao *contribuicao)
{
  return contribuicao->foiRetirada;
};

// void DestroiContribuicao(Contribuicao *contribuicao)
// {

//   if (contribuicao)
//   {
//     contribuicao->foiRetirada = 1;
//     free(contribuicao);
//   }
// };