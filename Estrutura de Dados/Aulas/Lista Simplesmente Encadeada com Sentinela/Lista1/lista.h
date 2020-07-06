#include <stdio.h>

typedef struct lista Lista;
typedef struct celula Celula;

// -----FUNÇÕES------
Lista *InicializaLista(void);
void InsereInicioLista(Lista *lista, char *fruta);
void InsereFimLista(Lista *lista, char *fruta);
void ImprimeLista(Lista *lista);
void OrdenaListaCrescente(Lista *lista);
void OrdenaListaDecrescente(Lista *lista);
void RemoveElementoLista(Lista *lista, char *fruta);
void RemoveLista(Lista *lista);
int QntCelulasNumaLista(Lista *lista);
Lista *CopiaLista(Lista *listaOriginal);
Lista *CopiaInversoLista(Lista *listaOriginal);
Lista *IntercalaListas(Lista *lista1, Lista *lista2);
