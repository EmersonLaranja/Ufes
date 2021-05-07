#if !defined(PARTIDO_H)
#define PARTIDO_H

#include "Candidato.h"

using namespace std;

class Partido
{
  unsigned numero;
  unsigned votosLegenda;
  unsigned totalCandidatosEleitos;
  unsigned totalVotosNominais;
  unsigned totalVotosPartido;
  unsigned totalCandidatos;
  string nomePartido;
  string sigla;
  list<Candidato> listaCandidatos;

public:
  Partido();
  Partido(const vector<string> &vetorDadosCandidato, list<Candidato> &listaDeCandidatosValidos);

  bool ordenaPartidoPorVotos(const Partido &partido) const;

  //---------------imprimir--------------
  void imprimePartido() const;
  void imprimePrimeiroUltimoPartido() const;
  void imprimeListaCandidatosDoPartido() const;

  //---------------setters--------------
  void setTotalCandidatos();
  void setTotalCandidatosEleitos();
  void setTotalVotosNominais();
  void setTotalVotosPartido();
  void setListaCandidatos(list<Candidato> &listaDeCandidatosValidos);
  void setNumero(const unsigned &numero);
  void setSigla(const string &sigla);
  void setVotosLegenda(const unsigned &votosLegenda);
  void setNome(const string &nome);

  //---------------getters--------------
  const unsigned &getTotalCandidatos() const;
  const unsigned &getTotalCandidatosEleitos() const;
  const unsigned &getTotalVotosNominais() const;
  const unsigned &getTotalVotosPartido() const;
  const unsigned &getNumero() const;
  const unsigned &getVotosLegenda() const;
  const string &getNome() const;
  const string &getSigla() const;
  const list<Candidato> &getListaCandidatos() const;

  ~Partido();
};

class ComparaPartidos
{
public:
  bool operator()(const Partido &partido1, const Partido &partido2);
};

#endif // PARTIDO_H
