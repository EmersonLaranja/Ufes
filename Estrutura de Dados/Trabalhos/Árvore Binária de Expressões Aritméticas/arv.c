#define _GNU_SOURCE
#include "arv.h"
#include <string.h>

#define INICIAL -1 //visto que 0 eh valido como operador, colocarei um negativo para inicializar as variaveis

struct arvore
{
    char operador;
    float operando;
    struct arvore *esquerda;
    struct arvore *direita;
};

Arvore *CriaArvoreVazia(void)
{
    return NULL;
}

Arvore *CriaArvore(void)
{
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));

    arvore->operador = '\0';
    arvore->operando = INICIAL;
    arvore->esquerda = arvore->direita = NULL;

    return arvore;
}

/*Verifica se o elemento eh um operador;
 *inputs: elemento (tipo char)
 *outputs: booleano (tipo int);
 *pré-condição: elemento existe;
 *pós-condição: 1 se for operador, caso contrario, 0;
*/
static int EhOperador(char elemento)
{

    return elemento == '*' ||
           elemento == '+' ||
           elemento == '-' ||
           elemento == '/';
}

/*Verifica se o elemento eh um operando;
 *inputs: elemento (tipo char)
 *outputs: booleano (tipo int);
 *pré-condição: elemento existe;
 *pós-condição: 1 se for operando, caso contrario, 0;
*/
static int EhOperando(char elemento)
{
    if (elemento >= '0' && elemento <= '9')
    {
        return 1;
    }
    return 0;
}

int RetornaOperando(Arvore *arvore)
{
    return arvore->operando;
}

char RetornaOperador(Arvore *arvore)
{
    return arvore->operador;
}

int ArvoreEhVazia(Arvore *arvore)
{
    return arvore == NULL;
}

Arvore *LiberaArvore(Arvore *arvore)
{
    if (!ArvoreEhVazia(arvore))
    {
        LiberaArvore(arvore->esquerda);
        LiberaArvore(arvore->direita);
        free(arvore);
    }
    return NULL;
}

Arvore *InsereOperandoArvore(Arvore *arvore, int operando)
{
    arvore->operando = operando;
    return arvore;
}

Arvore *InsereOperadorArvore(Arvore *arvore, char operador)
{
    arvore->operador = operador;
    return arvore;
}

Arvore *MontaArvore(Arvore *arvore, char *expressao, int *posicao)
{
    int ehOperando = 0;

    if (expressao[*posicao] == '(')
    {
        // Parenteses envolta de um numero, exemplo: (59)
        if ((EhOperando(expressao[*posicao + 1] == 1))) //proximo elemento eh o operando (um numero)
        {
            ehOperando = 1;
            *posicao = *posicao + 1;
        }

        //Se for inicio da expressão "(":
        else if (expressao[*posicao] == '(')
        {
            *posicao = *posicao + 1;

            // Se a arvore for vazia, inicializo um no filho a esquerda
            if (ArvoreEhVazia(arvore->esquerda))
            {
                arvore->esquerda = CriaArvore();
            }

            //entro no filho a esquerda e monto seus nós
            arvore->esquerda = MontaArvore(arvore->esquerda, expressao, posicao);
        }
    }

    if (expressao[*posicao] == ')')
    {
        *posicao = *posicao + 1;
        return arvore;
    }

    if (EhOperando(expressao[*posicao]) || ehOperando)
    {
        ehOperando = 0;
        char *num = NULL;

        //Le tudo ate o ')';
        num = strtok((expressao + *posicao), ")");

        //transforma valor para float e atribui ao no
        arvore = InsereOperandoArvore(arvore, atof(num));

        //atualizando a posicao da leitura do valor da expressao
        int tamanho = strlen(num) + 1;
        *posicao = *posicao + tamanho;

        return arvore;
    }

    //Se for operador;
    else if (EhOperador(expressao[*posicao]))
    {
        arvore = InsereOperadorArvore(arvore, expressao[*posicao]);
        *posicao = *posicao + 1;

        //Se a arvore for vazia, inicializo um no filho a direita
        if (ArvoreEhVazia(arvore->direita))
        {
            arvore->direita = CriaArvore();
        }

        //entro no filho a direita e monto seus nós
        arvore->direita = MontaArvore(arvore->direita, expressao, posicao);
    }
    return arvore;
}

float CalculaEquacao(Arvore *arvore)
{
    float esquerda = 0.0F, direita = 0.0F;

    if (ArvoreEhVazia(arvore))
    {
        return 0;
    }

    //Se for um número;
    if (ArvoreEhVazia(arvore->esquerda) && ArvoreEhVazia(arvore->direita))
    {
        return arvore->operando;
    }

    esquerda = CalculaEquacao(arvore->esquerda);
    direita = CalculaEquacao(arvore->direita);

    if (arvore->operador == '+')
    {
        esquerda += direita;
        return esquerda;
    }
    if (arvore->operador == '-')
    {
        esquerda = esquerda - direita;
        return esquerda;
    }
    if (arvore->operador == '*')
    {
        esquerda *= direita;
        return esquerda;
    }

    if (arvore->operador == '/')
    {
        esquerda = esquerda / direita;
        return esquerda;
    }

    return esquerda;
}

float ResultadoExpressao(Arvore *arvore)
{
    float resultado = 0.0F;

    resultado = CalculaEquacao(arvore);

    return resultado;
}

Arvore *PreencheArvore(Arvore *arvore, char *expressao)
{
    int posicao = 0;

    if (ArvoreEhVazia(arvore))
    {
        arvore = CriaArvore();
    }
    arvore = MontaArvore(arvore, expressao, &posicao);
    return arvore;
}

void ImprimeResultado(FILE *arquivoSaida, float resultado)
{
    float auxiliarFloat;
    int auxiliarInteiro;

    auxiliarFloat = resultado;
    auxiliarInteiro = resultado;

    if (auxiliarFloat - auxiliarInteiro == 0.0) //saber se eh preciso imprimir os numeros depois da virgula
    {
        fprintf(arquivoSaida, "%d\n", auxiliarInteiro);
        return;
    }
    fprintf(arquivoSaida, "%.2f\n", auxiliarFloat);
    return;
}