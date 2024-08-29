// Aluno.cpp (Roland Teodorowitsch; 27 out. 2019)
#include <sstream>
#include "Aluno.hpp"

Aluno::Aluno(int m, string n, string c, int s) {
  matricula = m;
  nome = n;
  curso = c;
  semestre = s;
}

int Aluno::obtemMatricula() {
  return matricula;
}

string Aluno::obtemNome() {
  return nome;
}

string Aluno::obtemCurso() {
  return curso;
}

int Aluno::obtemSemestre() {
  return semestre;
}

string Aluno::toString() {
  stringstream ss;
  ss << "Aluno: " << nome << endl;
  ss << "- matricula: " << matricula << endl;
  ss << "- curso: " << curso << endl;
  ss << "- semestre: " << semestre;
  return ss.str();
}