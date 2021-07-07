/* TENTANDO ENTENDER A SITUAÇÃO E CRIAR UMA ABORDAGEM OK
Um numero pode ser primo  (EH_PRIMO) ou não ser primo  (NAO_EH_PRIMO)
Porém, como a ideia eh não ficar repetindo um número já marcado, iniciarei todos com 0
*/
#include <stdlib.h>
#include <stdio.h>

#define EH_PRIMO 'p'
#define NAO_EH_PRIMO 'n'
#define EH_INDEFINIDO '\0'

char *cria_lista(int tam); //cria lista (já crio com calloc que todos ficam com zero)

void marca_multiplos(char *lista, int param, int fim); //altera os multiplos

void imprime_primos(char *lista, int fim);

void destroi_lista(char *lista);
