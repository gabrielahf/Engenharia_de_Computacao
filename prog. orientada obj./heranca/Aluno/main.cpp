// main.cpp (Roland Teodorowitsch; 28 out. 2019)
#include <iostream>
#include "AlunoRegular.hpp"
#include "AlunoFinanciado.hpp"

int main() {
  AlunoRegular    a1(100001,"Beatriz Silva","4/600",8);
  AlunoFinanciado a2(100002,"Augusto Alcantara","4/450",6,2017);
  cout << a1.toString() << endl;
  cout << "- mensalidades:";
  for (int i=1; i<=6; ++i)
      cout << " " << a1.mensalidade(i);
  cout << endl;
  cout << a2.toString() << endl;
  cout << "- saldo devedor: " << a2.saldoDevedor(2019) << endl;
  return 0;
}