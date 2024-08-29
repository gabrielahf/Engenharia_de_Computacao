#ifndef _STACK_HPP
#define _STACK_HPP

#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
class Stack {
private:
  size_t valueMaxSize;
  vector <T> stack;
public:
  Stack(int value = 0);
  ~Stack();
  int size() const;
  bool isEmpty() const;
  void clear();
  void push(const T &e);
  T pop();
  T top() const;
  string str() const; // APENAS PARA DEPURACAO
};


template<typename T>
Stack<T>::Stack(int value = 0){
  if(value != nullptr){
    valueMaxSize = value;
  } else{
    valueMaxSize = stack.max.size();
  }
}

template <typename T>
Stack<T>::~Stack(){}

template <typename T>
int Stack<T>::size()const {return stack.size();}

template <typename T>
bool Stack<T>::isEmpty()const {return stack.empty();}

template <typename T>
void Stack<T>::clear(){stack.clear();}

template <typename T>
void Stack<T>::push(const T &e){
  if(size() >= valueMaxSize) throw "ERRO. NÃO É POSSIVEL ADICIONAR ITEM";
  stack.push_back(e);
}

template <typename T>
T Stack<T>::pop(){
  if(isEmpty()) throw "ERRO. NÃO HÁ ELEMENTOS PARA REMOVER";
  T value = stack.back(); //Recupera o valor do elemento superior na pilha. A expressão stack.back() retorna uma referência ao elemento superior, e a parte T value = atribui esse valor à variável value
  stack.pop();
}

template <typename T>
T Stack<T>::top()const {
  if(isEmpty()) throw "ERRO. PILHA VAZIA";
  stack.back();
}
template <typename T>
string Stack<T>::str() const{
  stringstream ss;

  for(int i = stack.size() -1; i >= 0; i--){
    ss << "|" << stack[i] << "|";
  }

  return ss.str();
}

#endif