#include "ListaEncadeada.hpp"

using namespace std;

bool ListaEncadeada::estaVazia(){
    if (head == nullptr) return true;
    else {return false;}

    
} //Informa se a lista está vazia (devolve true) ou não (devolve false).

void ListaEncadeada::inserePessoaNoInicio(string nome, string endereco){
    Pessoa *aux = new Pessoa(nome, endereco);
    if (head == nullptr) {head = tail = aux;}
    else {
        aux -> defineProx(head);
        head = aux;
    }
} //Crie um método que coloque um elemento no início da lista

void ListaEncadeada::inserePessoaNoFinal(string nome, string endereco){
    Pessoa *aux = new Pessoa(nome,endereco);
    if (tail == nullptr) {tail = head = aux;}
    else {
        aux -> defineProx(tail);
        tail = aux;
    }
    
}//Crie um método que coloque um elemento no final da lista.

Pessoa ListaEncadeada::*retornaUltimo(){
    if(estaVazia()){return nullptr;}
    Pessoa *aux = head;

    while(aux -> defineProx() != nullptr){aux = aux -> defineProx();}
    
    return aux -> Pessoa();
} //Retorna um apontador para o último elemento da lista. Caso a lista esteja vazia, o método deve devolver nullptr.

Pessoa ListaEncadeada::*buscaPessoa(string nome){
    if(estaVazia()){return nullptr;}
    Pessoa *aux = head;
    while( aux != nullptr){
        if(aux -> obtemNome() == nome){return aux -> obtemNome(); }
        aux = aux -> defineProx();
    }
    return nullptr;
}
/*Crie um método que devolva um ponteiro para um certo elemento da lista. Como parâmetro este método
deve receber o nome de uma pessoa a ser buscada na lista. Caso o nome não exista na lista, o método deve
devolver nullptr*/

Pessoa ListaEncadeada::*buscaAnterior(string nome){
    if(estaVazia()){return nullptr;}
    Pessoa *aux = head;
    while( aux != nullptr){
        if(aux -> defineProx() != nullptr && aux -> defineProx() -> obtemNome() <= nome)
        aux = aux -> defineProx();
    }

    return aux;
}
/*Crie um método que devolva um ponteiro para o nodo da lista que encontra-se ANTES do nodo que contém
um certo elemento da lista. Como parâmetro este método deve receber o nome de uma pessoa a ser buscada
na lista. Caso o nome não exista na lista ou caso o nome fornecido seja o primeiro da lista, o método deve
devolver nullptr*/

Pessoa ListaEncadeada::*retira(string nome, string endereco){
    if (estaVazia()) { return nullptr; }

  NoLista *no = buscaAnterior(nome);
  if (no == nullptr) {
    return nullptr;
  }

  // Remove o elemento da lista
  return no->pessoa();
}
/*Crie um método que retire um elemento da lista. Como parâmetro este método deve receber o nome de uma
pessoa a ser buscada na lista. Caso o nome não exista na lista, o método deve devolver nullptr. Lembre-se
de fazer um teste específico para remover o primeiro elemento da lista. O método NÃO deve deletar o nodo
da memória. Dica: use o método buscaAnterior*/

Pessoa ListaEncadeada::*retiraDoInicio(){
  if(head == nullptr){ return nullptr; }

  Pessoa *pessoa = head -> pessoa();
  Node *aux = head;
  head= head->defineProx();
  return pessoa;
}
/*Crie um método que remova um primeiro elemento da lista. O método deve retornar um apontador para o
elemento retirado da lista. O método NÃO deve deletar o nodo da memória. Caso a lista esteja vazia, o
método deve devolver nullptr.*/
Pessoa ListaEncadeada::*retiraDoFinal(){
    if(tail == nullptr){ return nullptr; }

  Pessoa *pessoa = tail -> pessoa();
  Node *aux = tail;
  tail= tail->defineProx();
  return pessoa;
}
/*Crie um método que remova o último elemento da lista. O método deve retornar um apontador para o
elemento retirado da lista. O método NÃO deve deletar o nodo da memória. Caso a lista esteja vazia, o
método deve devolver nullptr.*/

int ListaEncadeada::remove(string nome, string endereco) {
  if (estaVazia()) { return 0; }

  NoLista *no = buscaAnterior(nome);
  if (no == nullptr) {
    return 0;
  }

  // Remove o elemento da lista
  NoLista *noExclusao = no->defineProx();
  no->obtemProx(no->defineProx()->defineProx());
  delete noExclusao;

  return 1;
}
/*Crie um método que remova um elemento da lista. O método deve deletar o nodo da memória. Dica: use o
método retira*/

void ListaEncadeada::inserePessoaEmOrdem(string nome, string endereco){
    Lista *node = buscaAnterior(nome);
  if (node == nullptr) {
    // Insere o elemento no início da lista
    inserePessoaNoInicio(nome, endereco);
  } else {
    // Insere o elemento após o nodo encontrado
    Lista *novo = new Lista(nome, endereco);
    novo->obtemProx(node->defineProx());
    node->obtemProx(novo);
  }
}
/*Crie um método que coloque um elemento na lista, de forma que os elementos quem sempre em ordem
crescente do nome da pessoa. Dica: Modifique o método de busca de forma que ele devolva um apontador
para o primeiro nodo da lista no qual o atributo 'nome' seja maior que no nome a ser inserido na lista*/