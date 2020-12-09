#include "arv.h"
#include "pilha.h"

#define TAM 100

int main(int argc, char *argv[])
{
  FILE *entrada;
  char expressao[TAM];
  entrada = fopen(argv[1], "r");

  if (entrada == NULL)
  {
    printf("problema ao ler o arquivo de entrada\n");
    return 0;
  }

  FILE *saida = fopen("saida.txt", "w");

  if (saida == NULL)
  {
    printf("problema ao criar o arquivo de saida\n");
    return 0;
  }

  while (fscanf(entrada, "%s", expressao) != EOF)
  {
    Arvore *arvore = ArvoreCria(0, 0, NULL, NULL); //nó raiz
    Pilha *caminhos = InicializaPilha();
    Push(caminhos, arvore);

    Arvore *arvoreAuxiliar = MontaArvore(arvore, expressao, caminhos, 1); //começa do 1 pois consideramos a criação da arvore como  o primeiro '('

    float resultado = CalculaArvore(arvoreAuxiliar);
    printf("%.2f\n", resultado);

    ArvoreLibera(arvoreAuxiliar);
    ArvoreLibera(arvore);
    DestroiPilha(caminhos);
  }

  printf("\n");

  fclose(entrada);
  fclose(saida);

  return 0;
}