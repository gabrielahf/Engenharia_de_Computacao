#include <iostream>
#include <fstream>
#include <sstream>
#include "Aplicacao.hpp"

using namespace std;

  Aplicacao::Aplicacao(){
    numFilmes = 0;
    for (int i = 0; i < MAX_FILMES; i++) {filmes[i] = nullptr;}
    numCinemas = 0;
    for (int i = 0; i < MAX_CINEMAS; i++) {cinemas[i] = nullptr;}
    numProgramacao = 0;
    for (int i = 0; i < MAX_PROGRAMACAO; i++) {programacao[i] = nullptr;}

  } // Primeira etapa
  Aplicacao::~Aplicacao(){
    for (int i = 0; i <= numFilmes; i++) {delete filmes[i];}
    for (int i = 0; i <= numCinemas; i++) {delete cinemas[i];}
    for (int i = 0; i <= numProgramacao; i++) {delete programacao[i];}
  }
  bool Aplicacao::carregaFilmes(string nomeArquivo){
    numFilmes = 0;

    ifstream arqi;
    arqi.open(nomeArquivo, ios::in);
    if(!arqi.is_open()) { salvaFilmes("filmes.txt.out"); return false; }

    while(1){
        filmes[numFilmes] = new Filme();
        arqi >> *filmes[numFilmes];
        
        if(!arqi.good()) break;
        ++numFilmes;
   }
    arqi.close();
    return true;
}  

  bool Aplicacao::salvaFilmes(string nomeArquivo){
    ofstream arqo;
    arqo.open(nomeArquivo, ios::out);
    if(!arqo.is_open()) return false;

    for(int i = 0; i < numFilmes; i++){ arqo << *filmes[i];}
    arqo.close();
    return true;
}
  void Aplicacao::mostraFilmes(){
     for(int i = 0; i < numFilmes; i++){ cout << filmes[i]->str() << endl;}
  }
  void Aplicacao::ordenaFilmes(){
    for (int i = 1; i < numFilmes ; ++i) {
        Filme *base = filmes[i];
        int j = i -1;
        while ( j >=0 && base->operator<(*filmes[j])) {
            filmes[j +1] = filmes[j];
            --j;
        }

    filmes[j +1] = base;
    }
  }
  Filme *Aplicacao::obtemFilme(int id){
    for(int i = 0; i < numFilmes; i++){
        if(filmes[i]->obtemNumero() == id) return filmes[i];
    }
    return nullptr;
  }

  bool Aplicacao::carregaCinemas(string nomeArquivo){
    numCinemas = 0;
     
    ifstream arqci;
    arqci.open(nomeArquivo, ios::in);

    if(!arqci.is_open()){ salvaCinemas("cinemas.txt.out"); return false; } 

    while(1){
        cinemas[numCinemas] = new Cinema();
        arqci >> *cinemas[numCinemas];
        
        if(!arqci.good()) break;
        ++numCinemas;
    }

    arqci.close();
    return true;
  }// Segunda etapa
  bool Aplicacao::salvaCinemas(string nomeArquivo){
     ofstream arqco;
    arqco.open(nomeArquivo, ios::out);
    if(!arqco.is_open()) return false;

    for(int i = 0; i < numCinemas; i++){
        arqco << *cinemas[i];
    }

    arqco.close();
    return true;
  }
  void Aplicacao::mostraCinemas(){
    for(int i = 0; i < numCinemas; i++){ cout << cinemas[i]->str() << endl;}
  }
  void Aplicacao::ordenaCinemas(){
     for (int i = 1; i < numCinemas ; ++i) {
        Cinema *base = cinemas[i];
        int j = i -1;
        while ( j >=0 && base->operator<(*cinemas[j])) {
            cinemas[j +1] = cinemas[j];
            --j;
        }

    cinemas[j +1] = base;
    }
  }
  Cinema *Aplicacao::obtemCinema(int id){
    for(int i = 0; i < numCinemas; i++){
        if(cinemas[i]->obtemNumero() == id) return cinemas[i];
    }
    return nullptr;
  }

  bool Aplicacao::carregaProgramacao(string nomeArquivo){
    numProgramacao = 0;
    ifstream arqpi;
    string line;
    arqpi.open(nomeArquivo, ios::in);
    if(!arqpi.is_open()) return false;

    while(arqpi.good()){
        programacao[numProgramacao] = new Programacao();

        if(getline(arqpi, line))
            programacao[numProgramacao]->defineCinema(obtemCinema(stoi(line)));

        if(getline(arqpi, line)) 
            programacao[numProgramacao]->defineSala(stoi(line));
        
        if(getline(arqpi, line))
            programacao[numProgramacao]->defineFilme(obtemFilme(stoi(line)));
        
        if(getline(arqpi, line))programacao[numProgramacao]->defineTipoDeExibicao(stoi(line));

        getline(arqpi, line);
        programacao[numProgramacao]->defineHorarios(line);
        
        if(!arqpi.good()) break;
        ++numProgramacao;
   }

    arqpi.close();
    return true;

}

void Aplicacao::mostraProgramacao(){
    string nome;
    int sala;

    for(int i = 0; i < numCinemas; ++i){
        cout << cinemas[i]->obtemNome() << endl << endl;
        sala = cinemas[i]->obtemSalas();

        for (int s = 1; s <= sala; ++s){
            for(int p = 0; p < numProgramacao; ++p){
                if(cinemas[i] == programacao[p]->obtemCinema() && programacao[p]->obtemSala() == s) {
                        cout << programacao[p]->str(false) << endl;
                }    
            }
        }

        cout << endl;
    }
}