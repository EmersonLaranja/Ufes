import java.util.Random;
import java.util.Scanner;

class Aleatorio {
  private static Random rand;
  private static int VALOR_MAXIMO_DEFAULT = 100;
  private int number;

  Aleatorio() {
    this(VALOR_MAXIMO_DEFAULT);
  }

  Aleatorio(int max) {
    number = rand.nextInt(max);
  }

  public void renovar() {
    number = rand.nextInt(VALOR_MAXIMO_DEFAULT);
  }

  public int getNumber() {
    return number;
  }

  static {
    Scanner scanner = new Scanner(System.in);
    long seed = scanner.nextLong();
    // r and.setSeed(seed); pq assim dá erro?
    rand = new Random(seed);
    scanner.close();
  }
}

public class J2_02 {

  public static void main(String[] args) {
    for (int i = 0; i < 5; i++) {
      Aleatorio random = new Aleatorio();
      System.out.print(random.getNumber() + " ");
      random.renovar();
      System.out.print(random.getNumber() + " ");
    }
    System.out.println();
  }
}
