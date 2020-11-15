#include "pilhasDuplas.h"

int main()
{
    PilhaDupla *pilha = InicializaPilha();
    PushPrimeiraPilha(pilha, 1);
    PushPrimeiraPilha(pilha, 2);
    PushPrimeiraPilha(pilha, 3);
    PushPrimeiraPilha(pilha, 5);
    PushPrimeiraPilha(pilha, 7);
    PushPrimeiraPilha(pilha, 11);

    PushSegundaPilha(pilha, 2);
    PushSegundaPilha(pilha, 4);
    PushSegundaPilha(pilha, 8);
    PushSegundaPilha(pilha, 16);
    PushSegundaPilha(pilha, 32);
    PushSegundaPilha(pilha, 64);

    ImprimePilha(pilha); //imprime ambas pilhas do ultimo a entrar ate o primeiro a entrar

    PopPrimeiraPilha(pilha);
    PopPrimeiraPilha(pilha);
    PopPrimeiraPilha(pilha);
    PopPrimeiraPilha(pilha);
    PopPrimeiraPilha(pilha);
    PopPrimeiraPilha(pilha);
    PopSegundaPilha(pilha);
    PopSegundaPilha(pilha);
    PopSegundaPilha(pilha);
    PopSegundaPilha(pilha);
    PopSegundaPilha(pilha);
    PopSegundaPilha(pilha);
    PopSegundaPilha(pilha); //aqui deve acusar um "erro"

    ImprimePilha(pilha); //imprime ambas pilhas vazias

    DestroiPilhas(pilha); //destroi todo espaco alocado

    return 0;
}
