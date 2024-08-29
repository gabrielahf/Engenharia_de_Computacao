#include <iostream>

using namespace std;

class Pessoa { 

    private:
        string nome;
        int anoNascimento;

    public:

    Pessoa() : nome(""), anoNascimento(0) {

    }

    Pessoa(string _nome, int _anoNascimento) : nome(_nome), anoNascimento(_anoNascimento) {

    }

    void defineNome (string _nome) {
        nome = _nome;
    }

    string obtemNome () {
        return nome;
    }

    void defineAnoNascimento (int _anoNascimento) {
        anoNascimento = _anoNascimento;
    }

    int obtemAnoNascimento () {
        return anoNascimento;
    }

    int obtemIdade (int Ano_atual) {
        if (Ano_atual < anoNascimento)
        {
            return -1;
        }
      return Ano_atual - anoNascimento;  
    } 

    int obtemIdadeEmMeses (int Ano_atual) {
        if (Ano_atual < anoNascimento)
        {
            return -1;
        }
      return (Ano_atual - anoNascimento) * 12;
    }

};


int main() 
{
    Pessoa *p = new Pessoa();

    cout << "[" << p->obtemNome() << "](" << p->obtemAnoNascimento() << ")" << endl;

    p->defineNome("Friedrich Wilhelm Nietzsche");
    p->defineAnoNascimento(1844);

    cout << "[" << p->obtemNome() << "](" <<
    p->obtemAnoNascimento() << "/" <<
    p->obtemIdade(1900) << " anos/" <<
    p->obtemIdadeEmMeses(1900) << " meses)" << endl;

    delete p;

    Pessoa *rn = new Pessoa("Fulano",2020);
    cout << "Nome = " << rn-> obtemNome() << endl;
    cout << "Ano de Nascimento = " << rn->obtemAnoNascimento() << endl;

    for (int i=2018; i<2025; ++i) 
        cout << i << " " << rn->obtemIdade(i) << " " << rn->obtemIdadeEmMeses(i) << endl;
        delete rn;

    return 0;
}