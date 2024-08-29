#ifndef _PROFESSOR_HPP
#define _PROFESSOR_HPP

#include <string>

class Professor {
    private:
        string nome;
        long matricula;
        int cargaHoraria;
        
    public:
        Professor(string n, long m, int cH);
        void defineNome(string n);
        void defineMatricula(long m);
        void defineCargaHoraria(int cH);
        int obtemCargaHoraria();
        string obtemNome();
        long obtemMatricula();

};

#endif