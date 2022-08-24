#include "Rectangle.h"


void Rectangle::berechneFlaeche() {
	flaeche = a * b;
}
void Rectangle::berechneUmfang() {
	umfang = (a + b) * 2;
}
std::string Rectangle::getType() {
	return "Rechteck";
}