// SUBCLASSE (derivada de Aluno)
#ifndef _ALUNOREGULAR_HPP
#define _ALUNOREGULAR_HPP
#include "Aluno.hpp"

class AlunoRegular : public Aluno {
  public:
    AlunoRegular(int m, string n, string c, int s);
    double mensalidade(int parcela);
};
#endif