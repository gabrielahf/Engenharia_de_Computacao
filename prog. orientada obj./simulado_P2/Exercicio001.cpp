#include <iostream>

using namespace std;

class Ponto {
    int x,y;
  protected:
    void Imprime();
    void Set(int x, int y); 
  public:
    Ponto();
    Ponto(int x, int y);
};
Ponto::Ponto() {
  Set(0,0);
}
Ponto::Ponto(int x, int y) {
  Set(x,y);
}
void Ponto::Set(int x, int y) {
  this->x = x;
  this->y = y;
}
void Ponto::Imprime() {
  cout << "(" << x << "," << y << ")";
}
// ===========================================
class Circulo: public Ponto {
  private:
    int raio;
  public:
    Circulo();
    Circulo(int x, int y, int Raio);
    void Set(int x, int y);
    void Imprime();
};
Circulo::Circulo() : Ponto() {
  raio = 0;
}
Circulo::Circulo(int x, int y, int Raio) : Ponto(x,y) {
  raio = Raio;
}
void Circulo::Set(int x, int y) {
  // [A] Há algum erro aqui? Qual?
  Ponto::Set(x,y); 
  /*Não, código Ponto::Set(x, y); 
  chama o método Set da classe base Ponto na classe derivada Circulo. 
  Isso é permitido porque o método Set é um método protegido da classe base, 
  e as classes derivadas podem acessar membros protegidos da classe base.*/
}
void Circulo::Imprime() {
  // [B] Há algum erro aqui? Qual?
  Ponto::Imprime(); 
/*Não, código Ponto::Imprime(); 
  chama o método Imprime da classe base Ponto na classe derivada Circulo. 
  Isso é permitido porque o método Imprime é um método protegido da classe base, 
  e as classes derivadas podem acessar membros protegidos da classe base.*/

  cout << "," << raio;
}
int main() {
  Circulo C1, *ptrC;
  Ponto P(4,3), *ptrP;
  // [C] Há algum erro aqui? Qual?
  ptrC = &P; 
  /* O ponteiro ptrC é declarado como um ponteiro para um objeto da classe Circulo, 
  mas está sendo atribuído ao endereço de um objeto da classe Ponto (P). 
  Isso viola a hierarquia de herança, pois um ponteiro para a classe derivada não pode apontar para um objeto da classe base. */

  // [D] Há algum erro aqui? Qual?
  ptrP = &C1; // base -> endereco derivada OK
  /* O ponteiro ptrP é declarado como um ponteiro para um objeto da classe Ponto, 
  e está sendo atribuído ao endereço de um objeto da classe Circulo (C1). 
  Logo está correta, pois um ponteiro para a classe base pode apontar para um objeto da classe derivada. */


  // [E] Há algum erro aqui? Qual?
  ptrP->Imprime(); 
  /*em Ponto, a função Imprime() foi definida como protected, 
  o que significa que é privada do ponto de vista de objetos dessa classe, 
  mas pode ser herdada e acessada em funções derivadas*/

  return 0;
}