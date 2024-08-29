// Ponto.cpp
#include <sstream>
#include <cmath>
#include "Ponto.hpp"

Ponto::Ponto(double x, double y) {
this->x = x; this->y = y;
}

void Ponto::defineX(double x) { this->x = x; }
void Ponto::defineY(double y) { this->y = y; }
double Ponto::obtemX() { return x; }
double Ponto::obtemY() { return y; }
string Ponto::toString() {
    stringstream ss;
    ss << "(" << x << "," << y << ")";
    return ss.str();
}
double distancia(Ponto& p1, Ponto& p2) {
    double dx = p1.obtemX() - p2.obtemX();
    double dy = p1.obtemY() - p2.obtemY();
    return sqrt(dx*dx + dy*dy);
}