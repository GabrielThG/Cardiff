#include "Cricle.h"
#define _USE_MATH_DEFINES
#include <math.h>

void Cricle::berechneFlaeche() {
	flaeche = r * r * M_PI;
}
void Cricle::berechneUmfang() {
	umfang = 2 * r * M_PI;
}
std::string Cricle::getType() {
	return "Kreis";
}
//std::ostream& operator<< (std::ostream& out, Cricle* shape)
//{
//	// Since operator<< is a friend of the Point class, we can access Point's members directly.
//	out << "Es ist ein " << shape->getType() << ".\n" << "Die Fläche ist: " << shape->getFlaeche() << "\nDer Umfang " << shape->getUmfang() << std::endl; // actual output done here
//
//	return out; // return std::ostream so we can chain calls to operator<<
//}
