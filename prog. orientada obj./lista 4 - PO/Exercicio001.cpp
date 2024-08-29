#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>

using namespace std;

#define MAX_ALUNOS 10

class Aluno {
private:
    int Matricula;
    string Nome;
    double Nota;

public:
    Aluno() : Matricula(0), Nome(""), Nota(-1.0) {}

    Aluno(int num_matricula, string nome, double nota) : Matricula(num_matricula), Nome(nome), Nota(nota) {}

    int obtemMatricula() { return Matricula; }

    string obtemNome() { return Nome; }

    double obtemNota() { return Nota; }

    void defineMatricula(int num_matricula) { Matricula = num_matricula; }

    void defineNome(string nome) { Nome = nome; }

    void defineNota(double nota) { Nota = nota; }

    string str() 
    {
        stringstream ss;
        ss << Nome << " (" << setfill('0') << setw(10) << Matricula << ")";
        
        if (Nota != -1.0) {ss << ": " << fixed << setprecision(4) << Nota;}
    
        return ss.str();
    }

};

class Turma {
private:
    int NumTurma;
    string Disciplina;
    string Professor;
    Aluno* alunos[MAX_ALUNOS];
    int numAlunos;

public:
    Turma() : NumTurma(0), Disciplina(""), Professor(""), numAlunos(0) {
        for (int i = 0; i < MAX_ALUNOS; ++i) {
            alunos[i] = nullptr;
        }
    }

    Turma(int num_turma, string disciplina, string professor) : NumTurma(num_turma), Disciplina(disciplina), Professor(professor), numAlunos(0) {
        for (int i = 0; i < MAX_ALUNOS; ++i) {
            alunos[i] = nullptr;
        }
    }

    int obtemNumero() { return NumTurma; }

    string obtemDisciplina() { return Disciplina; }

    string obtemProfessor() { return Professor; }

    Aluno* obtemAluno(int i) {
        if (i >= 0 && i < numAlunos) {
            return alunos[i];
        }
        return nullptr;
    }

    int obtemNumAlunos() { return numAlunos; }

    void defineNumero(int num_turma) { NumTurma = num_turma; }

    void defineDisciplina(string disciplina) { Disciplina = disciplina; }

    void defineProfessor(string professor) { Professor = professor; }

    bool adicionaAluno(Aluno* aluno) {
        if (numAlunos < MAX_ALUNOS) {
            alunos[numAlunos] = aluno;
            numAlunos++;
            return true;
        }
        return false;
    }

    double calculaMedia() {
    if (numAlunos == 0) {
        return -1.0;
    }
    double soma = 0.0;
    int NotasValidas = 0;  
    for (int i = 0; i < numAlunos; ++i) {
        if (alunos[i]->obtemNota() != -1.0) {
            soma += alunos[i]->obtemNota();
            NotasValidas++;
        }
    }
    if (NotasValidas == 0) {
        return -1.0;
    }
    return soma / NotasValidas;
}


    string str() {
    ostringstream ss;
    ss << NumTurma << " - " << Disciplina << " - Prof. " << Professor << endl;
    for (int i = 0; i < numAlunos; ++i) {
        ss << alunos[i]->str() << endl;
    }
    double media = calculaMedia();
    if (numAlunos > 0) {
        ss << "MEDIA = " << setprecision(4) << fixed << media;
    }
    return ss.str();
}

};
int main() {
    Aluno* discente[] = {
        new Aluno(1, "Benedito", 9.1),
        new Aluno(2, "Carlos", 8.2),
        new Aluno(3, "Daniela", 7.3),
        new Aluno(4, "Elisabeth", 6.4),
        new Aluno(5, "Fernanda", 5.5),
        new Aluno(6, "Gilson", 9.6),
        new Aluno(7, "Heitor", 8.5),
        new Aluno(8, "Irineu", 7.4),
        new Aluno(9, "Joana", 3.2),
        new Aluno(10, "Klaus", -1.0),
        new Aluno(11, "Laura", 9.8)
    };
    int numDiscentes = sizeof(discente) / sizeof(Aluno*);
    Turma* turma = new Turma(0, "SEM ALUNOS", "INDEFINIDO");
    int a;
    cout << turma->str() << endl;
    turma->defineNumero(123);
    turma->defineDisciplina("Linguagem C");
    turma->defineProfessor("Alberto");
    for (a = 0; a < 5; ++a)
        if (!turma->adicionaAluno(discente[a])) { cerr << "ERRO"; exit(1); }
    for (a = 0; a < 5; ++a)
        if (turma->obtemAluno(a) != discente[a]) { cerr << "ERRO"; exit(1); }
    for (; a < numDiscentes; ++a)
        if (turma->obtemAluno(a) != nullptr) { cerr << "ERRO"; exit(1); }
    cout << turma->str() << endl;
    for (a = 5; a < MAX_ALUNOS; ++a)
        if (!turma->adicionaAluno(discente[a])) { cerr << "ERRO"; exit(1); }
    for (; a < numDiscentes; ++a)
        if (turma->adicionaAluno(discente[a])) { cerr << "ERRO"; exit(1); }
    for (a = 0; a < MAX_ALUNOS; ++a)
        if (turma->obtemAluno(a) != discente[a]) { cerr << "ERRO"; exit(1); }
    cout << turma->str() << endl;
    delete turma;
    for (int i = 0; i < numDiscentes; ++i)
        delete discente[i];
    return 0;
}
