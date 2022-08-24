#include "EquilateralTriangle.h"
#include <math.h>
void EquilateralTriangle::berechneFlaeche() {
	flaeche = (sqrt(3) / 4) * (a * a);
}
void EquilateralTriangle::berechneUmfang() {
	umfang = 3 * a;
}
std::string EquilateralTriangle::getType() {
	return "gleichseitiges Dreieck";
}