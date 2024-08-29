#include <iostream>
#include "Stack.hpp"

using namespace std;

void print(Stack<int> &stack) {
  cout << "  " << stack.str() << "  size=" << stack.size() << "/"  << "  top=";
  int t;   bool res = stack.top(t);
  if (res) cout << t; else cout << "X";
  cout << "  isEmpty=" << stack.isEmpty() << "  isFull=" << stack.isFull() << endl;
}

int main() {
  int e;
  bool res; //alterar
  cout << "Stack(4): ";  Stack stack(4);  print(stack);
  e = 1;  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 2;  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 3;  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 4;  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  e = 5;  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  e = 6;  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(" << e << "):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  res = stack.pop(e); cout << "pop(X):  ";  cout << (res?"OK  ":"ERRO");  print(stack);
  e = 7;  cout << "push(" << e << "): "; res = stack.push(e);  cout << (res?"OK  ":"ERRO"); print(stack);
  cout << "clear(): OK  ";  stack.clear();  print(stack);
  return 0;
}

