#ifdef TURMA_HPP
#define TURMA_HPP

#include <vector>
#include <string>

using namespace std;

class Turma {
    private:
        string codigo;
        int creditos;
        string nome;
        string turma;
        vector <int> diaSemana;
        vector <string> horario;
    
    public:
        Turma(string c, int cr, string n, string t);
        void adicionaEncontro(int ds, string h);
        string obtemCodigo() const;
        int obtemCreditos()const;
        string obtemNome()const;
        string obtemTurma()const;
        string str()const;
        bool operator == (Turma &t) const;
        bool operator < (Turma &t) const;
};