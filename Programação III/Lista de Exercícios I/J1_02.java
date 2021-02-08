public class J1_02 {
  public static void main(String[] args) {
    int esquerda, direita, resultado;
    for (int i = 1000; 1000 <= i && i < 9999; i++) {
      esquerda = i / 100; // dois primeiros digitos do numero
      direita = i % 100; /// dois ultimos digitos do numero

      resultado = (esquerda + direita);

      if ((resultado * resultado) == i) {
        System.out.println(i);

      }
    }
  }
}
