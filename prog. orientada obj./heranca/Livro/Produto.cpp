#include <sstream>
#include "Produto.hpp"

Produto::Produto(){
    nome = "";
    precoBase = 0.0;
    ano = 0;
    paginas = 0;
}
Produto::Produto(string n, double p, int a, int pg){
    nome = n;
    precoBase = p;
    ano = a;
    paginas = pg;
}
Produto::~Produto(){}
string Produto::obtemNome(){return nome;}
double Produto::obtemPrecoBase(){return precoBase;}
double Produto::obtemPrecoFinal(){
    double pD = 0.0;
    Promocao *promocao = obtemPromocao();
    if(promo){pD = promo -> obtemPercDesconto();}

    return obtemPrecoBase() * (1.0 - pD);
}
double Produto::obtemPromocao(){
    double pD = 0.0;
    Promocao *promocao = obtemPromocao();
    if(promo){pD = promo -> obtemPromocao();}

    return pD;    
}
int Produto::obtemAno(){return ano;}
int Produto::obtemPaginas(){return paginas;}
void Produto::defineAno(int a){ano = a;}
void Produto::definePaginas(int pg){paginas = pg;}
void Produto::defineNome(string n){nome = n;}
void Produto::definePrecoBase(double p){precoBase = p;}
string Produto::str(){
    stringstream ss;
  ss << "Nome: " << nome << endl;
  ss << "- Preco Base: " << precoBase << endl;
  ss << "- Preco Final: " << obtemPrecoFinal() << endl;
  ss << "- Ano: " << ano << endl;
  ss << "- Paginas: " << paginas << endl;

  return ss.str();
}