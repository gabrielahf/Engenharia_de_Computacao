#include <iostream>
#include <sstream>
#include <map>	
#include <vector>
#include <algorithm>
#include <iterator>

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
    vector<Filme> lista;
    string linha;
   
    map<string, int> countEstilo; //cointeiner associativo, busca rapida e sem elem. duplicados
    vector<string> ordemEstilo;

    while (getline(cin, linha)) {
        vector<string> campos = splitCSV(linha, ';');
        int numero = stoi(campos[0]);
        int faixaEtaria = stoi(campos[2]);
        string estilo = campos[3];

        lista.push_back(Filme(numero, campos[1], faixaEtaria, estilo));

        countEstilo[estilo]++; //atualiza o estado atual de estilo

        if (find(ordemEstilo.begin(), ordemEstilo.end(), estilo) == ordemEstilo.end()){
            ordemEstilo.push_back(estilo); //ordenar estilos
        }
    }

    for (int i = 0; i < ordemEstilo.size(); i++) { //imprime a quantidade de estilos
        cout << ordemEstilo[i] << " " << countEstilo[ordemEstilo[i]] << endl;
    }

    return 0;
  
  }

  