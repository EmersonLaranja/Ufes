// Início da declaração de variáveis (seção .data)
int dim = 2;                 //declara uma variavel chamada dim, inteiro 32 bits, inicializada com valor 2
float a[] = {0.818, -1.188}; // declara um vetor de float (PF single) chamado a, com 2 posições.
                             // O vetor a é inicializado com 2 números reais 0.ZYX e -1.YXZ
float b[] = {-2.881, 3.818}; // declara um vetor de float (PF single) chamado b, com 2 posições.
                             // O vetor b é inicializado com 2 números reais -2.XZY e 3.XYZ
float r[] = {0, 0};          // declara um vetor de float (PF single) chamado r, com 2 posições.
                             // O vetor r é inicializado com valores 0.0 em duas 2 posições

void main(void)
{ // Início do programa (seção .text)
  for (int i = 0; i < dim; i++)
  {                     // Declara um loop que começa com valor i=0 (i é inteiro, 32 bits) e
                        // repete enquanto i<dim. i é incrementado a cada iteração
    r[i] = a[i] + b[i]; // Soma os valores nas posições i (i=0 e i=1) dos vetores a e b (ou
    // seja a[i]+b[i]) e armazena o resultado na mesma posição i do vetor
    // r (ou seja, r[i] = a[i] + b[i])
  }
}
