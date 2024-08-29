#ifndef _PESSOA_HPP
#define _PESSOA_HPP

#include <iostream>
using namespace std;

class Pessoa{
  private:
    string nome, endereco;
    Pessoa *prox;

  public: 
    Pessoa(string n, string e);
    void defineProx(Pessoa *p);
    Pessoa *obtemProx();
    void imprime();
    string obtemNome();
    string obtemEndereco();
};
#endif
