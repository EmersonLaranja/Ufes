#include "professor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professor
{
  int siape;
  char *nome;
  float salario;
};

Professor *InicializaProfessor(int siape, char *nome, float salario)
{
  Professor *novo = (Professor *)malloc(sizeof(Professor));
  novo->nome = strdup(nome);
  novo->siape = siape;
  novo->salario = salario;
  return novo;
}

void ImprimeProfessor(Professor *professor)
{
  printf("Siape %d, Nome: %s, Salario: %.2f\n", professor->siape, professor->nome, professor->salario);
}

int RetornaSiape(Professor *professor)
{
  return professor->siape;
}

char *RetornaNomeProfessor(Professor *professor)
{
  return professor->nome;
}

float RetornaSalario(Professor *professor)
{
  return professor->salario;
}

void DestroiProfessor(Professor *professor)
{
  free(professor->nome);
  free(professor);
}