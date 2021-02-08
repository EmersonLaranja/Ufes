public class J1_01 {
  public static void main(String[] args) {
    double numerador, denominador, s1 = 0.0, s2 = 0.0, s3 = 0.0;

    // Calculando e imprimindo S1
    for (numerador = 1.0, denominador = 1.0; denominador <= 50.0; numerador += 2.0, denominador++)
      s1 = s1 + (numerador / denominador);
    System.out.println("S1 = " + s1);

    // Calculando e imprimindo S2
    for (numerador = 2.0, denominador = 50.0; denominador >= 1.0; numerador *= 2.0, denominador--)
      s2 = s2 + (numerador / denominador);
    System.out.println("S2 = " + s2);

    // Calculando e imprimindo S3
    double resultado = 0.0;
    for (numerador = 1.0, denominador = 1.0; numerador <= 10.0; numerador++, denominador = numerador * numerador) {
      resultado = numerador / denominador;
      if (numerador % 2 == 0 || denominador % 2 == 0) {
        s3 = s3 - resultado;
      } else {
        s3 = s3 + resultado;
      }
    }
    System.out.println("S3 = " + s3);
  };
}
