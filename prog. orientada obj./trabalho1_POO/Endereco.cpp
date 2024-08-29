#include <iostream>
#include <sstream>
#include "Endereco.hpp"

using namespace std;

  Endereco::Endereco(string l, int n, string c, string b, string cp, string cd, string e): logradouro(l), numero(n), complemento(c), bairro(b), cep(cp), cidade(cd), estado(e){}
  Endereco::~Endereco(){}
  string Endereco::obtemLogradouro() const{return logradouro;}
  int Endereco::obtemNumero() const{return numero;}
  string Endereco::obtemComplemento() const{return complemento;}
  string Endereco::obtemBairro() const{return bairro;}
  string Endereco::obtemCEP() const{return cep;}
  string Endereco::obtemCidade() const{return cidade;}
  string Endereco::obtemEstado() const{return estado;}
  string Endereco::str() const{
   stringstream ss;
    ss << logradouro << "," << numero << "-" << complemento << "-Bairro" << bairro << cidade << "-" << estado;
    return ss.str();
  }
  void Endereco::defineLogradouro(string l){logradouro = l;}
  void Endereco::defineNumero(int n){numero = n;}
  void Endereco::defineComplemento(string c){complemento = c;}
  void Endereco::defineBairro(string b){bairro = b;}
  void Endereco::defineCEP(string cp){cep = cp;}
  void Endereco::defineCidade(string cd){cidade = cd;}
  void Endereco::defineEstado(string e){estado = e;}
  istream &operator>>(istream &in,Endereco &e){
    string line;

    getline(in, e.logradouro);

    if (getline(in, line)) {
        e.numero = stoi(line);
    } else {return in;}

    getline(in, e.complemento);
    getline(in, e.bairro);
    getline(in, e.cep);
    getline(in, e.cidade);
    getline(in, e.estado);

    return in;
  }
  ostream &operator<<(ostream &out,const Endereco &e){
    out << e.logradouro << endl;
    out << e.numero << endl;
    out << e.complemento << endl;
    out << e.bairro << endl;
    out << e.cep << endl;
    out << e.cidade << endl;
    out << e.estado << endl;

    return out;
  }

