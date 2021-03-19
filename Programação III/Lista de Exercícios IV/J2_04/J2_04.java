import java.io.File;
import java.util.Scanner;

public class J2_04 {

  public static void main(String[] args) {
    try {
      File entrada = new File(args[0]);
      Scanner scanner = new Scanner(entrada);
      int qnt = scanner.nextInt(); // quantidade de itens

      for (int i = 0; i <= qnt; i++) {
        String[] elementos = scanner.nextLine().split(",");
        if (elementos[0].equals("L")) {
          Livro livro = new Livro(elementos[1], Float.parseFloat(elementos[2]), elementos[3]);
          livro.imprimir();
        }
        if (elementos[0].equals("C")) {
          Cd cd = new Cd(elementos[1], Float.parseFloat(elementos[2]), elementos[3]);
          cd.imprimir();
        }
        if (elementos[0].equals("D")) {
          Dvd dvd = new Dvd(elementos[1], Float.parseFloat(elementos[2]), elementos[3]);
          dvd.imprimir();
        }
      }

    } catch (Exception e) {
      System.err.println(e);
    }

  }
}