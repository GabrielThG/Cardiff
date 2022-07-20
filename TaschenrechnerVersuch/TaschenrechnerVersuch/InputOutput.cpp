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
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream;

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}
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
	cout << "Wollen Sie Taschenrechner oder Funktionsrechner (T/F) starten?" << std::endl;;
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
	std::string wort = "0";
	while (weiter == 'j') {
		cout << "Bitte geben Sie eine Zahl ein (bis max"<< begrenzung <<"):" << std::endl;
		cin >> wort;
		if (is_number(wort)) {
			zahl = stoi(wort);
			if (zahl == 0 || zahl>begrenzung)
			{
				cout << "Bitte geben Sie eine gültige Zahl ein: " << std::endl;
				break;
			}
			weiter = false;
			return zahl;
		}
		else {
			std::cin.clear();
			weiter = true;
		}
	}
}
int InputOutput::askNumber() {
	bool weiter = true;
	int zahl = 0;
	std::string wort = "0";
	while (weiter == 'j') {
		cout << "Bitte geben Sie eine Zahl ein:" << std::endl;
		cin >> wort;
		if (is_number(wort)) {
			zahl = stoi(wort);
			if (zahl == 0)
			{
				cout << "Bitte geben Sie eine gültige Zahl ein: " << std::endl;
				break;
			}
			weiter = false;
			return zahl;
		}
		else {
			std::cin.clear();
			weiter =true;
		}
	}
}
int InputOutput::askTROperation() {
	bool weiter =true;
	int zahlOperator;
	string wort;
	while (weiter == true) {
		cout << "Welche Rechenoperation soll durchgefuehrt werden? \n";
		cout << "(1-Addieren, 2-Subtrahieren, 3-Multiplizieren, 4-Dividieren,\n";
		cout << " 5-Modulo, 6-Potenzieren, 7-Wurzelziehen)";
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
			cout << "Bitte geben Sie eine gueltige Zahl ein!" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
}
void InputOutput::printError() {
	cout << "Bitte eine gültige Zahl eingeben." << std::endl;;

}
void InputOutput::printErgebnis(float x) {
	std::cout << "Dein Ergebnis ist: " << std::setprecision(2) << x << std::endl;
}
int InputOutput::askFROperation() {
	bool weiter = true;
	int zahlOperator;
	std::string wort;
	ladenrechner(1, "Funktionsrechner startet ");
	while (weiter == true) {
		cout << "Welche Funktion soll durchgfuehrt?";
		cout << "1-Faktoriell, 2-Catalan, 3-Kreisberechnung, ";
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
			cout << "Bitte geben Sie eine gueltige Zahl ein!" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
}
char InputOutput::askAgain() {
	char weiter;
	cout << "Wollen Sie nocheinmal zu Taschenrechner/Funktionsrechner? (T/F/N)";
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
	cout << "Durchmesser oder Radius? (D/R)";
	cin >> kreisAuswahl;
	if (checkCharDR(kreisAuswahl)) {
		return kreisAuswahl;
		weiter = false;
	}
	else{
		cin.clear();
		cout << "Bitte D, d, R oder r eingeben.";
		weiter = true;
		}
	}
}
char askAdd() {
	char auswahl;
	cout << "Über das Terminal oder File einlesen? (T/F)";
	cin >> auswahl;
	if (checkCharTFN(auswahl)) {
		return auswahl;
	}
	else {
		return 'n';
	}
}
//vector<int> InputOutput::makeVectorT() {
//	vector<int> vec;
//	int zahl;
//	char weiter = 'j';
//	cout << "Geben Sie eine Zahl ein: ";
//	cin >> zahl;
//	while (weiter == 'j') {
//		string wort;
//		int zahl1;
//		cout << "Geben Sie eine weitere Zahl ein(#/n): ";
//		cin >> wort;
//		if (is_number(wort)) {
//			zahl1 = stoi(wort);
//			weiter = 'j';
//		}
//		else {
//			weiter = 'j';
//			break;
//		}
//		vec.push_back(zahl1);
//	}
//	return vec;
//}
//vector<int> InputOutput::makeVectorF() {
//	vector<int> vec;
//	string filename("input.txt");
//	int number;
//	ifstream input_file(filename);
//	if (!input_file.is_open()) {
//		cerr << "Could not open the file - '" << filename << "'" << endl;
//		return vec;
//	}
//	while (input_file >> number) {
//		vec.push_back(number);
//	}
//	cout << endl;
//	input_file.close();
//	return vec;
//}


	
