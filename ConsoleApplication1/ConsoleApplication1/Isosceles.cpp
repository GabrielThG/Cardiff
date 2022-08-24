#include "Isosceles.h"
#include <math.h>
void Isosceles::berechneFlaeche() {
	flaeche = (c * hc) / 2;
}
void Isosceles::berechneUmfang() {
	a = sqrt((c / 2) * (c / 2) + (hc * hc));
	umfang = 2 * a + c;
}
std::string Isosceles::getType() {
	return "gleichschenkeliges Dreieck";
}