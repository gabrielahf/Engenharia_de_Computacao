#include <sstream>
#include "Pessoa.hpp"

Pessoa::Pessoa(string n, long rg){
    n = "";
    rg = 0;
}
void Pessoa::defineNome(string n){nome = n;}
void Pessoa::defineRG(long rg){RG = rg;}
string Pessoa::obtemNome(){return nome;}
long Pessoa::obtemRG(){return RG;}
string Pessoa::toString(){
    stringstream ss;
    ss << "Nome: " << nome << endl;
    ss << "RG: " << RG << endl;
    return ss.str();
}