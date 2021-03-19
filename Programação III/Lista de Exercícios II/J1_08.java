import java.util.Scanner;

class Funcionario {
  private String nome;
  private float salario;
  private String dataAdmissao;

  public String getDataAdmissao() {
    return dataAdmissao;
  }

  public void setDataAdmissao(String dataAdmissao) {
    this.dataAdmissao = dataAdmissao;
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public float getSalario() {
    return salario;
  }

  public void setSalario(float salario) {
    this.salario = salario;
  }
}

class Departamento {
  private String nome;
  private Funcionario[] funcionarios;

  public Funcionario[] getFuncionarios() {
    return funcionarios;
  }

  public void setFuncionarios(Funcionario[] funcionarios) {
    this.funcionarios = funcionarios;
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setFuncionarioNumDepartamento(Funcionario funcionario, int posicao) {

    this.funcionarios[posicao] = funcionario;
  }

  public float somaSalarios() {
    float soma = 0.0f;
    for (Funcionario funcionario : this.funcionarios) {
      soma += funcionario.getSalario();
    }

    return soma;
  }

  public void aumentaSalarios() {
    for (Funcionario funcionario : this.funcionarios) {
      funcionario.setSalario((funcionario.getSalario()) * 1.1f);
    }
  }

  public int calculaQuantidadeFuncionarios() {
    int i = 0;
    for (Funcionario funcionario : this.funcionarios) {
      i++;
    }
    return i;
  }
}

class Empresa {
  private String nome;
  private String cnpj;
  private Departamento[] departamentos;

  public String getCnpj() {
    return cnpj;
  }

  public void setCnpj(String cnpj) {
    this.cnpj = cnpj;
  }

  public Departamento[] getDepartamentos() {
    return departamentos;
  }

  public void setDepartamentos(Departamento[] departamentos) {
    this.departamentos = departamentos;
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setDepartamentoNumaEmpresa(Departamento departamento, int posicao) {
    this.departamentos[posicao] = departamento;
  }

}

public class J1_08 {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    Empresa empresa = new Empresa();
    empresa.setNome(scan.next());
    empresa.setCnpj(scan.next());

    System.out.println(empresa.getNome());
    System.out.println(empresa.getCnpj());

    Departamento[] departamentos = new Departamento[scan.nextInt()];
    empresa.setDepartamentos(departamentos);

    for (int i = 0; i < departamentos.length; i++) {
      Departamento departamento = new Departamento();
      empresa.setDepartamentoNumaEmpresa(departamento, i);

      departamento.setNome(scan.next());

      Funcionario[] funcionarios = new Funcionario[scan.nextInt()];
      departamento.setFuncionarios(funcionarios);

      for (int j = 0; j < funcionarios.length; j++) {
        Funcionario funcionario = new Funcionario();
        departamento.setFuncionarioNumDepartamento(funcionario, j);
        funcionario.setNome(scan.next());
        funcionario.setSalario(scan.nextFloat());
        funcionario.setDataAdmissao(scan.next());
      }
    }

    // aumentando 10% no salário
    Departamento primeiroDepartamento = empresa.getDepartamentos()[0];
    primeiroDepartamento.aumentaSalarios();

    // transferindo primeiro funcionario para o segundo departamento
    Departamento segundoDepartamento = empresa.getDepartamentos()[1];

    Funcionario primeiroFuncionario = primeiroDepartamento.getFuncionarios()[0];

    int posicao = segundoDepartamento.calculaQuantidadeFuncionarios();

    segundoDepartamento.setFuncionarioNumDepartamento(primeiroFuncionario, posicao);

    scan.close();

  }
}