public class Cd extends Produto {
  private String numeroFaixas;

  Cd(String nome, float preco, String numeroFaixas) {
    super(nome, preco);
    setNumeroFaixas(numeroFaixas);
  }

  @Override
  public void imprimir() {
    super.imprimir();
    System.out.println(this.numeroFaixas + " faixas");
  }

  public void setNumeroFaixas(String numeroFaixas) {
    this.numeroFaixas = numeroFaixas;
  }

  public String getNumeroFaixas() {
    return numeroFaixas;
  }

}
