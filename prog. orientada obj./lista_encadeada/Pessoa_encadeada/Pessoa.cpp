#include "Pessoa.hpp"

Pessoa::Pessoa(string n, string e){
  nome = n;
  endereco = e;
}

void Pessoa::defineProx(Pessoa *p){
  prox = p;
}

Pessoa *Pessoa::obtemProx(){
  return prox;
}

void Pessoa::imprime(){
  cout << "Pessoa: " << nome;
  cout << "  -  " << endereco << endl;
}

string Pessoa::obtemNome(){
  return nome;
}

string Pessoa::obtemEndereco(){
  return endereco;
}
