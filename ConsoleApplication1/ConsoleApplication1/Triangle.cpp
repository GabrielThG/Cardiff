#include "Triangle.h"
#include "cmath"
void Triangle::berechneFlaeche() {
	double s = (a + b + c) / 2;
	flaeche = sqrt(s*(s-a)*(s-b)*(s-c));
}
void Triangle::berechneUmfang() {
	umfang = a + b + c;
}
std::string Triangle::getType() {
	return "Dreieck";
}
