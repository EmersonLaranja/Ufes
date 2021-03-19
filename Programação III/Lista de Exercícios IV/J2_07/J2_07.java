import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

public class J2_07 {

  public static void main(String[] args) {
    try {
      File entrada = new File(args[0]);
      Scanner scanner = new Scanner(entrada);
      int qnt = scanner.nextInt(); // quantidade de itens
      scanner.nextLine();
      Produto[] produtos = new Produto[qnt];

      for (int i = 0; i < qnt; i++) {
        String[] elementos = scanner.nextLine().split(",");
        if (elementos[0].equals("L")) {
          Produto livro = new Livro(elementos[1], Float.parseFloat(elementos[2]), elementos[3]);
          produtos[i] = livro;
        }
        if (elementos[0].equals("C")) {
          Produto cd = new Cd(elementos[1], Float.parseFloat(elementos[2]), elementos[3]);
          produtos[i] = cd;
        }
        if (elementos[0].equals("D")) {
          Produto dvd = new Dvd(elementos[1], Float.parseFloat(elementos[2]), elementos[3]);
          produtos[i] = dvd;
        }
      }
      Arrays.sort(produtos);
      for (Produto produto : produtos) {
        produto.imprimir();
      }

    } catch (Exception e) {
      System.err.println(e);
    }

  }
}