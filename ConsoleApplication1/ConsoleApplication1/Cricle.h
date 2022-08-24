#pragma once
#include "Shape.h"
class Cricle :
    public Shape
{
private:
    double r;
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
    Cricle(double _r) {
        r = _r;
    }
};