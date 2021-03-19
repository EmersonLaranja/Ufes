class Quadrado extends Quadrilateros {
  private double lado;

  Quadrado(double lado) {
    super(lado, lado, lado, lado);
    this.lado = lado;
  }

  @Override
  public double calculaArea() {

    return lado * lado;
  }

  @Override
  public String toString() {
    return String.format("Quadrado de lado %.2f - perimetro:%.2f; area %.2f.", lado, calculaPerimetro(), calculaArea());

  }

}