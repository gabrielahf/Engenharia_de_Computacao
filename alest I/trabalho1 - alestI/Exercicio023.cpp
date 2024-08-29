#include <iostream>
#include <string>

using namespace std;

struct Registro {
    string identificador;
    int numeroLinha;
};

void insertionSort(Registro *dados, int tam) {
    for (int i = 1; i < tam; ++i) {
        Registro base = dados[i];
        int j = i - 1;
        while (j >= 0 && (base.identificador < dados[j].identificador ||
               (base.identificador == dados[j].identificador && base.numeroLinha < dados[j].numeroLinha))) {
            
            dados[j + 1] = dados[j];
            --j;
        }
        
        dados[j + 1] = base;
        
        for (int k = 0; k < tam; ++k) {
            cout << dados[k].identificador << "/" << dados[k].numeroLinha;
            if (k != tam - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    Registro* registros = new Registro[N];

    for (int i = 0; i < N; ++i) {
        cin >> registros[i].identificador >> registros[i].numeroLinha;
    }

    insertionSort(registros, N);

    delete[] registros;

    return 0;
}
