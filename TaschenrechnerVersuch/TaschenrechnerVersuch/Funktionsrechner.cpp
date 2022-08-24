#include "Funktionsrechner.h"
#include <iostream>
#include "Check.h"
#include <iomanip>
#include <math.h>
#include "Ladezeichen.h"
#include "InputOutput.h"

# define Pi           3.14159265358979323846; /* pi */

int fakt(int x) {
	if (x == 0)
		return 1;
	else
		return x * fakt(x - 1);
}
unsigned long int catalan(unsigned int n)
{
	if (n <= 1)
		return 1;
	unsigned long int res = 0;
	for (int i = 0; i < n; i++)
		res += catalan(i)
		* catalan(n - i - 1);
	return res;
}
float flache(int r){
	float A;
	return A = r * r * Pi;
}
int umfang(int r) {
	int U;
	return U = r * 2 * Pi;
}

void Funktionsrechner::FRBerechnen() {
	InputOutput io;
	int auswahl, zahlErg, zahl1, r, d, A, U;
	char kreisAuswahl, weiter='j';
	auswahl = io.askFROperation();
	switch (auswahl) {
	case 1:
		zahl1 = io.askNumberMax(15);
		cout << "Deine Zahl faktoriell ist: " << fakt(zahl1) << endl;
		break;
	case 2:
		zahl1 = io.askNumberMax(15);
		cout << "Deine Catalanzahl ist: " << catalan(zahl1) << endl;
		break;
	case 3:
		kreisAuswahl = io.askDR();
		switch (kreisAuswahl) {
		case 'D':
		case 'd':
			cout << "Durchmesser: ";
			cin >> d;
			r = d / 2;
			
			cout << "Deine Fäche ist: " << setprecision(2) << flache(r) << endl;
			cout << "Dein Umfang ist:" << umfang(r) << endl;
			break;
		case 'R':
		case 'r':
			cout << "Radius: ";
			cin >> r;
			A = flache(r);
			U = umfang(r);
			cout << "Deine Fäche ist: " << setprecision(2) << flache(r) << endl;
			cout << "Dein Umfang ist: " << umfang(r) << endl;
			break;
		}
		break;
	}
}
