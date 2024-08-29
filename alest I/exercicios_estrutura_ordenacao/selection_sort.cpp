#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprimeDados(int dados[], int tam){
    int i;
    cout << "\n";
    for(i = 0; i < tam; i++){
        cout << " |" << dados[i] << "| ";
    }
}

void selectionSort(int dados[], int tam) {
  for (int i=0; i<tam-1; ++i) { // percorre todos os elementos
      int men = i; // recebe a posicao inicial para o menor valor
      for (int j=i+1; j<tam; ++j) // percorre o espaço sobrando, com uma posicao a frente 
          if ( dados[j] < dados[men] ) men = j; // caso encontre um valor menor na frente dos elementos analisados
      if ( men != i ) {  // se encontrou, verificar se precisa realizar troca dos elementos
         int aux = dados[men];
         dados[men] = dados[i];
         dados[i] = aux;
      }
        imprimeDados(dados, TAM);
  }
}


int main(){

    int dados[TAM] = {10,9,8,7,6,5,4,3,2,1};

    selectionSort(dados, TAM);

    imprimeDados(dados, TAM);

    return 0;
}