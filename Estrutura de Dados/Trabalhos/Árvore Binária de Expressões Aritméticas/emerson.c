#include "arv.h"
#define TAM 250

int main(int argc, char const *argv[])
{
    FILE *fileEntrada = fopen("entrada.txt", "r");

    if (fileEntrada == NULL)
    {
        printf("Nao foi possivel abrir o arquivo entrada.txt\n");
        return 0;
    }

    FILE *arquivoSaida = fopen("saida.txt", "w");

    if (arquivoSaida == NULL)
    {
        printf("Nao foi possivel abrir o arquivo saida.txt\n");
        return 0;
    }

    char expressao[TAM];
    Arvore *arvore;

    while (fscanf(fileEntrada, "%s", expressao) != EOF)
    {
        float resultado = 0.0F;

        arvore = CriaArvoreVazia();

        //armaneza os valores da expressao na arvore
        arvore = PreencheArvore(arvore, expressao);

        //retorna o resultado da expressao
        resultado = ResultadoExpressao(arvore);

        // imprime o resultado da expressao
        ImprimeResultado(arquivoSaida, resultado);

        // libera o espaco de memoria alocado
        arvore = LiberaArvore(arvore);
    }

    fclose(arquivoSaida);
    fclose(fileEntrada);
    return 0;
}
