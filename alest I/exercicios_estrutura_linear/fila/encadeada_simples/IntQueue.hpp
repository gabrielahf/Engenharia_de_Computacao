#ifndef _INTQUEUE_HPP
#define _INTQUEUE_HPP

#include <string>

using namespace std;

class IntQueue {
private:
  int numElements, maxElements;
  int insertPos, removePos;
  int *queue;
public:
  IntQueue(int mxSz = 10); // maximo de elementos = 10
  ~IntQueue();
  int size() const; // metodo tamanho
  int maxSize() const; // metodo tamanho maximo
  bool isEmpty() const; // metodo verificar se esta vazio
  bool isFull() const; // metodo verificar se esta cheio
  void clear(); // limpar
  bool enqueue(const int e); // inserir
  bool dequeue(int &e); // remover (por referencia)
  bool head(int &e) const; // retorna (por referência) o elemento do início, mas não o remove 
  string str() const; // APENAS PARA DEPURACAO
};
#endif