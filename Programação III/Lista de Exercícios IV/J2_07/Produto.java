import java.lang.Comparable;

public class Produto implements Comparable<Produto> {
  protected String nome;
  protected float preco;

  Produto(String nome, float preco) {
    this.setNome(nome);
    this.setPreco(preco);
  }

  public void imprimir() {
    System.out.printf("%s (R$ %.2f) - ", nome, preco);
  }

  @Override
  public int compareTo(Produto produto) {
    if (this.preco > produto.getPreco())
      return -1;
    else if (this.preco < produto.getPreco())
      return 1;
    else {
      if (this.nome.compareTo(produto.getNome()) < 0)
        return -1;
      return 1;
    }
  }

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
