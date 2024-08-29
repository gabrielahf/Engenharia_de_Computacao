#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

#define TAM 10

void imprimeDados(int dados[], int tam) {
    int i;
    cout << "\n";
    for(i = 0; i < tam; i++) {
        cout << " |" << dados[i] << "| ";
    }
}

void bubbleSort(int *dados, int tam) {
  int trocou;
  do {
     trocou = 0;
     --tam;
     for (int i=0; i<tam; ++i) {
        //imprimeDados(dados,TAM);
         if (dados[i] > dados[i+1]) {
            int aux = dados[i];
            dados[i] = dados[i+1];
            dados[i+1] = aux;
            trocou = 1;
         }
     }
  }  while (trocou);
}


int main() {
    int dados[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    bubbleSort(dados, TAM);

    imprimeDados(dados, TAM);

    return 0;
}
