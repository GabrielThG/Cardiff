#pragma once
#include "Shape.h"
class Rectangle :
    public Shape
{
private:
    double a;
    double b;
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
    Rectangle() {
        a = 0;
        b = 0;
    }
    Rectangle(double _a, double _b) {
        a = _a;
        b = _b;
    }
};

