#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class UnidadeFederativa { 
private:
    string nome;
    string sigla;
    string capital;
    double area;
    int populacao;

public:
    UnidadeFederativa() : nome(""), sigla(""), capital(""), area(0), populacao(0) {}

    UnidadeFederativa(string _nome, string _sigla, string _capital, double _area, int _populacao)
        : nome(_nome), sigla(_sigla), capital(_capital), area(_area), populacao(_populacao) {}

    string obtemNome() {
        return nome;
    }
    void defineNome(string _nome) {
        nome = _nome;
    }

    string obtemSigla() {
        return sigla;
    }
    void defineSigla(string _sigla) {
        sigla = _sigla;
    }

    string obtemCapital() {
        return capital;
    }
    void defineCapital(string _capital) {
        capital = _capital;
    }

    double obtemArea() {
        return area;
    }
    void defineArea(double _area) {
        area = _area;
    }

    int obtemPopulacao() {
        return populacao;
    }
    void definePopulacao(int _populacao) {
        populacao = _populacao;
    }

    double obtemDensidade() {
        if (area != 0) {
            return populacao / area;
        }
        return 0.0;
    }
};

void mostraUF(UnidadeFederativa &uf) {
    cout << uf.obtemNome() << " (" << uf.obtemSigla() << ") - " << uf.obtemCapital();
    cout << " - Area = " << fixed << setprecision(4) << uf.obtemArea();
    cout << " - Pop. = " << uf.obtemPopulacao();
    cout << " - Densidade = " << fixed << setprecision(4) << uf.obtemDensidade() << endl;
}

int main() {
    UnidadeFederativa rs;
    mostraUF(rs);

    rs.defineNome("Rio Grande do Sul");
    rs.defineSigla("RS");
    rs.defineCapital("Porto Alegre");
    rs.defineArea(281748.5);
    rs.definePopulacao(11228091);
    mostraUF(rs);

    UnidadeFederativa sc("Santa Catarina", "SC", "Florianopolis", 95346.2, 6734568);
    mostraUF(sc);

    for (int i = 0; i < 10; ++i) {
        sc.definePopulacao(sc.obtemPopulacao() + 100000);
        mostraUF(sc);
    }

    return 0;
}
