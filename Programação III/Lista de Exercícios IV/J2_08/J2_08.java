import java.io.File;
import java.util.Scanner;

interface Forma {
  public double calculaArea();

  public double calculaPerimetro();
}

public class J2_08 {

  public static void main(String[] args) {
    try {
      File entrada = new File(args[0]);
      Scanner scanner = new Scanner(entrada);
      int qnt = scanner.nextInt(); // quantidade de itens

      for (int i = 0; i <= qnt; i++) {
        String[] elementos = scanner.nextLine().split(",");
        if (elementos[0].equals("R")) {
          Retangulo retangulo = new Retangulo(Double.parseDouble(elementos[1]), Double.parseDouble(elementos[2]));
          System.out.println(retangulo.toString());
        }
        if (elementos[0].equals("C")) {
          Circulo circulo = new Circulo(Double.parseDouble(elementos[1]));
          System.out.println(circulo.toString());

        }
        if (elementos[0].equals("Q")) {
          Quadrado quadrado = new Quadrado(Double.parseDouble(elementos[1]));
          System.out.println(quadrado.toString());
        }
      }

    } catch (Exception e) {
      System.err.println(e);
    }

  }
}
