public class Dvd extends Produto {
  private String duracao;

  Dvd(String nome, float preco, String duracao) {
    super(nome, preco);
    setDuracao(duracao);
  }

  @Override
  public void imprimir() {
    super.imprimir();
    System.out.println(this.duracao + " minutos");
  }

  public void setDuracao(String duracao) {
    this.duracao = duracao;
  }

  public String getDuracao() {
    return duracao;
  }

}
