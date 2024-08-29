// main.cpp (Roland Teodorowitsch; 22 set. 2019)

#include <fstream>
#include <iostream>
#include "Ponto.hpp"

using namespace std;

//lendo um arquivo texto
int main() {
  int numPontos; // no exemplo ele atribui o valor 5 
  double x, y; // abcissa e ordenada
  ifstream arq; // cria input file stream

  arq.open("pontos.txt", ios::in); // abre o arquivo
  if (!arq.is_open())// se houver erro, sai do programa
     return 1;
  arq >> numPontos;
  Ponto *pontos = new Ponto[numPontos]; //faz a alocação de memoria p/ um objeto da classe Ponto com a variavel 'numPontos'  
  for (int i=0; i<numPontos; ++i) {
      arq >> x;
      arq >> y;
      pontos[i].defineX(x);
      pontos[i].defineY(y);
  }
  arq.close(); //fecha o arquivo
  double dTotal = 0.0;
  for (int i=0;i<numPontos-1;++i)
      dTotal += distancia(pontos[i], pontos[i+1]); // calcular a distancia total
  cout << dTotal << endl;
  return 0;
}