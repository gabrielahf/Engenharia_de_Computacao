#include "Promocao.hpp"
using namespace std;

    Promocao::Promocao(){
        pD = 0.0;
        promo = "";
    }
    Promocao::Promocao(){
        percDesconto = pD;
        promo = nomePromocao;
    }
    Promocao::~Promocao(){}
    void Promocao::definePromocao(string nomePromocao){promo = nomePromocao;}
    void  Promocao::definePercDesconto(double pD){percDesconto = pD;}
    double  Promocao::obtemPercDesconto(){return percDesconto * 0,70;} // desconto de 30%
    double Promocao::obtemPromocao(){return percDesconto * 0,90;} // desconto de 10%
