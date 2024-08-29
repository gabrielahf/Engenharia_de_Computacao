//Pais.cpp (Roland Teodorowitsch; 22 set. 2019)

#include <sstream>
#include "Pais.hpp"

void Pais::calculaDensidade() {
  if (area != 0.0)
     densidade = populacao / area;
  else
     densidade = 0.0;
}

Pais::Pais(string n,string c, double a, int p) {
  nome = n;
  capital = c;
  area = a;
  populacao = p;
  calculaDensidade();
}

string Pais::obtemNome() {
  return nome;
}

void Pais::defineNome(string n) {
  nome = n;
}

string Pais::obtemCapital() {
  return capital;
}

void Pais::defineCapital(string c) {
  capital = c;
}

double Pais::obtemArea() {
  return area;
}

void Pais::defineArea(double a) {
  area = a;
  calculaDensidade();
}

int Pais::obtemPopulacao() {
  return populacao;
}

void Pais::definePopulacao(int p) {
  populacao = p;
  calculaDensidade();
}

double Pais::obtemDensidade() {
  return densidade;
}

string Pais::toString() {
  stringstream ss;
  ss << nome;
  ss << " - capital = " << capital;
  ss << " - area = " << area;
  ss << " - populacao = " << populacao;
  ss << " - densidade = " << densidade;
  return ss.str();
}