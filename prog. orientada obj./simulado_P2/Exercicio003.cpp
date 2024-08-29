#include <iostream>

using namespace std;

class VetorDinamico {
    int *dados; // ponteiro para a área que armazena os dados.
    int qtd;    // armazena a quantidade atual de dados armazenados no vetor
    int max;    // armazena a quantidade máxima de dados que podem ser armazenados no vetor
  public:
    VetorDinamico(int tamMax); // Deve ser implementado
    ~VetorDinamico();          // Deve ser implementado
    void adiciona(int n);      // Deve ser implementado
    int qtdDados();            // Ja esta implementado
    int getDado(int i);        // Ja esta implementado
};

VetorDinamico::VetorDinamico(int tamMax){
    qtd = 0;
    max = tamMax;
    dados = new int[max];

  
}

VetorDinamico::~VetorDinamico(){delete [] dados;}

void VetorDinamico::adiciona(int n){
  if(qtd == max){ // se nao ha mais espaco
    int novoMax = max * 1.5; // nova variavel para armazenar uma quantidade maxima maior de dados do que a atual (50% a mais de espaco)
    int *novoDado = new int[novoMax]; // novo ponteiro para area q armazena os dados, agora com tamanho maior
   
  for(int i = 0; i < qtd; i++) //percorre os dados armazenados no vetor
      novoDado[i] = dados[i]; // passa as informacoes do dado para o com maior tamanho
      delete [] dados; //desaloca, pois nao sera mais util
      dados = dadoNovo;
      max = novoMax;
  }
  dados[qtd++] = n; //colocar dado no vetor da primeira posicao
}

int VetorDinamico::qtdDados() {return qtd;}

int VetorDinamico::getDado(int i) {return dados[i];}



int main() {
  VetorDinamico V1(5);
  int dado;
  do {
    cin >> dado;
    if (dado>0)
       V1.adiciona(dado);
    else break;
  } while (1);
  for (int i=0; i< V1.qtdDados(); i++)
      cout << V1.getDado(i) << endl;
  return 0;
}