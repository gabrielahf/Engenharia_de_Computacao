// Ponto.hpp
#ifndef _PONTO_HPP
#define _PONTO_HPP
#include <string>

using namespace std;

class Ponto {
    private:
        
    public:
        Ponto(double x=0.0, double y=0.0);
        void defineX(double x);
        void defineY(double y);
        double obtemX();
        double obtemY();
        string toString();
};

double distancia(Ponto& p1, Ponto& p2);
#endif