#ifndef _PESSOA_HPP
#define _PESSOA_HPP

#include <string>
#include <sstream>

using namespace std;

class Pessoa {
private:
    string nome;
    long RG;

public:
    Pessoa(string n, long rg);
    void defineNome(string n);
    void defineRG(long rg);
    string obtemNome();
    long obtemRG();
    string toString();
};

#endif