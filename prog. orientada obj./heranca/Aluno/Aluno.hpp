// SUPERCLASSE (base de AlunoFinanciado e AlunoRegualar)
#ifndef _ALUNO_HPP
#define _ALUNO_HPP
#include <string>

using namespace std;

class Aluno {
  private:
    int matricula;
    string nome;
    string curso;
    int semestre;
  public:
    const double valorMensal = 500.0;
    Aluno(int m, string n, string c, int s);
    int obtemMatricula();
    string obtemNome();
    string obtemCurso();
    int obtemSemestre();
    string toString();
};
#endif