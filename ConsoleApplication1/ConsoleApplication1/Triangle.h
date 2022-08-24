#pragma once
#include "Shape.h"
class Triangle :
    public Shape
{
private:
    double a;
    double b;
    double c;
    double hc;
    double flaeche = 0;
    double umfang = 0;
public:
    double getFlaeche() {
        return flaeche;
    };
    double getUmfang() {
        return umfang;
    };
    virtual std::string getType();
    virtual void berechneFlaeche();
    virtual void berechneUmfang();
    Triangle() { a = 0; b = 0; c = 0; hc = 0; }
    Triangle(double d1, double d2, double d3)
    {
        a = d1;
        b = d2;
        c = d3;
        hc = 0;
    }
};