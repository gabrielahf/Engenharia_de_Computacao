/*Implemente um programa que lê n palavras da entrada-padrão, e mais uma palavra-chave. 
Você deve localizar e imprimir as palavras que foram digitadas que possuem a palavra-chave como
substring.
a. Dica: o método ::find() retorna o valor específico string::npos se não encontrar nada
(use-o para teste!)*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Variáveis
    int n;
    cin >> n;

    // Lê as palavras da entrada-padrão
    vector<string> palavras;
    for (int i = 0; i < n; ++i) {
        string palavra;
        cout << i + 1 << ": ";
        cin >> palavra;
        palavras.push_back(palavra);
    }

    // Lê a palavra-chave
    string palavraChave;
    cin >> palavraChave;

    // Procura e imprime palavras que contêm a palavra-chave como substring
    cout  << palavraChave << endl;
    for (const string& palavra : palavras) {
        // Verifica se a palavra-chave é uma substring da palavra atual
        if (palavra.find(palavraChave) != string::npos) {
            cout << palavra << endl;
        }
    }

    return 0;
}


