#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprimeDados(int dados[]){
    int i;
    cout << "\n";
    for(i = 0; i < TAM; i++){
        cout << " |" << dados[i] << "| ";
    }
}

//junta os dois subarrays criados ao dividir o vetor principal
void merge(int *dados, int ini, int meio, int fim) {
  int p = ini, q = meio+1, k=0;
  int *aux = new int[fim-ini+1];
  for (int i = ini; i <= fim; i++){
      if (p > meio)                 aux[k++] = dados[q++];
      else if (q > fim)             aux[k++] = dados[p++];
      else if( dados[p] < dados[q]) aux[k++] = dados[p++];
      else                          aux[k++] = dados[q++];
  }
  for (int p=0; p<k; p++) dados[ini++] = aux[p];
  delete[] aux;
}

void mergeSort(int *dados, int ini, int fim) {
  if ( ini >= fim ) return;
  int meio = (ini + fim) / 2; // dividir os elementos e sub grupos
  mergeSort(dados, ini, meio); // inicio ao meio
  mergeSort(dados, meio+1, fim); // meio ao fim
  merge(dados, ini, meio, fim); // funcao que faz a ordenacao dos elementos, unindo os dois subarrays q/ foram criados
  //imprimeDados(dados);
}

int main(){

    int dados[TAM] = {10,9,8,7,6,5,4,3,2,1};

    mergeSort(dados, 0, TAM-1);

    imprimeDados(dados);

    return 0;
}
