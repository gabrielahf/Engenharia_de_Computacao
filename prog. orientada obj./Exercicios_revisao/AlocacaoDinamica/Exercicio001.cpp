#include <iostream>

using namespace std;

class VetorDinamico {
private:
    int tamanho;
    int* vetor; // Pointer to dynamically allocated array
    int qtdDados;

public:
    VetorDinamico(int tam) : tamanho(tam), vetor(new int[tam]), qtdDados(0) {}

    ~VetorDinamico() {
        delete[] vetor; // Destructor to release dynamically allocated memory
    }

    void adiciona(int dado) {
        if (qtdDados < tamanho) {
            vetor[qtdDados] = dado;
            qtdDados++;
        } else {
            cout << "Vector is full." << endl;
        }
    }

    int getQtdDados() {
        return qtdDados;
    }

    int getDado(int i) {
        if (i >= 0 && i < qtdDados) {
            return vetor[i];
        } else {
            cout << "Index out of bounds!" << endl;
            return -1; // You can modify this part based on your error handling requirements
        }
    }
};

int main() {
    VetorDinamico V1(5);
    int dado;

    do {
        cin >> dado;
        if (dado > 0)
            V1.adiciona(dado);
        else
            break;
    } while (1);

    for (int i = 0; i < V1.getQtdDados(); i++)
        cout << V1.getDado(i) << endl;

    return 0;
}
