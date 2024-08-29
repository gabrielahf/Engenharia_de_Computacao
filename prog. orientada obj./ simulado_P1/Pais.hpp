// Pais.hpp (Roland Teodorowitsch; 22 set. 2019)
#ifndef _PAIS_HPP
#define _PAIS_HPP

#include <string>

using namespace std;

class Pais {
  private:
    string nome;
    string capital;
    double area;
    int    populacao;
    double densidade;
    void calculaDensidade();
  public:
    Pais(string n="",string c="", double a=0.0, int p=0);
    string obtemNome();
    void defineNome(string n);
    string obtemCapital();
    void defineCapital(string c);
    double obtemArea();
    void defineArea(double a);
    int obtemPopulacao();
    void definePopulacao(int p);
    double obtemDensidade();
    string toString();
};
#endif