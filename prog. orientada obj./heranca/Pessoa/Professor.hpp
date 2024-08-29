#ifndef _PROFESSOR_HPP
#define _PROFESSOR_HPP
#include "Pessoa.hpp"

class Professor : public Pessoa {
  private:
    string unidade;
    double AnoIngresso;
    double SalarioFixo;
  public:
    Professor(string u, double ano, double salario);
    void defineUnidade(string u);
    void defineAnoIngresso(double ano);
    void defineSalarioFixo(double salario);
    string obtemUnidade();
    double obtemAnoIngresso();
    double obtemSalarioFixo();
    string toString();
};
#endif