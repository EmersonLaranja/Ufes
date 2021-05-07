
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.io.File;
import java.util.Collections;

public class Main {

  public static void main(String[] args) {
    List<Candidato> listaDeCandidatosValidos = new ArrayList<Candidato>();

    try {
      File ArquivoCandidatos = new File(args[0]);

      Scanner scanner = new Scanner(ArquivoCandidatos);
      scanner.nextLine();

      String auxiliar;
      String[] vetorDadosCandidato;

      while (scanner.hasNextLine()) {
        auxiliar = scanner.nextLine();
        vetorDadosCandidato = auxiliar.split(",");

        Candidato candidato = new Candidato(vetorDadosCandidato);

        if (candidato.verificaDestinoVoto()) {

          listaDeCandidatosValidos.add(candidato);
        }
      }
      scanner.close();
      Collections.sort(listaDeCandidatosValidos);

      // -------------------------LENDO PARTIDO------------------------------------
      try {

        List<Partido> listaDePartidos = new ArrayList<Partido>();
        File ArquivoPartido = new File(args[1]);
        scanner = new Scanner(ArquivoPartido);
        scanner.nextLine();

        String[] vetorDadosPartido;

        while (scanner.hasNextLine()) {
          auxiliar = scanner.nextLine();
          vetorDadosPartido = auxiliar.split(",");

          Partido partido = new Partido(vetorDadosPartido, listaDeCandidatosValidos);

          listaDePartidos.add(partido);
        }
        Collections.sort(listaDePartidos);
        scanner.close();

        // // --------------------------IMPRIMINDO LISTAS---------------------
        try {
          String dataEleicao = args[2];
          try {
            Eleicao eleicao = new Eleicao(listaDeCandidatosValidos, listaDePartidos, dataEleicao);
            System.out.printf("Número de vagas: %d\n", eleicao.getNumeroTotalEleitos());
            eleicao.imprimeCandidatosEleitos();
            eleicao.imprimeListaCandidatosMaisVotadosPorLimiteVagas();
            eleicao.imprimeCandidatosBeneficiadosVotacaoMajoritaria();
            eleicao.imprimeCandidatosBeneficiadosVotacaoProporcional();
            eleicao.imprimeListaPartidos();
            eleicao.ordenaPrimeiroUltimoListaPartido();

            eleicao.imprimeCandidatosPorIdade();
            eleicao.imprimeCandidatosPorSexo();
            System.out.println();
            eleicao.imprimeVotosTotaisEleicao();
            System.out.println();
            System.out.println();

          } catch (Exception e) {
            System.out.println(e);

          }
        } catch (Exception e) {
          System.out.println("Não foi possivel ler a data da eleicao! ");
        }

      } catch (Exception e) {
        System.out.println("Não foi possivel abrir o arquivo: " + args[1]);

      }
    } catch (Exception e) {
      System.out.println("Não foi possivel abrir o arquivo: " + args[0]);

    }
  }
}