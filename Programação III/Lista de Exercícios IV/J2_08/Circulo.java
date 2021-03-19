class Circulo implements Forma {
  private double raio;
  private final double PI = 3.141521;

  Circulo(double raio) {
    this.raio = raio;
  }

  @Override
  public double calculaPerimetro() {

    return 2 * PI * raio;
  }

  @Override
  public double calculaArea() {

    return raio * PI * raio;
  }

  @Override
  public String toString() {
    return String.format("Circulo de raio %.2f - perimetro %.2f; area %.2f.", raio, calculaPerimetro(), calculaArea());

  }

}
