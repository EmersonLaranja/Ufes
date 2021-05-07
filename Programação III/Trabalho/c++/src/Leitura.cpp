#include "Leitura.h"
#include <stdexcept>

const void Leitura::inicializaListaCandidatos(string nomeArquivoEntrada, string dataEleicao, list<Candidato> &listaDeCandidatos)
{
  ifstream in(nomeArquivoEntrada);
  if (in.is_open())
  {
    string linha, palavra;
    vector<string> vetorDados;

    getline(in, linha); //pulando primeira linha
    while (getline(in, linha))
    {

      stringstream s(linha);

      while (getline(s, palavra, ','))
      {
        vetorDados.push_back(palavra);
      }

      Candidato candidato(vetorDados, dataEleicao);
      if (candidato.verificaDestinoVoto())
      {
        listaDeCandidatos.push_back(candidato);
      }

      vetorDados.clear();
    }
    listaDeCandidatos.sort(ComparaCandidatos());

    in.close();
  }
  else
  {
    throw runtime_error("Não foi possível ler arquivo de candidatos");
  }
};

const void Leitura::inicializaListaPartidos(string nomeArquivoEntrada, list<Partido> &listaPartidos, list<Candidato> &listaDeCandidatos)
{
  string linha, palavra;
  vector<string> vetorDados;

  //LENDO ARQUIVO DE PARTIDOS
  ifstream inPartido(nomeArquivoEntrada);

  if (inPartido.is_open())
  {
    getline(inPartido, linha); //pulando a primeira linha

    while (getline(inPartido, linha))
    {

      stringstream s(linha);

      while (getline(s, palavra, ','))
      {
        vetorDados.push_back(palavra);
      }

      Partido partido(vetorDados, listaDeCandidatos);

      listaPartidos.push_back(partido);
      vetorDados.clear();
    }

    inPartido.close();
    listaPartidos.sort(ComparaPartidos());
  }
  else
  {
    throw runtime_error("Não foi possível ler arquivo de partidos");
  }
}

const void Leitura::verificaQuantidadeParametros(const int &argumentos) const
{
  if (argumentos < 4)
  {
    throw runtime_error("Problemas ao ler dados de entrada, parametros de entrada incompletos");
  }
}