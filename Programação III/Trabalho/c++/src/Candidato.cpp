#include "Candidato.h"

Candidato::Candidato(){

};
Candidato::Candidato(const vector<string> &vetorDadosCandidato, const string &dataEleicao)
{
  unsigned numero = stoi(vetorDadosCandidato[0]);
  unsigned votosNominais = stoi(vetorDadosCandidato[1]);
  string situacao = vetorDadosCandidato[2];
  string nome = vetorDadosCandidato[3];
  string nomeUrna = vetorDadosCandidato[4];
  char sexo = vetorDadosCandidato[5].at(0);
  string dataNascimento = vetorDadosCandidato[6];
  string destinoVoto = vetorDadosCandidato[7];
  unsigned numeroPartido = stoi(vetorDadosCandidato[8]);

  this->setNumero(numero);
  this->setVotosNominais(votosNominais);
  this->setSituacao(situacao);
  this->setNome(nome);
  this->setSexo(sexo);
  this->setNomeUrna(nomeUrna);
  this->setDestinoVoto(destinoVoto);
  this->setNumeroPartido(numeroPartido);
  this->setDataNascimento(dataNascimento);
  this->setIdade(dataEleicao);
};

Candidato::~Candidato() {}

bool Candidato::verificaDestinoVoto() const
{

  return this->destinoVoto == "Válido";
}

//-------------setters-------------

void Candidato::setSiglaPartido(const string &siglaPartido)
{
  this->siglaPartido = siglaPartido;
};

void Candidato::setDestinoVoto(const string &destinoVoto)
{
  this->destinoVoto = destinoVoto;
};

void Candidato::setNome(const string &nome)
{
  this->nome = nome;
};

void Candidato::setNomeUrna(const string &nomeUrna)
{
  this->nomeUrna = nomeUrna;
};

void Candidato::setNumero(const unsigned &numero)
{
  this->numero = numero;
};

void Candidato::setNumeroPartido(const unsigned &numeroPartido)
{
  this->numeroPartido = numeroPartido;
};

void Candidato::setSexo(const char &sexo)
{
  switch (sexo)
  {
  case 'M':
    this->sexo = MASCULINO;
    break;

  default:
    this->sexo = FEMININO;
    break;
  }
};

void Candidato::setIdade(const string &dataEleicao)
{
  this->idade = calculaIdadeCandidato(dataEleicao, this->getDataNascimento());
};

void Candidato::setSituacao(const string &situacao)
{
  this->situacao = situacao;
};

void Candidato::setVotosNominais(const unsigned &votosNominais)
{
  this->votosNominais = votosNominais;
};

void Candidato::setDataNascimento(const string &dataNascimento)
{
  this->dataNascimento = dataNascimento;
};

//-------------getters-------------
const string &Candidato::getSiglaPartido() const
{
  return this->siglaPartido;
};

const string &Candidato::getDestinoVoto() const
{
  return this->destinoVoto;
};

const string &Candidato::getNome() const
{
  return nome;
};

const string &Candidato::getNomeUrna() const
{
  return nomeUrna;
};

const unsigned &Candidato::getNumero() const
{
  return numero;
};

const unsigned &Candidato::getNumeroPartido() const
{
  return numeroPartido;
};

const unsigned &Candidato::getIdade() const
{
  return this->idade;
};

const string &Candidato::getSituacao() const
{
  return situacao;
};

const char &Candidato::getSexo() const
{
  return sexo;
};

const string &Candidato::getDataNascimento() const
{
  return dataNascimento;
};

const unsigned &Candidato::getVotosNominais() const
{
  return votosNominais;
};

void Candidato ::imprimeCandidato() const
{
  cout << this->getNome() << " / "
       << this->getNomeUrna() << " ("
       << this->getSiglaPartido() << ", "
       << this->getVotosNominais();

  if (this->getVotosNominais() > 1)
    cout
        << " votos)" << endl;
  else
    cout << " voto)" << endl;
};

const unsigned Candidato ::calculaIdadeCandidato(const string &dataEleicao, const string &dataNascimento) const
{
  string data, linha;
  vector<unsigned> vetorDataEleicao;
  vector<unsigned> vetorDataNascimento;

  stringstream s1(dataEleicao);
  while (getline(s1, data, '/'))
  {
    unsigned aux = stoi(data);
    vetorDataEleicao.push_back(aux);
  }
  stringstream s2(dataNascimento);
  while (getline(s2, data, '/'))
  {
    unsigned aux = stoi(data);
    vetorDataNascimento.push_back(aux);
  }

  if (vetorDataNascimento[1] < vetorDataEleicao[1])
  {
    return vetorDataEleicao[2] - vetorDataNascimento[2];
  }
  else if (vetorDataNascimento[1] == vetorDataEleicao[1] && vetorDataNascimento[0] <= vetorDataEleicao[0])
  {
    return vetorDataEleicao[2] - vetorDataNascimento[2];
  }
  else
  {
    return ((vetorDataEleicao[2] - vetorDataNascimento[2]) - 1);
  }
}

bool ComparaCandidatos::compare(const string &dataNascimentoCandidato1, const string &dataNascimentoCandidato2)
{
  string data, linha;
  vector<unsigned> vetorDataNascimentoCandidato1;
  vector<unsigned> vetorDataNascimentoCandidato2;

  stringstream s1(dataNascimentoCandidato1);
  while (getline(s1, data, '/'))
  {
    unsigned aux = stoi(data);
    vetorDataNascimentoCandidato1.push_back(aux);
  }

  stringstream s2(dataNascimentoCandidato2);
  while (getline(s2, data, '/'))
  {
    unsigned aux = stoi(data);
    vetorDataNascimentoCandidato2.push_back(aux);
  }

  if (vetorDataNascimentoCandidato2[2] < vetorDataNascimentoCandidato1[2])
  {
    return false;
  }
  else if (vetorDataNascimentoCandidato2[2] == vetorDataNascimentoCandidato1[2] && vetorDataNascimentoCandidato2[1] < vetorDataNascimentoCandidato1[1])
  {
    return false;
  }
  else if (vetorDataNascimentoCandidato2[2] == vetorDataNascimentoCandidato1[2] && vetorDataNascimentoCandidato2[1] == vetorDataNascimentoCandidato1[1] && vetorDataNascimentoCandidato2[0] < vetorDataNascimentoCandidato1[0])
  {
    return false;
  }
  else
  {
    return true;
    ;
  }
}

bool ComparaCandidatos::operator()(Candidato &candidato1, Candidato &candidato2)
{
  if (candidato1.getVotosNominais() > candidato2.getVotosNominais())
    return true;
  else if (candidato1.getVotosNominais() < candidato2.getVotosNominais())
    return false;
  else
  {
    return compare(candidato1.getDataNascimento(), candidato2.getDataNascimento());
  }
}
