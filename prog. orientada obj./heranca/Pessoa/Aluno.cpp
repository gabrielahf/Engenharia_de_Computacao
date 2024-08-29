#include <sstream>
#include "Aluno.hpp"

Aluno::Aluno(long matricula, double ano){
    matricula = 0;
    ano = 0.0;
}
void Aluno::defineMatricula(long matricula){Matricula = matricula;}
void Aluno::defineAnoIngresso(double ano){AnoIngresso = ano;}
long Aluno::obtemMatricula(){return Matricula;}
double Aluno::obtemAnoIngresso(){return AnoIngresso;}
string Aluno::toString(){
    stringstream ss;
    ss << Pessoa::toString() << endl;
    ss << "Matricula: " << Matricula << endl;
    ss << "Ano Ingresso: " << AnoIngresso << endl;
    return ss.str();
}