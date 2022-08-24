#pragma once
#include "Triangle.h"
class EquilateralTriangle :
    public Triangle
{
private:
    double a, flaeche, umfang;
public:
    inline double getFlaeche() {
        return flaeche;
    }
    double getUmfang() {
        return umfang;
    }
    virtual std::string getType();
    virtual void berechneFlaeche();
    virtual void berechneUmfang();
    EquilateralTriangle(double _a) {
        a = _a;
        flaeche = 0;
        umfang = 0;
    }
    
};

