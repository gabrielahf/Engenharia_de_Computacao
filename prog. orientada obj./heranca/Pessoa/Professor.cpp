#include <sstream>
#include <string>
#include "Professor.hpp"

Professor::Professor(string u, double ano, double salario){
    u = "";
    ano = 0.0;
    salario = 0.0;
}
void Professor::defineUnidade(string u){unidade = u;}
void Professor::defineAnoIngresso(double ano){AnoIngresso = ano;}
void Professor::defineSalarioFixo(double salario){SalarioFixo = salario;}
string Professor::obtemUnidade(){return unidade;}
double Professor::obtemAnoIngresso(){return AnoIngresso;}
double Professor::obtemSalarioFixo(){return SalarioFixo;}
string Professor::toString(){
    stringstream ss;
    ss << Pessoa::toString() << endl;
    ss << "Unidade: " << unidade << endl;
    ss << "Ano Ingresso: " << AnoIngresso << endl;
    ss << "Salario Fixo: " << SalarioFixo << endl;
    return ss.str();
}