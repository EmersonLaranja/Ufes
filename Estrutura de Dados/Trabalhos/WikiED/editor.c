
#include "editor.h"

struct editor
{
  char *nome;
};

Editor *InicializaEditor(char *nome)
{
  Editor *editor = (Editor *)malloc(sizeof(Editor));
  editor->nome = strdup(nome);
  return editor;
};

void ImprimeEditor(Editor *editor)
{
  if (editor)

    printf("%s\n", editor->nome);
};

char *RetornaNomeEditor(Editor *editor)
{
  if (editor->nome)
    return editor->nome;
};

void DestroiEditor(Editor *editor)
{
  if (editor)
    free(editor->nome);
  free(editor);
};
