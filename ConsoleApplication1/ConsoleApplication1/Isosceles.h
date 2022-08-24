#pragma once
#include "Triangle.h"
class Isosceles :
    public Triangle
{
private:
    double a, b, c, hc, flaeche, umfang;
public:
    double getFlaeche() {
        return flaeche;
    }
    double getUmfang() {
        return umfang;
    }
    virtual std::string getType();
    virtual void berechneFlaeche();
    virtual void berechneUmfang();
    Isosceles(double _c, double _hc) {
        c = _c;
        hc = _hc;
        a = 0;
        b = 0;
        flaeche = 0;
        umfang = 0;
    }

};

