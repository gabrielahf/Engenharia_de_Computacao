/*Escreva um programa que recebe de entrada nomes e telefones correspondentes.
    a. A entrada deve ser n nomes e n telefones 
        i. Defina uma classe e seus métodos para armazenamento de tais informações.
    b. Na saída, imprima a lista [<nome> <telefone>] ordenada pelos nomes
        i. Crie uma função para comparação.
        ii. Explore o algoritmo sort de STL.
        iii. Veja exemplo em: http://www.inf.pucrs.br/~pinho/PRGSWB/STL/stl.html
    c. Após isso, o programa deve ler um nome da entrada padrão e imprimir seu telefone
    correspondente, se este existir. Se não existir, imprima uma mensagem apropriada*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Info {
private:
    string nome;
    string telefone;

public:
    // Construtor
    Info(string n = "", string t = "") : nome(n), telefone(t) {}

    // Métodos de acesso
    string getNome() const { return nome; }
    string getTelefone() const { return telefone; }

    // Função de comparação para ordenação
    static bool comparacao(const Info &a, const Info &b) {
        return a.nome < b.nome;
    }

    // Sobrecarga do operador de saída para facilitar a impressão
    friend ostream &operator<<(ostream &out, const Info &info) {
        out << "[" << info.nome << " " << info.telefone << "]";
        return out;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Info> lista;

    for (int i = 0; i < n; ++i) {
        string nome, telefone;
        cin >> nome;
        cin >> telefone;
        lista.push_back(Info(nome, telefone));
    }

    // Ordena a lista usando a função de comparação
    sort(lista.begin(), lista.end(), Info::comparacao);

    // Imprime a lista ordenada
    for (const auto &info : lista) {
        cout << info << " ";
    }
    cout << "\n";

    // Busca por nome
    string buscaNome;
    cin >> buscaNome;

    // Procura o nome na lista ordenada usando busca binária
    auto it = lower_bound(lista.begin(), lista.end(), Info(buscaNome), Info::comparacao);

    // Verifica se o nome foi encontrado
    if (it != lista.end() && it->getNome() == buscaNome) {
        cout << "Telefone correspondente: " << it->getTelefone() << "\n";
    } else {
        cout << "Nome não encontrado.\n";
    }

    return 0;
}
