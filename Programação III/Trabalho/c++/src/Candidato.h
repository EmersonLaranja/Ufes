#if !defined(CANDIDATO_H)
#define CANDIDATO_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <list>

#define MASCULINO 'M'
#define FEMININO 'F'

using namespace std;

class Candidato
{
private:
  unsigned numero;
  unsigned votosNominais;
  unsigned numeroPartido;
  unsigned idade;
  char sexo;
  string situacao;
  string destinoVoto;
  string nome;
  string nomeUrna;
  string siglaPartido;
  string dataNascimento;

public:
  Candidato();
  Candidato(const vector<string> &vetorDadosCandidato, const string &dataEleicao);
  bool verificaDestinoVoto() const;
  const unsigned calculaIdadeCandidato(const string &dataEleicao, const string &dataNascimento) const;

  // --------------imprimir---------------//
  void imprimeCandidato() const;

  //------------------setters-----------------
  void setSiglaPartido(const string &siglaPartido);
  void setDestinoVoto(const string &destinoVoto);
  void setDataNascimento(const string &dataNascimento);
  void setNome(const string &nome);
  void setNomeUrna(const string &nomeUrna);
  void setNumero(const unsigned &numero);
  void setNumeroPartido(const unsigned &numeroPartido);
  void setSexo(const char &sexo);
  void setIdade(const string &dataEleicao);
  void setSituacao(const string &situacao);
  void setVotosNominais(const unsigned &votosNominais);

  //-------------getters---------------------
  const string &getSiglaPartido() const;
  const string &getDestinoVoto() const;
  const string &getNome() const;
  const string &getNomeUrna() const;
  const unsigned &getNumero() const;
  const unsigned &getNumeroPartido() const;
  const char &getSexo() const;
  const unsigned &getIdade() const;
  const string &getSituacao() const;
  const unsigned &getVotosNominais() const;
  const string &getDataNascimento() const;

  ~Candidato();
};

class ComparaCandidatos
{
public:
  bool operator()(Candidato &candidato1, Candidato &candidato2);
  bool compare(const string &dataNascimentoCandidato1, const string &dataNascimentoCandidato2);
};
#endif // CANDIDATO_H
