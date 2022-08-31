#pragma once
#include <string>
class GleichseitigesVieleck
{
private:
	double AnzahlEcken;
	double Radius;
	double Seite;
	double Flaecheninhalt;
	double Umfang;
	std::string Typ;
	void berechneFlaecheninhalt();
	void berechneUmfang();
	void getTyp();
	void printThings();
public:
	void gsVieleck();
	GleichseitigesVieleck() {

	}
	GleichseitigesVieleck(double anz, double seiten) {
		AnzahlEcken = anz;
		Seite = seiten;
	}
};