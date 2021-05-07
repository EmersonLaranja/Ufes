
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.lang.Comparable;

public class Partido implements Comparable<Partido> {
  private int numero;
  private int votosLegenda;
  private int totalCandidatosEleitos = 0;
  private int totalVotosNominais = 0;
  private int totalVotosPartido = 0;
  private int totalCandidatos = 0;
  private String nomePartido;
  private String sigla;
  private List<Candidato> listaCandidatos;

  Partido(String[] vetorDados, List<Candidato> listaDeCandidatosValidos) {
    int numeroPartido = Integer.parseInt(vetorDados[0]);
    int votosLegenda = Integer.parseInt(vetorDados[1]);
    String nomePartido = vetorDados[2];
    String siglaPartido = vetorDados[3];

    this.setNumero(numeroPartido);
    this.setNome(nomePartido);
    this.setSigla(siglaPartido);
    this.setVotosLegenda(votosLegenda);
    this.setListaCandidatos(listaDeCandidatosValidos);
    this.setTotalVotosNominais();
    this.setTotalVotosPartido();
    this.setTotalCandidatosEleitos();
    this.setTotalCandidatos();
  }
  // --------------@Overrides---------------//

  @Override
  public String toString() {
    String s = this.sigla + " - " + this.numero + ", ";
    String aux;

    if (this.totalVotosPartido > 1) {
      if (this.totalVotosNominais > 1)
        s = s.concat(+this.totalVotosPartido + " votos (" + this.totalVotosNominais + " nominais e ");
      else {
        s = s.concat(+this.totalVotosPartido + " votos (" + this.totalVotosNominais + " nominal e ");

      }
    } else {
      if (this.totalVotosNominais > 1)
        s = s.concat(+this.totalVotosPartido + " voto (" + this.totalVotosNominais + " nominais e ");
      else {
        s = s.concat(+this.totalVotosPartido + " voto (" + this.totalVotosNominais + " nominal e ");

      }
    }

    s = s.concat(+this.votosLegenda + " de legenda), " + this.getTotalCandidatosEleitos());

    if (this.totalCandidatosEleitos > 1) {
      aux = " candidatos eleitos";
    } else
      aux = " candidato eleito";

    return s + aux;
  }

  @Override
  public int compareTo(Partido partido) {
    if (this.totalVotosPartido > partido.gettotalVotosPartido())
      return -1;
    else if (this.totalVotosPartido < partido.gettotalVotosPartido())
      return 1;
    else {
      if (this.numero > partido.getNumero())
        return -1;
      return 1;
    }
  }

  public void imprimePrimeiroUltimoPartido() {

    System.out.print(this.sigla + " - " + this.numero + ", ");
    if (this.listaCandidatos.size() > 0) {
      Candidato aux = this.listaCandidatos.get(0);
      if (aux.getvotosNominais() > 1)
        System.out.print(aux.getnomeUrna() + " (" + aux.getNumero() + ", " + aux.getvotosNominais() + " votos) / ");
      else
        System.out.print(aux.getnomeUrna() + " (" + aux.getNumero() + ", " + aux.getvotosNominais() + " voto) / ");

      aux = this.listaCandidatos.get(listaCandidatos.size() - 1);

      if (aux.getvotosNominais() > 1)
        System.out.print(aux.getnomeUrna() + " (" + aux.getNumero() + ", " + aux.getvotosNominais() + " votos)");
      else
        System.out.print(aux.getnomeUrna() + " (" + aux.getNumero() + ", " + aux.getvotosNominais() + " voto)");

    }
    System.out.println();
  }

  public void imprimeListaCandidatosDoPartido() {
    int i = 1;
    for (Candidato candidato : this.listaCandidatos) {
      System.out.println(i + " - " + candidato);
    }

  }

  public int verificaListaCandidatosVazia() {

    if (this.listaCandidatos.isEmpty()) {
      return 1;
    }
    return 0;
  }

  public Candidato buscaCandidatoPorPosicao(int posicao) {
    return listaCandidatos.get(posicao);
  }
  // ---------------setters & getters--------------------

  public void setTotalCandidatos() {
    this.totalCandidatos = this.listaCandidatos.size();
  }

  public int getTotalCandidatos() {
    return totalCandidatos;
  }

  public void setTotalCandidatosEleitos() {
    for (Candidato candidato : listaCandidatos) {
      if (candidato.getSituacao().equals("Eleito")) {
        this.totalCandidatosEleitos++;
      }
    }
  }

  public int getTotalCandidatosEleitos() {
    return totalCandidatosEleitos;
  }

  public void setTotalVotosNominais() {
    for (Candidato candidato : listaCandidatos) {
      this.totalVotosNominais += candidato.getvotosNominais();
    }
  }

  public int getTotalVotosNominais() {
    return totalVotosNominais;
  }

  public void setTotalVotosPartido() {
    this.totalVotosPartido = this.totalVotosNominais + this.votosLegenda;
  }

  public int gettotalVotosPartido() {
    return totalVotosPartido;
  }

  public void setListaCandidatos(List<Candidato> listaDeCandidatosValidos) {
    this.listaCandidatos = new ArrayList<Candidato>();

    for (Candidato candidato : listaDeCandidatosValidos) {
      if (candidato.getnumeroPartido() == this.numero) {
        this.listaCandidatos.add(candidato);
        candidato.setSiglaPartido(this.sigla);
      }
    }

  }

  public List<Candidato> getlistaCandidatos() {
    return listaCandidatos;
  }

  public void setNome(String nome) {
    this.nomePartido = nome;
  }

  public String getNome() {
    return nomePartido;
  }

  public void setNumero(int numero) {
    this.numero = numero;
  }

  public int getNumero() {
    return numero;
  }

  public void setSigla(String sigla) {
    this.sigla = sigla;
  }

  public String getSigla() {
    return sigla;
  }

  public void setVotosLegenda(int votosLegenda) {
    this.votosLegenda = votosLegenda;
  }

  public int getvotosLegenda() {
    return votosLegenda;
  }

}

class OrdenarPrimeiroUltimoCandidatoPartido implements Comparator<Partido> {
  @Override
  public int compare(Partido p1, Partido p2) {
    int value;
    OrdenarCandidatoPorMaisVotadoComparator comp = new OrdenarCandidatoPorMaisVotadoComparator();
    value = comp.compare(p2.buscaCandidatoPorPosicao(0), p1.buscaCandidatoPorPosicao(0));

    if (value == -1)
      return -1;
    else if (value == 1)
      return 1;

    else {
      return Integer.compare(p1.getNumero(), p2.getNumero());
    }
  }
}
