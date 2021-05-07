
#include "Eleicao.h"
#include "Leitura.h"
using namespace std;

int main(int argc, char const *argv[])
{
  setlocale(LC_ALL, "pt_BR.utf8"); //usando locale br + biblioteca NumberUtils para as formatações

  try
  {
    Leitura leitura;
    leitura.verificaQuantidadeParametros(argc); //se faltou algum argumento, o programa fechará notificando-o
    string dataEleicao = argv[3];

    //lendo candidatos.csv e preenchendo na lista
    list<Candidato> listaDeCandidatos;
    leitura.inicializaListaCandidatos(argv[1], dataEleicao, listaDeCandidatos);

    //lendo partidos.csv e preenchendo na lista
    list<Partido> listaDePartidos;
    leitura.inicializaListaPartidos(argv[2], listaDePartidos, listaDeCandidatos);

    //criando eleição
    Eleicao eleicao(listaDeCandidatos, listaDePartidos, dataEleicao);

    //relatório 1
    eleicao.imprimeNumeroVagas();

    //relatório 2
    eleicao.imprimeCandidatosEleitos();

    //relatório 3
    eleicao.imprimeListaCandidatosMaisVotadosPorLimiteVagas();

    //relatório 4
    eleicao.imprimeCandidatosBeneficiadosVotacaoMajoritaria();

    //relatório 5
    eleicao.imprimeCandidatosBeneficiadosVotacaoProporcional();

    //relatório 6
    eleicao.imprimeListaPartidos();

    //relatório 7
    eleicao.ordenaPrimeiroUltimoListaPartido();

    //relatório 8
    eleicao.imprimeCandidatosPorIdade();

    //relatório 9
    eleicao.imprimeCandidatosPorSexo();

    //relatório 10
    eleicao.imprimeVotosTotaisEleicao();
  }
  catch (const exception &e)
  {
    cout << e.what() << '\n'; //lança exceção de arquivo não encontrado (especificando o arquivo)
  }
  return 0;
}