class Retangulo extends Quadrilateros {
  private double base;
  private double altura;

  Retangulo(double base, double altura) {
    super(base, altura, base, altura);
    this.base = base;
    this.altura = altura;
  }

  @Override
  public double calculaArea() {

    return base * altura;
  }

  @Override
  public String toString() {
    return String.format("Retangulo de base %.2f e altura %.2f - perimetro %.2f; area %.2f.", base, altura,
        calculaPerimetro(), calculaArea());

  }

}
