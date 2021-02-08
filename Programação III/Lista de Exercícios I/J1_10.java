import java.util.Scanner;

public class J1_10 {
  public static void main(String[] args) {
    double proximo = 0.0, atual = 0.0, anterior = 1.0;

    Scanner ler = new Scanner(System.in);
    int n = ler.nextInt();

    for (int i = 0; i < n; i++) {

      if (i == 0) {
        System.out.print("0 ");
        if (n == 0)
          break;
        continue;
      }

      proximo = atual + anterior;
      System.out.printf("%.0f ", proximo);
      anterior = atual;
      atual = proximo;
    }
    System.out.println();
    ler.close();
  }
}
