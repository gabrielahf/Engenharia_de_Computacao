#ifndef _ALUNO_HPP
#define _ALUNO_HPP
#include "Pessoa.hpp"

class Aluno : public Pessoa {
  private:
    long Matricula;
    double AnoIngresso;

  public:
    Aluno(long matricula, double ano);
    void defineMatricula(double matricula);
    void defineAnoIngresso(double ano);
    long obtemMatricula();
    double obtemAnoIngresso();
    string toStirng();
};
#endif