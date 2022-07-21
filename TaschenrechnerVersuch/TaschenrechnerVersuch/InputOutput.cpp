#include "InputOutput.h"
#include <iostream>
#include <iomanip>
#include "Ladezeichen.h"
#include <math.h>
#include <limits>
#include <stdio.h>   
#include <stdlib.h> 
#include <string> 
#include <vector>
#include <fstream>
#include "Filerechner.h"
using std::cout; using std::cerr;
using std::cin;
using std::endl; using std::string;
using std::ifstream;

bool checkCharTFN(char x) {
	if (x == 'T' || 't' || 'F' || 'f' || 'N' || 'n')
		return true;
	else
		return false;
}
bool checkCharDR(char x) {
	if (x == 'D' || 'd' || 'R' || 'r')
		return true;
	else
		return false;
}
char InputOutput::askMain() {
	char auswahl;
	cout << "Wollen Sie Taschenrechner oder Funktionsrechner (T/F) starten?" << endl;;
	cin >> auswahl;
	if (checkCharTFN(auswahl))
		return auswahl;
	else
		return 'n';
	return auswahl;
};
int InputOutput::askNumberMax(int begrenzung) {
	bool weiter = true;
	int zahl = 0;
	string wort = "0";
	while (weiter == 'j') {
		cout << "Bitte geben Sie eine Zahl ein (bis max"<< begrenzung <<"):" << endl;
		cin >> wort;
		if (is_number(wort)) {
			zahl = stoi(wort);
			if (zahl == 0 || zahl>begrenzung)
			{
				cout << "Bitte geben Sie eine gültige Zahl ein: " << endl;
				break;
			}
			weiter = false;
			return zahl;
		}
		else {
			cin.clear();
			weiter = true;
		}
	}
}
int InputOutput::askNumber() {
	bool weiter = true;
	int zahl = 0;
	string wort = "0";
	while (weiter == true) {
		cout << "Bitte geben Sie eine Zahl ein:" << endl;
		cin >> wort;
		if (is_number(wort)) {
			zahl = stoi(wort);
			if (zahl == 0)
			{
				cout << "Bitte geben Sie eine gültige Zahl ein: " << endl;
				break;
			}
			weiter = false;
			return zahl;
		}
		else {
			cin.clear();
			weiter = true;
		}
	}
}
int InputOutput::askTROperation() {
	bool weiter =true;
	int zahlOperator;
	string wort;
	while (weiter == true) {
		cout << "Welche Rechenoperation soll durchgefuehrt werden?" << endl;
		cout << "(1-Addieren, 2-Subtrahieren, 3-Multiplizieren, 4-Dividieren," << endl;
		cout << " 5-Modulo, 6-Potenzieren, 7-Wurzelziehen)" << endl;
		cin >> wort;
		try {
			zahlOperator = stoi(wort);
			if (zahlOperator < 8 || zahlOperator != 0) {
				return zahlOperator;
				weiter = false;
			}
			else
			{
				cin.clear();
				weiter = true;
			}
		}
		catch (const std::exception& e)
		{
			cout << "Bitte geben Sie eine gueltige Zahl ein!" << endl;
			cerr << e.what() << endl;
		}
	}
}
void InputOutput::printError() {
	cout << "Bitte eine gültige Zahl eingeben." << endl;;

}
void InputOutput::printErgebnis(float x) {
	cout << "Dein Ergebnis ist: " << std::setprecision(2) << x << endl;
}
int InputOutput::askFROperation() {
	bool weiter = true;
	int zahlOperator;
	string wort;
	ladenrechner(1, "Funktionsrechner startet ");
	while (weiter == true) {
		cout << "Welche Funktion soll durchgfuehrt?";
		cout << "1-Faktoriell, 2-Catalan, 3-Kreisberechnung, " << endl;
		cin >> wort;
		try {
			zahlOperator = stoi(wort);
			if (zahlOperator < 8 || zahlOperator != 0) {
				return zahlOperator;
				weiter = false;
			}
			else
			{
				cin.clear();
				weiter = true;
			}
		}
		catch (const std::exception& e)
		{
			cout << "Bitte geben Sie eine gueltige Zahl ein!" << endl;
			cerr << e.what() << endl;
		}
	}
}
void InputOutput::printFileError() {
	std::cout << "Bitte an erster Stelle des Files einen Operator eingeben!";
}
char InputOutput::askAgain() {
	char weiter;
	cout << "Wollen Sie nocheinmal zu Taschenrechner/Funktionsrechner? (T/F/N)" << endl;
	cin >> weiter;
	if (checkCharTFN(weiter))
		return weiter;
	else
		return 'n';
}
char InputOutput::askDR() {
	char kreisAuswahl;
	bool weiter = true;
	while (weiter == true) { 
	cout << "Durchmesser oder Radius? (D/R)" << endl;
	cin >> kreisAuswahl;
	if (checkCharDR(kreisAuswahl)) {
		return kreisAuswahl;
		weiter = false;
	}
	else{
		cin.clear();
		cout << "Bitte D, d, R oder r eingeben." << endl;
		weiter = true;
		}
	}
}
char askMethode() {
	char auswahl ='n';
	cout << "Über das Terminal oder File einlesen? (T/F)" << endl;
	cin >> auswahl;
	if (checkCharTFN(auswahl)) {
		return auswahl;
	}
	else {
		return 'n';
	}
}



	
