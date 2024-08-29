#ifndef _LISTAENCADEADA_HPP
#define _LISTAENCADEADA_HPP

#include <iostream>
using namespace std;

class ListaEncadeada{
  private:
    string nome, endereco;
    Pessoa *prox;

  public: 
    bool estaVazia();
    void inserePessoaNoInicio(string nome, string endereco); 
    void inserePessoaNoFinal(string nome, string endereco); 
    Pessoa *retornaUltimo(); 
    Pessoa *buscaPessoa(string nome);
    Pessoa *buscaAnterior(string nome);
    Pessoa *retira(string nome, string endereco);
    Pessoa *retiraDoInicio();
    Pessoa *retiraDoFinal();
    int remove(string nome, string endereco);
    void inserePessoaEmOrdem(string nome, string endereco);
};
#endif
