// AlunoRegular.cpp (Roland Teodorowitsch; 28 out. 2019)
#include "AlunoRegular.hpp"

AlunoRegular::AlunoRegular(int m, string n, string c, int s) : Aluno(m,n,c,s) {}

double AlunoRegular::mensalidade(int parcela) {
  if (parcela>=1 && parcela<=3)
     return valorMensal * 1.2;
  return valorMensal;
}