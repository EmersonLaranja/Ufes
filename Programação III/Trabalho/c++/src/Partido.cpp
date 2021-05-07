#include "Partido.h"

Partido::Partido() {}
Partido::~Partido() {}

Partido::Partido(const vector<string> &vetorDadosCandidato, list<Candidato> &listaDeCandidatosValidos)
{
  string sigla = vetorDadosCandidato[3];
  string nomePartido = vetorDadosCandidato[2];
  unsigned votosLegenda = stoi(vetorDadosCandidato[1]);
  unsigned numero = stoi(vetorDadosCandidato[0]);

  setSigla(sigla);
  setNome(nomePartido);
  setNumero(numero);
  setListaCandidatos(listaDeCandidatosValidos);
  setVotosLegenda(votosLegenda);
  setTotalCandidatos();
  setTotalCandidatosEleitos();
  setTotalVotosNominais();
  setTotalVotosPartido();
}

void Partido::imprimePartido() const
{
  cout << this->getSigla() << " - "
       << this->getNumero() << ", ";

  if (this->getTotalVotosPartido() > 1)
  {
    cout << this->getTotalVotosPartido() << " votos (";
  }
  else
  {
    cout << this->getTotalVotosPartido() << " voto (";
  }

  if (this->getTotalVotosNominais() > 1)
  {
    cout << this->getTotalVotosNominais() << " nominais e ";
  }
  else
  {
    cout << this->getTotalVotosNominais() << " nominal e ";
  }
  cout
      << this->getVotosLegenda() << " de legenda), ";

  if (this->getTotalCandidatosEleitos() > 1)
  {
    cout << this->getTotalCandidatosEleitos() << " candidatos eleitos" << endl;
  }
  else
  {
    cout << this->getTotalCandidatosEleitos() << " candidato eleito" << endl;
  }
}

void Partido::imprimePrimeiroUltimoPartido() const
{
  cout << this->getSigla() << " - " << this->getNumero() << ", ";
  if (this->listaCandidatos.size() > 0)
  {
    Candidato aux;

    // -----------------------PRIMEIRO-----------------------------------
    aux = listaCandidatos.front();

    if (aux.getVotosNominais() > 1)
      cout
          << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " votos) / ";
    else
      cout << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " voto) / ";

    // -----------------------ULTIMO-----------------------------------
    aux = listaCandidatos.back();

    if (aux.getVotosNominais() > 1)
      cout
          << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " votos)";
    else
      cout << aux.getNomeUrna() << " (" << aux.getNumero() << ", " << aux.getVotosNominais() << " voto)";
  }

  cout << endl;
}

void Partido::imprimeListaCandidatosDoPartido() const
{
  unsigned i = 1;
  for (Candidato candidato : listaCandidatos)
  {
    cout << i << " - ";
    candidato.imprimeCandidato();
    i++;
  }
}

void Partido::setTotalCandidatos()
{
  this->totalCandidatos = 0;
  this->totalCandidatos = this->listaCandidatos.size();
}
void Partido::setTotalCandidatosEleitos()
{
  unsigned contador = 0;

  for (Candidato &candidato : listaCandidatos)
    if (candidato.getSituacao() == "Eleito")
      contador++;

  this->totalCandidatosEleitos = contador;
}
void Partido::setTotalVotosNominais()
{
  unsigned contador = 0;
  for (Candidato &candidato : listaCandidatos)
  {
    contador += candidato.getVotosNominais();
  }
  this->totalVotosNominais = contador;
}
void Partido::setTotalVotosPartido()
{
  this->totalVotosPartido = this->totalVotosNominais + this->votosLegenda;
}

void Partido::setListaCandidatos(list<Candidato> &listaDeCandidatosValidos)
{
  for (Candidato &candidato : listaDeCandidatosValidos)
  {
    if (candidato.getNumeroPartido() == this->numero)
    {
      candidato.setSiglaPartido(this->sigla);
      this->listaCandidatos.push_back(candidato);
    }
  }
}
void Partido::setNumero(const unsigned &numero)
{
  this->numero = numero;
}
void Partido::setSigla(const string &sigla)
{
  this->sigla = sigla;
}
void Partido::setVotosLegenda(const unsigned &votosLegenda)
{
  this->votosLegenda = votosLegenda;
}
void Partido::setNome(const string &nome)
{
  this->nomePartido = nome;
}

const unsigned &Partido::getTotalCandidatos() const
{
  return this->totalCandidatos;
}
const unsigned &Partido::getTotalCandidatosEleitos() const
{
  return this->totalCandidatosEleitos;
}
const unsigned &Partido::getTotalVotosNominais() const
{
  return this->totalVotosNominais;
}
const unsigned &Partido::getTotalVotosPartido() const
{
  return this->totalVotosPartido;
}
const unsigned &Partido::getNumero() const
{
  return this->numero;
}
const unsigned &Partido::getVotosLegenda() const
{
  return this->votosLegenda;
}
const string &Partido::getNome() const { return this->nomePartido; }
const string &Partido::getSigla() const { return this->sigla; }
const list<Candidato> &Partido::getListaCandidatos() const { return this->listaCandidatos; }

bool Partido::ordenaPartidoPorVotos(const Partido &partido) const
{
  if (this->totalVotosPartido > partido.totalVotosPartido)
    return true;
  else if (this->totalVotosPartido < partido.totalVotosPartido)
    return false;
  else
  {
    if (this->numero < partido.numero)
      return true;
    return false;
  }
}

bool ComparaPartidos::operator()(const Partido &partido1, const Partido &partido2)
{
  if (partido1.getTotalVotosPartido() > partido2.getTotalVotosPartido())
    return true;
  else if (partido1.getTotalVotosPartido() < partido2.getTotalVotosPartido())
    return false;
  else
  {
    if (partido1.getNumero() < partido2.getNumero())
      return true;
    return false;
  }
}
