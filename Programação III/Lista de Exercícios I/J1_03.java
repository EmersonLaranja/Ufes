import java.util.Scanner;

public class J1_03 {
  public static void main(String[] args) {
    int x, y, mdc = 1;
    System.out.print("Informe dois números para calcular o MDC: ");
    Scanner ler = new Scanner(System.in);
    x = ler.nextInt();
    y = ler.nextInt();

    while (!(x == 1 || y == 1)) {
      if (x == y) {
        mdc = x;
        break;
      }
      if (y > x) {
        int temp = x;
        x = y;
        y = temp;
      }

      mdc = x - y;
      x = mdc;
    }
    System.out.println(mdc);
    ler.close();
  }
}
