import java.util.Locale;
import java.util.Scanner;

class Ponto {
  float x;
  float y;
}

class Triangulo {
  // triangulo com 3 vértices: v1,v2,v3
  Ponto v1;
  Ponto v2;
  Ponto v3;

}

public class J1_07 {

  public static void main(String[] args) {
    Triangulo triangulo = new Triangulo();
    Ponto v1 = new Ponto();
    Ponto v2 = new Ponto();
    Ponto v3 = new Ponto();

    Scanner leitura = new Scanner(System.in);
    leitura.useLocale(Locale.US);// ler ponto ao invés de virgula

    System.out.println("Digite os ponto x e y referentes ao primeiro vértice");
    v1.x = leitura.nextFloat();
    v1.y = leitura.nextFloat();

    System.out.println("Digite os ponto x e y referentes ao segundo vértice");
    v2.x = leitura.nextFloat();
    v2.y = leitura.nextFloat();

    System.out.println("Digite os ponto x e y referentes ao terceiro vértice");
    v3.x = leitura.nextFloat();
    v3.y = leitura.nextFloat();

    triangulo.v1 = v1;
    triangulo.v2 = v2;
    triangulo.v3 = v3;

    leitura.close();

    double perimetro = 0.0;

    perimetro = Math.sqrt(((triangulo.v1.y - triangulo.v2.y) * (triangulo.v1.y - triangulo.v2.y))
        + ((triangulo.v1.x - triangulo.v2.x) * (triangulo.v1.x - triangulo.v2.x))) + // |v1-v2|

        Math.sqrt(((triangulo.v1.y - triangulo.v3.y) * (triangulo.v1.y - triangulo.v3.y))
            + ((triangulo.v1.x - triangulo.v3.x) * (triangulo.v1.x - triangulo.v3.x)))
        + // |v1-v3|

        Math.sqrt(((triangulo.v3.y - triangulo.v2.y) * (triangulo.v3.y - triangulo.v2.y))
            + ((triangulo.v3.x - triangulo.v2.x) * (triangulo.v3.x - triangulo.v2.x)));// |v3-v2|

    System.out.printf("%.5f\n", perimetro);
  }
}