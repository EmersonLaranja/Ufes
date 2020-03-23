// #include <stdio.h>
// #include "matriz.h"
// #include <stdlib.h>

// struct matriz
// {
//     int *inicio;
//     int numlinhas;
//     int numcolunas;
// };

// typedef struct matriz Matriz;

// Matriz *inicializaMatriz(int nlinhas, int ncolunas)
// {
//     Matriz *m = (Matriz *)malloc(sizeof(Matriz));
//     if (m == NULL)
//         return m;

//     m->numcolunas = ncolunas;
//     m->numlinhas = nlinhas;

//     m->inicio = (int *)malloc(nlinhas * ncolunas * sizeof(int));
//     if (m->inicio == NULL)
//     {
//         free(m);
//         return NULL;
//     }
//     return m;
// }


// void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
// {

//     if (linha < mat->numlinhas && coluna < mat->numcolunas)
//     {
//         mat->inicio[linha * mat->numcolunas + coluna] = elem;
//     }
// }


// int recuperaElemento(Matriz *mat, int linha, int coluna)
// {
//     if (linha < mat->numlinhas && coluna < mat->numcolunas)
//     {
//         return mat->inicio[linha * mat->numcolunas + coluna];
//     }
// }


// int recuperaNColunas(Matriz *mat)
// {
//     return mat->numcolunas;
// }

// int recuperaNLinhas(Matriz *mat)
// {
//     return mat->numlinhas;
// }


// Matriz *transposta(Matriz *mat)
// {
//     Matriz *t = inicializaMatriz(recuperaNColunas(mat), recuperaNLinhas(mat));
//     for (int i = 0; i < t->numlinhas; i++)
//     {
//         for (int j = 0; j < t->numcolunas; j++)
//         {
//             modificaElemento(t, i, j, recuperaElemento(mat, j, i));
//         }
//     }
//     return t;
// }



// Matriz *multiplicacao(Matriz *mat1, Matriz *mat2)
// {
//     Matriz *mult = inicializaMatriz(recuperaNLinhas(mat1), recuperaNColunas(mat2));
//     int t;
//     for (int i = 0; i < mult->numlinhas; i++)
//     {
//         for (int j = 0; j < mult->numcolunas; j++)
//         {
//             t = 0;
//             for (int k = 0; k < recuperaNColunas(mat1); k++)
//             {
//                 t += (mat1->inicio[i * mat1->numcolunas + k]) * (mat2->inicio[k * mat2->numcolunas + j]);
//             }
//             mult->inicio[i * mult->numcolunas + j] = t;
//         }
//     }
//     return mult;
// }


// void imprimeMatriz(Matriz *mat)
// {
//     int k;
//     for (int i = 0; i < mat->numlinhas; i++)
//     {
//         printf("|");
//         for (int j = 0; j < mat->numcolunas; j++)
//         {
//             k = (i * (mat->numcolunas)) + j;
//             if (j == mat->numcolunas - 1)
//             {
//                 printf("%.2d", mat->inicio[k]);
//                 continue;
//             }
//             printf("%.2d\t", mat->inicio[k]);
//         }
//         printf("|\n");
//     }
// }

// void destroiMatriz(Matriz *mat)
// {
//     if (mat)
//     {
//         if (mat->inicio)
//             free(mat->inicio);
//         free(mat);
//     }
// }