// AlunoFinanciado.cpp (Roland Teodorowitsch; 28 out. 2019)
#include <sstream>
#include "AlunoFinanciado.hpp"

AlunoFinanciado::AlunoFinanciado(int m, string n, string c, int s, int ai) : Aluno(m,n,c,s) {
  anoIngresso = ai;
}

int AlunoFinanciado::obtemAnoIngresso() {
  return anoIngresso;
}

string AlunoFinanciado::toString() {
  stringstream ss;
  ss << Aluno::toString() << endl; // chama o str de aluno para acrecentar o ano do ingresso
  ss << "- ingresso: " << anoIngresso;
  return ss.str();
}

double AlunoFinanciado::saldoDevedor(int ano) {
  int dif = ano - anoIngresso;
  return dif * 12 * valorMensal;
}