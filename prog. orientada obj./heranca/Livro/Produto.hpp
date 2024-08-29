// SUPERCLASSE (base de AlunoFinanciado e AlunoRegualar)
#ifndef _PRODUTO_HPP
#define _PRODUTO_HPP
#include <string>

using namespace std;

class Produto {
  private:
    string nome;
    double precoBase;
    int paginas;
    int ano;
    Promocao *promocao;
    
  public:
    Produto();
    Produto(string n, double p, int ano, int pg);
    ~Produto();
    Promocao *obtemPromocao();
    string obtemNome();
    int obtemAno();
    int obtemPaginas();
    double obtemPrecoBase();
    double obtemPrecoFinal();
    double obtemPromocao();
    void defineAno(int ano);
    void definePaginas(int pg);
    void defineNome(string n);
    void definePrecoBase(double p);
    string str();

};
#endif