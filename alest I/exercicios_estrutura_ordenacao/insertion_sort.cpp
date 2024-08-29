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

void insertionSort(int dados[], int tam) {
    for (int i = 1; i < tam; ++i) { // i analisa o elemento da frente
        int base = dados[i]; // base = elemento atual
        int j = i - 1; // j analisa o elemento anterior ao i (andar ao contrario)
        while (j >= 0 && base < dados[j]) { // analisar membros anteriores
            dados[j + 1] = dados[j]; // posiciona os elementos uma posicao para frente 
            --j;
        }
        dados[j + 1] = base; // introducao do elemento atual na posicao correta
        //imprimeDados(dados, TAM); imprime passo a passo
    }
}

int main() {
    int dados[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    insertionSort(dados, TAM);

    imprimeDados(dados, TAM);

    return 0;
}
