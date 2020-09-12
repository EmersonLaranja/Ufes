#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

struct esfera
{
  float *area;
  float *volume;
  float r;
};

typedef struct esfera Esfera;

Esfera *inicializa_esfera(float r);
void calc_esfera(float r, float *area, float *volume);
void imprime_esfera(Esfera *esf);
float *retorna_area(Esfera *esf);
float *retorna_volume(Esfera *esf);
void libera_esfera(Esfera *esf);
int raizes(float a, float b, float c, float *x1, float *x2);
int pares(int n, int *vet);
void inverte(int n, int *vet);
double avalia(double *poli, int grau, double x);

// ---------------------EXERCICIO 2.1------------
int main()
{
  Esfera *esfera;
  float raio;
  printf("Digite o raio da esfera: ");
  scanf("%f", &raio);
  esfera = inicializa_esfera(raio);

  calc_esfera(raio, retorna_area(esfera), retorna_volume(esfera));
  imprime_esfera(esfera);

  libera_esfera(esfera);
  return 0;
}

// ---------------------EXERCICIO 2.2------------
/*
int main()
{
  float a, b, c, x1, x2;
  printf("Digite o coeficiente a,b e c da equacao quadratica completa: ");
  scanf("%f%f%f", &a, &b, &c);

  int resultado = raizes(a, b, c, &x1, &x2);
  if (resultado == 0)
  {
    printf("Nao exite raiz real");
    return 0;
  }

  printf("As raizes sao %.2f %.2f", x1, x2);

  return 0;
}
*/

// ---------------------EXERCICIO 2.3------------
/*
int main()
{
  int n;
  printf("Digite o tamanho do seu vetor: ");
  scanf("%d", &n);
  int *vetor = (int *)malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++)
  {
    printf("Digite o elemento da posicao %d  do seu vetor: ", i);
    scanf("%d", (vetor + i));
  }

  int qtdPares = pares(n, vetor);
  printf("A quantidade de interos pares eh:%d", qtdPares);
  free(vetor);

  return 0;
}
*/
// ---------------------EXERCICIO 2.4------------
/*

int main()
{
  unsigned int n;
  printf("Digite o tamanho do seu vetor: ");
  scanf("%u", &n);
  int *vetor = (int *)malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++)
  {
    printf("Digite o elemento da posicao %d  do seu vetor: ", i);
    scanf("%d", (vetor + i));
  }

  inverte(n, vetor);
  printf("\nVetor invertido:");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vetor[i]);
  }

  free(vetor);
  return 0;
}


// ---------------------EXERCICIO 2.5------------
/*
int main()
{
  unsigned int grau;
  double x;

  printf("Digite o grau do seu polinomio: ");
  scanf("%u", &grau);
  double *vetor = (double *)malloc(sizeof(double) * (grau + 1)); //polinomio de grau 2 tem até 3 membros

  for (int i = 0; i <= grau; i++)
  {
    printf("\nDigite o elemento de grau %d do polinomio, caso nao exita digite 0:\n", i);
    scanf("%lf", &(vetor[i]));
  }

  printf("Para termos o resultado, informe o valor de x: \n");
  scanf("%lf", &x);

  double resultado = avalia(vetor, grau, x);
  printf("O valor de x eh:%.2f\n", resultado);

  free(vetor);
}
*/

// ------------FUNCOES----------------
Esfera *inicializa_esfera(float r)
{
  Esfera *esf;
  esf = (Esfera *)malloc(sizeof(Esfera));
  esf->area = (float *)malloc(sizeof(float));
  esf->volume = (float *)malloc(sizeof(float));
  esf->r = r;
  return esf;
}
float *retorna_area(Esfera *esf)
{
  return esf->area;
}
float *retorna_volume(Esfera *esf)
{
  return esf->volume;
}
void calc_esfera(float r, float *area, float *volume)
{
  *area = 4 * r * r * PI;
  *volume = (4 * r * r * r * PI) / 3;
  return;
};

void imprime_esfera(Esfera *esf)
{
  printf("Area:%.2f\n", *esf->area);
  printf("Volume:%.2f\n", *esf->volume);
}

void libera_esfera(Esfera *esf)
{
  free(esf->area);
  free(esf->volume);
  free(esf);
}

int raizes(float a, float b, float c, float *x1, float *x2)
{
  float delta = (b * b) - (4 * a * c);
  printf("DELTA:%.2f\n", delta);
  if (delta < 0)
  {
    return 0;
  }
  *x1 = ((-1 * b) + sqrt(delta)) / 2 * a;
  *x2 = ((-1 * b) - sqrt(delta)) / 2 * a;

  if (delta == 0)
  {
    return 1;
  }

  if (delta > 0)
  {
    return 2;
  }
}

int pares(int n, int *vet)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (vet[i] % 2 == 0)
      count++;
  }
  return count;
}

void inverte(int n, int *vet)
{
  int aux;

  for (int i = 0; i < n / 2; i++)
  {
    aux = vet[i];
    vet[i] = vet[(n - 1) - i];
    vet[(n - 1) - i] = aux;
  }
}

double avalia(double *poli, int grau, double x)
{
  double result = 0.0;
  for (int i = 0; i <= grau; i++)
  {
    result += poli[i] * pow(x, i);
  }

  return result;
}
