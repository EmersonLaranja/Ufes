#ifndef EDITOR_H
#define EDITOR_H

typedef struct editor Editor;

Editor *InicializaEditor(char *nome);

void ImprimeEditor(Editor *editor);

char *RetornaNomeEditor(Editor *editor);

void DestroiEditor(Editor *editor);

#endif /* EDITOR_H */