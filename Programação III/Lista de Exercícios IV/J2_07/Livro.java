public class Livro extends Produto {
  private String nomeAutor;

  Livro(String nome, float preco, String nomeAutor) {
    super(nome, preco);
    setNomeAutor(nomeAutor);
  }

  @Override
  public void imprimir() {
    super.imprimir();
    System.out.println(this.nomeAutor);
  }

  public void setNomeAutor(String nomeAutor) {
    this.nomeAutor = nomeAutor;
  }

  public String getNomeAutor() {
    return nomeAutor;
  }

}
