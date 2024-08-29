#include <iostream>
#include <sstream>
#include <string>
#include "Cinema.hpp"

using namespace std;

  Cinema::Cinema() {
    numero = 0;
    salas = 0;
    nome = "";
  }
  Cinema::Cinema(int n, string nm, Endereco &e, int s): numero(n), nome(nm), endereco(e), salas(s){}
  Cinema::~Cinema(){}
  int Cinema::obtemNumero() const{return numero;}
  string Cinema::obtemNome() const{return nome;}
  Endereco Cinema::obtemEndereco() const{return endereco;}
  int Cinema::obtemSalas() const{return salas;}
  string Cinema::str() const{
     stringstream ss;

    ss << nome << " [" << numero << "]" << endl << endereco.str() << endl << "Cinema(s): " << salas << endl;

    return ss.str();
  }
  void Cinema::defineNumero(int n){numero = n;}
  void Cinema::defineNome(string nm){nome = nm;}
  void Cinema::defineEndereco(Endereco &e){endereco = e;}
  void Cinema::defineSalas(int s){salas = s;}
  bool Cinema::operator<(const Cinema &c) const{
    if (nome < c.obtemNome()){return true;}
    return false;
  }
  istream &operator>>(istream &in,Cinema &c){
    string line;
    if (getline(in, line)) {
        c.numero = stoi(line);
    } else {return in;}

    getline(in, c.nome);

    in >> c.endereco;

    if (getline(in, line)) {
        c.salas = stoi(line);
    } else {return in;}

    return in;
  }
  ostream &operator<<(ostream &out,const Cinema &c){
    out << c.numero << endl;
    out << c.nome << endl;
    out << c.endereco << endl;
    out << c.salas << endl;

    return out;
  }

