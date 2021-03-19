class Num {
  int i = 5;

  void somar(int j) {
    i += j;
  }
}

public class Test {
  public static void main(String[] args) {
    Num m = new Num(), n = new Num();
    m.somar(10);
    n.somar(5);
  }
}