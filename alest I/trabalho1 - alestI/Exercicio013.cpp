#include <iostream>
#include <string>
using namespace std;

struct Registro {
    string identificador;
    int numeroLinha;
};

void selectionSort(Registro* dados, int tam) {
    for (int i = 0; i < tam - 1; ++i) {
        int men = i;
        for (int j = i + 1; j < tam; ++j) {
            if (dados[j].identificador < dados[men].identificador ||
                (dados[j].identificador == dados[men].identificador && dados[j].numeroLinha < dados[men].numeroLinha)) {
                men = j;
            }
        }
        if (men != i) {
            swap(dados[men], dados[i]);
        }

       
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

    selectionSort(registros, N);

    delete[] registros;

    return 0;
}
