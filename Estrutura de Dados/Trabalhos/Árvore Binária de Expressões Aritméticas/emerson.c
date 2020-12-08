#include "arv.h"

int EhNumero(char c)
{
  if (c >= '0' && c <= '9')
  {
    return 1;
  };
  return 0;
}

int EhOperador(char c)
{
  return c == '+' ||
         c == '-' ||
         c == '/' ||
         c == '*';
}

int main(int argc, char *argv[])
{
  FILE *entrada;
  char caracter;
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

  //! Criar uma arvore nula
  // Crie uma pilha e insira a arvore

  while (fscanf(entrada, "%c", &caracter) != EOF)
  {
    if (caracter == '\n')
    {
      //Calcula o resultado
      printf("\n");
      fprintf(saida, "\n");
      continue;
    }

    if (EhNumero(caracter))
    {
      int i = 1;
      char vetorAuxiliar[30];
      vetorAuxiliar[0] = caracter;

      while (fscanf(entrada, "%c", &caracter) == 1)
      {
        if (caracter == ')')
        {
          break;
        }

        vetorAuxiliar[i] = caracter;
        i++;
      }
      vetorAuxiliar[i] = '\n';
      sscanf(vetorAuxiliar, "%d", &i);
      // adiciona o numero ao item da arvore
      printf("%d", i);
      fprintf(saida, "%d", i);
    }

    if (EhOperador(caracter))
    {
      //defina o valor do no atual com o operador
      printf("%c", caracter);
      fprintf(saida, "%c", caracter);
    }

    if (caracter == '(')
    {
      //if da pilha na posicao topo-2 (item anterior)
      //se for null, cria um nó à esquerda
      //diferentemente, cria um nó à direita

      //adiciona nó na pilha
      //vai para o nó filho criado
      printf("%c", caracter);
      fprintf(saida, "%c", caracter);
    }
    if (caracter == ')')
    {
      //retira o elemento do topo da pilha
      //volta para o nó raiz
      //se a pilha ficar vazia, quebre o laço
      printf("%c", caracter);
      fprintf(saida, "%c", caracter);
    }
  }

  printf("\n");
  fclose(entrada);
  fclose(saida);

  return 0;
}