#include "GleichseitigesVieleck.h"
#include <math.h>
#include <iostream>
#include "InputOutput.h"
double cot(double a)
{
	return cos(a) / sin(a);
}
void GleichseitigesVieleck::berechneFlaecheninhalt() {
	Flaecheninhalt = (AnzahlEcken / 4) * cot(180 / AnzahlEcken) * Seite * Seite;
}
void GleichseitigesVieleck::berechneUmfang() {
	Umfang = AnzahlEcken * Seite;
}
void GleichseitigesVieleck::getTyp() {
	Typ = "Das ist ein "+AnzahlEcken+"-Eck";
}
void GleichseitigesVieleck::printThings() {
	std::cout << "Flaeche: " << Flaecheninhalt << std::endl;
	std::cout << "Umfang: " << Umfang << std::endl;
}
void GleichseitigesVieleck::gsVieleck() {
	InputOutput io;
	double ecken =io.askEcken();
	double seite = io.askSeite();
	GleichseitigesVieleck gVieleck(ecken, seite);
	gVieleck.berechneUmfang();
	gVieleck.berechneFlaecheninhalt();
	gVieleck.getTyp();
	gVieleck.printThings();
}