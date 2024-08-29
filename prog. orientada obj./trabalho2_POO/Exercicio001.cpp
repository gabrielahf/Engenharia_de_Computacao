#include <iostream>
#include <sstream>
#include <string>	
#include <vector>
#include <algorithm>

using namespace std;


class Filme {
private:
  int numero;
  string titulo;
  int faixaEtaria;
  string estilo;
public:
  Filme(int n=-1, string t="", int f=-1, string e="");
  ~Filme();
  int obtemNumero() const;
  string obtemTitulo() const;
  int obtemFaixaEtaria() const;
  string obtemEstilo() const;
  string str() const;
  void defineNumero(int n);
  void defineTitulo(string t);
  void defineFaixaEtaria(int f);
  void defineEstilo(string e);
  bool operator<(const Filme &f) const;
  
};


  Filme::Filme(int n, string t, int f, string e): numero(n), titulo(t), faixaEtaria(f), estilo(e){}


  Filme::~Filme(){}


  int Filme::obtemNumero() const{return numero;}


  string Filme::obtemTitulo() const{return titulo;}


  int Filme::obtemFaixaEtaria() const{return faixaEtaria;}


  string Filme::obtemEstilo() const{return estilo;}


  string Filme::str() const{
    stringstream ss;
    ss << titulo << " [" << numero << "] - ";
    
    if(faixaEtaria > 0) ss << faixaEtaria << " anos";
    else ss  << "LIVRE";

    ss << " - " << estilo;
    return ss.str();
  }


  void Filme::defineNumero(int n){numero = n;}


  void Filme::defineTitulo(string t){titulo = t;}


  void Filme::defineFaixaEtaria(int f){faixaEtaria = f;}

 
  void Filme::defineEstilo(string e){estilo = e;}


  bool Filme::operator<(const Filme &f) const{
    if (titulo < f.obtemTitulo()){return true;}
    return false;
  }

   vector<string> splitCSV(string linha, char separador=';') {
    vector<string> res;
    string campo = "";

    for (int i=0; i < linha.size(); ++i) {
        char c = linha.at(i);
        if (c == separador) {
            res.push_back(campo);
        campo = "";
    }
    else
        campo.append(1,c);
    }
    res.push_back(campo);
    return res;
}

int main(){
    
    vector<Filme>lista; //conteiner
    string linha;

    while(getline(cin,linha)){
        vector<string>campos = splitCSV(linha,';');
        int numero = stoi(campos[0]); //converte tipo de variavel
        //string titulo = campos[1];
        int faixaEtaria = stoi(campos[2]);
        //string estilo = campos[3];
        

        lista.push_back(Filme(numero,campos[1],faixaEtaria,campos[3]));
    }
        sort(lista.begin(),lista.end()); //usar biblioteca algorithm

        for(int i = 0; i < lista.size(); i++ ){ //imprime a lista de filmes
        cout << lista[i].str() << endl;
    }
    
        return 0;
}  

