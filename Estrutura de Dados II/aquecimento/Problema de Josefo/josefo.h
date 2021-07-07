/* TENTANDO ENTENDER A SITUAÇÃO E CRIAR UMA ABORDAGEM OK
Aqui a lógica é encontrar o M-ésimo elemento a partir do Primeiro
o Primeiro vai ser inicialmente o 1, depois será o elemento posterior ao M-ésimo.

O lance então é ficar redefinindo o Primeiro elemento e somar M.
Quando M > N, é só fazer M-N para encontrar o primeiro elemento

Ok, vamos de lista circular que eu sei um caminho


1) Cria a lista onde o primeiro vai ser o 1
2)Verifica se
3)Remove o elemento na M-esima posição
4)Coloca o elemento  da posição M-esima + 1 como líder
5) Volta no passo 2 


*/
#include <stdlib.h>
#include <stdio.h>

typedef struct listaCircular ListaCircular;
typedef struct celula Celula;

ListaCircular *CriaLista(void);

void InsereElementosFinalLista(ListaCircular *lista, int qntElementos);

ListaCircular *RemoveElementoLista(int elemento);
