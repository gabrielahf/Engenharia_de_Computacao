#include <iostream>
using namespace std;
class Ponto {
    int x,y;
public:
    Ponto(int x, int y);
    void Set(int x, int y);
    virtual void Imprime();
};
Ponto::Ponto(int x, int y) {
  this->x = x; this->y = y;
}
void Ponto::Imprime() {
  cout << "Imprime da Ponto\n";
}
class Circulo: public Ponto {
    int raio;
public:
    Circulo(int x, int y, int Raio);
    void Imprime();
};
Circulo::Circulo(int a, int b, int r):Ponto (0, 0) {
  raio = r;
}
void Circulo::Imprime() {
  cout << "Imprime da Circulo\n";
}
int main() {
  Circulo C1(111,4,5); // objeto da classe circulo (derivada)
  Ponto P1(2,3); // objeto da classe ponto (base)
  Ponto *Desenhos[4]; // vetor de ponteiros para objetos da classe ponto
  Ponto *Ptr; // ponteiro para objetos da classe ponto

  P1 = C1; // objeto da classe base vai englobar os objetos da classe derivada
  Ptr = &C1; // ponteiro da classe ponto passa a armazenar o endereco do objeto da classe circulo
  Desenhos[0] = new Ponto(4,5); // vetor de ponteiro da classe Ponto passa a alocar novos valores para classe Ponto -- imprimir PONTO
  Desenhos[1] = &P1; // passa a armazenar o endereco do objeto da classe ponto -- imprimir PONTO
  Desenhos[2] = new Circulo(6,2,4); // passa a alocar novos valores para classe Circulo -- CIRCULO
  Desenhos[3] = Ptr; // como Ptr = &C1 -- imprime CIRCULO

  P1.Imprime(); // seleciona os membros para objetos da classe ponto e chama o metodo imprime() -- imprimir PONTO

  for (int i=0;i<4;i++)
      Desenhos[i]->Imprime();// 
  return 0;
}

/*SAIDA
P1.imprime() -- PONTO
Desenhos[0] -- PONTO
Desenhos[1] -- PONTO
Desenhos[2] -- CIRCULO
Desenhos[3] -- CIRCULO
*/