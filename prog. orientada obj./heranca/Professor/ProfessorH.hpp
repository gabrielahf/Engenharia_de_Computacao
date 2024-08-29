#ifndef _PROFESSORH_HPP
#define _PROFESSORH_HPP

#include "Professor.hpp"

class ProfessorH : public Professor {
    private:
        double salarioHora;
    public:
        ProfessorH(double sH);
        void defineSalarioHora(int sH);
        int obtemCargaHoraria();
        long obtemSalarioHora();
};

#endif
