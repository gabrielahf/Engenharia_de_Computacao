#include <iostream>
#include <sstream>
using namespace std;

class StringDoubleLinkedList {
private:
  struct Node {
    string data;
    Node *prev, *next;
    Node(string d) {  data = d;  prev = next = nullptr;  }
  };
  Node *head, *tail;
  Node *find(string s) const {
    Node *aux = head;
    while (aux != nullptr) {
      if ( aux->data == s ) return aux;
      aux = aux->next;
    }
    return nullptr;
  }
public:
  StringDoubleLinkedList() {  head = tail = nullptr;  }
  ~StringDoubleLinkedList() {  
    while (head != nullptr) {  Node *aux = head;  head = head->next;  delete aux; }
  }
  void push_back(string s) {
    Node *aux = new Node(s);
    if ( head == nullptr ) {  head = tail = aux;  }
    else {  aux->prev = tail;  tail->next = aux;  tail = aux;  }
  }
  string str() {
    stringstream ss;
    Node *aux = head;
    while ( aux!=nullptr ) {  ss << aux->data << " ";  aux = aux->next;  }
    return ss.str();
  }
  string reverseStr() {
    stringstream ss;
    Node *aux = tail;
    while ( aux!=nullptr ) {  ss << aux->data << " ";  aux = aux->prev;  }
    return ss.str();
  }
 
void StringDoubleLinkedList::remove(string s) {
  Node *nodo = find(s);
  if ( nodo == nullptr ) return;
  if ( nodo == head ) {
     head = head->next;
     if ( head != nullptr ) head->prev = nullptr;
     else tail = nullptr;
  }
  else {
     Node *prev = nodo->prev; // Sempre haverá um nodo prev
     Node *next = nodo->next; // Nem sempre haverá um nodo next
     prev->next = next;
     if ( next != nullptr ) next->prev = prev;
     else tail = prev;
  }
  delete nodo;
}
};

int main() {
  StringDoubleLinkedList lista;
  lista.push_back("OI");
  lista.push_back("BOM");
  lista.push_back("FALSO");
  lista.push_back("DIA");
  cout << lista.str() << endl;
  cout << lista.reverseStr() << endl;
  lista.remove("FALSO");
  cout << lista.str() << endl;
  cout << lista.reverseStr() << endl;
  lista.remove("OI");
  cout << lista.str() << endl;
  cout << lista.reverseStr() << endl;
  lista.remove("DIA");
  cout << lista.str() << endl;
  cout << lista.reverseStr() << endl;
  lista.remove("BOM");
  cout << lista.str() << endl;
  cout << lista.reverseStr() << endl;
  return 0;
}	