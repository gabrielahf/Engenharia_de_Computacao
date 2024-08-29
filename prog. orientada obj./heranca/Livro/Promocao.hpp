// SUPERCLASSE (base de AlunoFinanciado e AlunoRegualar)
#ifndef _PROMOCAO_HPP
#define _PROMOCAO_HPP

#include <string>
#include "Produto.hpp"

using namespace std;

class Promocao : public Produto {
  private:
    double percDesconto;
    double nomePromocao;
  public:
    Promocao(double pD = 0.0, string nomePromocao = "");
    ~Promocao();
    void definePromocao(string nomePromocao);
    void definePercDesconto(double pD);
    double obtemPercDesconto();
    double obtemPromocao();

};
#endif