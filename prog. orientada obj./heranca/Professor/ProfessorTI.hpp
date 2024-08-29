#ifndef _PROFESSORTI_HPP
#define _PROFESSORTI_HPP

#include "Professor.hpp"

class ProfessorTI : public Professor {
    private:
        double salarioHora;
    public:
        ProfessorTI(double sH);
        void defineSalarioHora(int sH);
        int obtemCargaHoraria();
        long obtemSalarioHora();
};

#endif
