public class Produto {
  protected String nome;
  protected float preco;

  Produto(String nome, float preco) {
    this.setNome(nome);
    this.setPreco(preco);
  }

  public void imprimir() {
    System.out.printf("%s (R$ %.2f) - ", nome, preco);
  }

  // public String toString() {
  // return this.nome + String.format(" (R$%2.f) - ", this.preco);
  // }

  // setters & getters
  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getNome() {
    return nome;
  }

  public void setPreco(float preco) {
    this.preco = preco;
  }

  public float getPreco() {
    return preco;
  }
}
