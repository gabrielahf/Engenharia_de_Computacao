/*Escreva um programa explorando STL que declara um vetor de inteiros. Armazene no
vetor os 5 valores informados e então imprima o vetor de elementos com o comando
cout.*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> vetor; //cria o vetor
    int valor;
    for (int i = 0; i < 5; i++) // armazena os 5 valores informados
    {
         cin >> valor;
         vetor.push_back(valor);
    }
    
    for (int i = 0; i < vetor.size(); i++) // imprime o vetor de elementos
    {
        cout << vetor[i];
        
    }
    
}