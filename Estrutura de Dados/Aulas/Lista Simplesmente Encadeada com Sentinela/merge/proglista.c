/*
 *********************************
 * Programa testador 4 do TAD Lista Simplesmente Encadeada COM Sentinela de Alunos
 * Testa funcoes Cria, Imprime, Insere, Retira, Retira todas ocorrencias, Merge, Libera Lista e Libera Aluno (Vale 10,0)
 *********************************
 */
#include <stdio.h>
#include "lista.h"

int main()
{
    
    printf ("\n **** Preparando para a Terceira Bateria de Testes. Vale 10,0 **** \n\n");
    
    //cria  turmas
    TLista* turma1 = CriaLista();
    TLista* turma2 = CriaLista();
    
    //cria alunos para teste
    TAluno* patricia = InicializaAluno ("Patricia", 123);
    TAluno* maria = InicializaAluno ("Maria", 122);
    TAluno* joao = InicializaAluno ("Joao", 121);
    TAluno* eduardo = InicializaAluno ("Eduardo", 111);
    TAluno* lucas = InicializaAluno ("Lucas", 100);
    TAluno* john = InicializaAluno ("John", 99);
    TAluno* fulano = InicializaAluno ("Fulano", 98);
    TAluno* simone = InicializaAluno ("Simone", 97);
    
    //Insere alunos na turma1
    InsereAluno (turma1, patricia);
    InsereAluno (turma1, maria);
    InsereAluno (turma1, joao);
    InsereAluno (turma1, eduardo);
    
    // Imprime a turma1 com todos os alunos inseridos
    printf ("\n Imprimindo os alunos da Turma1: \n");
    Imprime (turma1);
    
    //Insere alunos na turma2
    InsereAluno (turma2, lucas);
    InsereAluno (turma2, john);
    InsereAluno (turma2, fulano);
    InsereAluno (turma2, simone);
    
    //Neste momento, insere-se os alunos fulano e simone novamente (simulando algum erro)
    InsereAluno (turma2, fulano);
    InsereAluno (turma2, simone);
    
    // Imprime a turma2 com todos os alunos inseridos (2 ocorrencias de fulano e 2 ocorrencias de simone)
    printf ("\n Imprimindo os alunos da Turma2 - com repeticoes de Fulano e Simone: \n");
    Imprime (turma2);
    
    //tenta retirar o John da lista turma1
    john = Retira (turma1, 99);
    
    if (john == NULL)
        printf ("\n O Aluno John não se encontra na Turma1 \n");
    
    //retira agora o john da turma2
    john = Retira (turma2, 99);
    
    if (john == NULL)
        printf ("\n O Aluno John não se encontra na Turma2 \n");
    
    //Imprime a turma2 sem o John
    printf ("\n Imprimindo os alunos da Turma2 (sem o john) - mas ainda com repeticoes: \n");
    Imprime (turma2);
    
    //retira agora a patricia da turma1
    patricia = Retira (turma1, 123);
    
    //Imprime a turma1 sem a Patricia
    printf ("\n Imprimindo os alunos da Turma1 (sem a patricia): \n");
    Imprime (turma1);
    
    //Declara uma nova lista
    TLista* mix;
    
    //Faz o merge entre as duas turmas
    mix = Merge (turma1, turma2);
    
    //Imprime a lista merge (ainda com alunos repetidos
    printf ("\n Imprimindo a turma merge (ainda com alunos repetidos): \n");
    Imprime (mix);
    
    //Retira as ocorrencias duplicadas da lista completa
    RetiraRepetidos (mix);
    
    //Imprime a lista merge sem repeticoes
    printf ("\n Imprimindo a turma merge (sem repeticoes): \n");
    Imprime (mix);
    
    //libera o espaço alocado para o aluno John
    LiberaAluno (john);
    
    //libera o espaço alocado para o aluno patricia
    LiberaAluno (patricia);
    
    //Liberando as memorias (use o valgrind!)
    LiberaLista (mix);
    LiberaLista (turma1);
    LiberaLista (turma2);
}

