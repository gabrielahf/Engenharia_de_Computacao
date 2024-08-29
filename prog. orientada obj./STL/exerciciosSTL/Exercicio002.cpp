/*Escreva um programa que explora STL, o qual captura uma sequência arbitrária de
dígitos binários com cin e armazena em um container. Enquanto o valor recebido é
diferente de 1 ou 0. Considere que o primeiro valor inserido é o bit menos
significativos. Ao final, apresente a representação binária informada e o valor decimal
sem sinal desta representação binária.*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vetor;
    int valor;

    while (cin >> valor && (valor != 0 || valor != 1)) { // verifica se o valor recebido é diferente de 1 e 0
        vetor.push_back(valor); //armazenar a sequencia em um container
    }

    int decimal = 0;
    int potencia = 1;

    for (int i = vetor.size() - 1; i >= 0; i--) {
        decimal += vetor[i] * potencia; //calcular o valor binario para decimal
        potencia *= 2;
    }

   
    for (int j = vetor.size() - 1; j >= 0; j--) { // impressão
        cout << vetor[j];
    }
    
    cout << decimal << endl;

    return 0;
}
