#include <sstream>
#include "IntQueue.hpp"

IntQueue::IntQueue(int mxSz) {
  numElements = insertPos = removePos = 0;   maxElements =  ( mxSz < 1 ) ? 10 : mxSz;  queue = new int[maxElements];
}

IntQueue::~IntQueue() {  delete[] queue;  } // adc [] por ser um vetor
int IntQueue::size() const { return numElements; } // tamanho retorna o numero de elementos atual
int IntQueue::maxSize() const { return maxElements; } // tamanho maximo retorna se atingiu o maximo de elementos
bool IntQueue::isEmpty() const { return numElements == 0; } // verifica se nao ha nenhum elemento
bool IntQueue::isFull() const { return numElements == maxElements; } // verifica se o vetor atingiu o numero maximo de elementos
void IntQueue::clear() { numElements = insertPos = removePos = 0; } // limpar os elementos 

bool IntQueue::enqueue(const int e) {
  if ( numElements == maxElements ) return false; // verififcar se o vetor esta cheio
  else { queue[ insertPos++ ] = e;  insertPos %= maxElements;  ++numElements;  return true; }
  /*inserir o elemento na ultima posicao, entretanto se estiver maior que o max de elementos suportados pelo vetor, 
  sera necessario ver o resto da divisao entre o ultimo pelo max de itens */
}

bool IntQueue::dequeue(int &e) {
  if ( numElements == 0 ) return false; // verificar se o vetor esta vazio
  else { e = queue[ removePos++ ];  removePos %= maxElements; --numElements; return true; }
  /* remover o elemento na primeira posicao, entretanto o primeiro elemento pode ter passado 
  do max de elementos suportados pelo vetor, sera necessario verificar a correspondencia de 
  memoria que foi guardado*/
}

bool IntQueue::head(int &e) const {
  if ( numElements < 1 ) return false; 
  else { e = queue[ removePos ];  return true; } 
}

string IntQueue::str() const {
  stringstream ss;   ss << "|";
  for (int i=0; i<maxElements; ++i)
      if ( (removePos == insertPos && numElements != 0) ||
           (removePos < insertPos && (i >= removePos && i < insertPos)) ||
           (removePos > insertPos && (i >= removePos || i < insertPos)) ) ss << queue[i] << "|";
      else ss << " |";
  return ss.str();
}