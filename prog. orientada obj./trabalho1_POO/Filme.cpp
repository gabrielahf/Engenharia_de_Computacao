#include <iostream>
#include <sstream>
#include "Filme.hpp"

using namespace std;

  Filme::Filme(int n, string t, int f, string e): numero(n), titulo(t), faixaEtaria(f), estilo(e){}
  Filme::~Filme(){}
  int Filme::obtemNumero() const{return numero;}
  string Filme::obtemTitulo() const{return titulo;}
  int Filme::obtemFaixaEtaria() const{return faixaEtaria;}
  string Filme::obtemEstilo() const{return estilo;}
  string Filme::str() const{
    stringstream ss;
    ss << titulo << " [" << numero << "] - ";
    
    if(faixaEtaria > 0) ss << faixaEtaria << " anos";
    else ss  << "LIVRE";

    ss << " - " << estilo;
    return ss.str();
  }
  void Filme::defineNumero(int n){numero = n;}
  void Filme::defineTitulo(string t){titulo = t;}
  void Filme::defineFaixaEtaria(int f){faixaEtaria = f;}
  void Filme::defineEstilo(string e){estilo = e;}
  bool Filme::operator<(const Filme &f) const{
    if (titulo < f.obtemTitulo()){return true;}
    return false;
  }

    istream& operator>>(istream& in, Filme& f) {
    string line;

    if (getline(in, line)) {
        f.numero = stoi(line);
    } else {return in;}

     (getline(in, f.titulo));

    if (getline(in, line)) {
        f.faixaEtaria = stoi(line);
    } else {return in;}

    (getline(in, f.estilo));

    return in;
}

  ostream &operator<<(ostream &out,const Filme &f){
    out << f.obtemNumero() << endl;
    out << f.obtemTitulo() << endl;
    out << f.obtemFaixaEtaria() << endl;
    out << f.obtemEstilo() << endl;

    return out;
  }
